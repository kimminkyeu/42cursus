

#include <stdio.h>


#include <stdarg.h>
#include <unistd.h>

/* NOTE : Project Goal
 *
 * (1) 읽기 쉽고 빠른 코드를 작성한다.
 *
 * (2) 유지보수가 쉽도록 설계한다. -> 룩업테이블을 쓴 이유.
 *		강의 : https://www.youtube.com/watch?v=JPPxV3Hdz_A
 *
 * (3) if else 문을 최소화 한다.
 *
 * (4) state machine 구조를 사용한다. 
 *
 * */


/* TODO : change directory  */
/** #include "../libft/libft.h"  */

/* NOTE : state machine */

#define PRINTF_STATE_NORMAL (0)
#define PRINTF_STATE_END (2)

/** typedef enum e_state { */
/**     PRINTF_STATE_NORMAL */
/**     // ... */
/** } t_state; */

void	test0(int *state_ptr, const char* format, va_list ap)
{
	*state_ptr = 1;
	printf("ap in test0 : %d\n", va_arg(ap, int));
	printf("goto test%d\n", *state_ptr);
	format += 0;
}

void	test1(int *state_ptr, const char* format, va_list ap)
{
	*state_ptr = 2;
	printf("ap in test 1 : %d\n", va_arg(ap, int));
	printf("goto test%d\n", *state_ptr);
	format += 0;
}

int	ft_vprintf(int fd, const char *format, va_list ap)
{
//	int		*argp;
	int		state;
	void	(*func_table[10])(int *state, const char* format, va_list ap);

/* NOTE : why use int? */
/* TODO : 함수 포인터를 가지고 테이블을 만들면, state에 따라서 자동 함수 호출이 되게 가능하지 않을까?  */
/* TODO : 어떤 함수가 return을 해주면, 그 리턴값으로 함수 포인터를 자동 호출되게 할 수 없나?  */
/* TODO : Look-up table에 대해 공부하자. 그리고 응용하자.  */

	state = PRINTF_STATE_NORMAL;
//	argp = (int *)format; 
//
	(void)ap;

	// FIXME : 이렇게 2차원 포인터 초기화해도 되나?
	func_table[0] = test0;
	func_table[1] = test1;
	
	while (*format != '\0' && state != PRINTF_STATE_END)
	{
		// test : 이렇게 하면 함수 포인터를 통해 거친 후 state이 바뀔까?
		(func_table[state])(&state, format, ap);
		++format;
	}
	write(fd, "state:", 6);
	printf("%d\n", state);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		done;

	va_start(ap, format);
	done = ft_vprintf(STDOUT_FILENO, format, ap);
	va_end(ap);
	return (done);
}


int main(void)
{
	ft_printf("test", 42, 24);
	return 0;
}
