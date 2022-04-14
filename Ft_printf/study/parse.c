#include <stdio.h>



/* Test for state machine via Recursion */
/* 
 * #next == new line 
 * 
 *
 *
 * */


/* NOTE: 해보니 장점 : 에러 체킹에 효과적인듯. 재귀중에 오류나면 바로 끝이니까.  */

const char *language = "void	myfunc(int a, int b); int myfunc2(void); hello";


void	parse_recur(const char **line, int *cnt)
{
	if (**line == '\0')
	{
		printf("\t\t\t --> syntax error");
		*cnt = -1;
		return ;
	}
	if (**line == ';')
	{
		printf("\t\t\t --> parse finished. total : %d\n", *cnt);
		*line += 1;
		*cnt = 0;
		return ;
	}
	else
	{
		*cnt += 1;
		printf("%c", **line);
		*line += 1;
		parse_recur(line, cnt);
	}
}

void	parse(const char **line)
{
	static int	count;
	parse_recur(line, &count);
	printf("\n");

	parse_recur(line, &count);
	printf("\n");

	parse_recur(line, &count);
	printf("\n");

}

int main(void)
{
	parse(&language);

	return (0);
}
