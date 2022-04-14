/* NOTE : header for va_list  */
#include <stdarg.h>

/* NOTE  : https://docs.microsoft.com/ko-kr/cpp/c-runtime-library/reference/va-arg-va-copy-va-end-va-start?view=msvc-170
 *
 * [ MACRO FUNCTIONS LIST ]
 *
 * va_list : list structure
 *
 * va_start : make new va_list
 *
 * va_arg : returns current argument
 *
 * va_copy : copy va_list
 *
 * va_end : delete va_list, set to NULL
 *
 * */
#include <stdio.h>

void	myfunc(const char* args, ...)
{

	// https://dojang.io/mod/page/view.php?id=577 설명 끝판왕
	
	va_list	ap; // --> ap = argument pointer 


	/* NOTE : malloc&init va_list (Macro function) */
	va_start(ap, args); // why args? what for? -> args는 뒤에 붙은 애들의 주소 시작점이다. 

	/* NOTE : void va_start(va_list ap, last_arg); --> 이런 형식의 함수임 
	 * ap : the object of va_list and it will hold the informatio
	 *		needed to retrieve the additional arguments with va_arg
	 *
	 * last_arg − This is the last known fixed argument being passed to the function. */


	/* NOTE : 파일 포인터 처럼, 내부에서 va_arg를 호출하면 int만큼 포인터가 이동하네. 
	 * 근데 va_list의 끝이 뭔지 알아야하네. 그래서 개수를 넣든 해야 했던 거구만. 
	 *
	 * 그럼 printf는va_list 개수를 인자로 안받으니, %의 개수를 세서 그만큼 진행하겠구나.
	 *
	 * */


/* NOTE : There is no way of knowing how many arguments are passed from 
 * inside a variable-argument function, that's why functions such as printf 
 * are using special format strings that tells the function how many arguments to expect.  */

	printf("ap addr : %p\n", ap);
	printf("args addr : %p\n", &args);

	int data = va_arg(ap, int); // va_list 배열에서 int를 읽고 int만큼 포인터를 이동
	printf("lst 1: %d", data);
	printf("\t\t%p\n", &data);
	int data2 = va_arg(ap, int);
	printf("lst 2: %d", data2);
	printf("\t\t%p\n", &data2);
	char* data3 = va_arg(ap, char*);
	printf("lst 3: %s", data3);
	printf("\t\t%p\n", &data3);
	int data4 = va_arg(ap, int);
	printf("lst 4: %d", data4);
	printf("\t\t%p\n", &data4);
	int data5 = va_arg(ap, int);
	printf("lst 5: %d", data5);
	printf("\t\t%p\n", &data5);

	/* delete va_list */
	va_end(ap);

	/* TODO : va_end가 되어도 사라지지 않는다.   */
	printf("lst 2 after va_end: %d", data2);
	printf("\t%p\n", &data2);
	// 인텔/AMD x86, x86-64 플랫폼에서는 va_end 매크로를 사용하지 않아도 동작에 지장이 없습니다. 
	// 하지만 다른 플랫폼에서는 문제가 생길 수도 있으므로 호환성을 위해서 
	// va_end로 마무리를 해주는 것이 좋습니다.
}

int main(void)
{
	myfunc("hey", 1, 2, "last");
}

