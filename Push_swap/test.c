
/* Test code for build_trangles  */

// input : total num of trianlge.
// output : divided groups of triangle 18 = (6 + 6 + 6) = (2+2+2) + (2+2+2) + (2+2+2);


#include <stdio.h>
#include <stdbool.h>

#define INC (1)
#define DEC (0)

typedef struct s_triangle {
	int		nmemb;
	bool	inc_or_dec;
}	t_triangle;

/** 1 + 1 + 1 의 부분 삼각형도 허용해야 하나?  */

void	build_triangle_recur(int start, int end)
{
	int nmemb = end - start + 1;
	int p = nmemb / 3;

	/** TODO : if 1+1+1 까지 쪼개고싶다면, nmemb >= 3을 하세요.  */
	if (nmemb >= 6) // if nmemb is over 6, than split
	{
		build_triangle_recur(0, p - 1);
		build_triangle_recur(p, (p * 2) - 1);
		build_triangle_recur((p * 2), nmemb - 1);
	}
	else
	{
		printf("(");
		for(int i=0; i<nmemb; i++)
		{
			printf(" %d ", start + i);
		}
		printf(")");
	}
}

void	build_triangle(int start, int end)
{
	int nmemb = end - start + 1;
	int p = nmemb / 3;
	
	if (nmemb < 6) // if nmemb is less then 6, do not split
	{
		printf("(");
		for(int i=0; i<nmemb; i++)
		{
			printf(" %d ", start + i);
		}
		printf(")");
	}
	else // if over 6, split to 3 chunks
	{	
		build_triangle_recur(0, p - 1);
		build_triangle_recur(p, (p * 2) - 1);
		build_triangle_recur((p * 2), nmemb - 1);
	} 
}


void	build_triangle_ver2(int start, int end)
{
	int nmemb = end - start + 1;
	int p = nmemb / 3;

	/** TODO : if 1+1+1 까지 쪼개고싶다면, nmemb >= 3을 하세요.  */
	if (nmemb <= 3) // if nmemb is over 6, than split
	{
		printf(" %d ", nmemb);
			return ;
	}
	else
	{
		build_triangle_ver2(0, p - 1);
		build_triangle_ver2(p, (p * 2) - 1);
		build_triangle_ver2((p * 2), nmemb - 1);
	}

}

#include <stdlib.h>

int main(int ac, char **av)
{
	// build 설계도.
	if (ac != 3)
		return (1);

	build_triangle_ver2(atoi(av[1]), atoi(av[2]));
	/** build_triangle(atoi(av[1]), atoi(av[2])); */

	return (0);
}
