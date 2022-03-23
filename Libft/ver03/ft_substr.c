/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 10:00:25 by minkyeki          #+#    #+#             */
/*   Updated: 2022/03/14 14:37:57 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO: assert의 장점은 dedug모드에서만 작동하고 release모드시 포함이 안된다는 점 + 에러 위치까지 잘 표시된다는점.
// Q : malloc 실패는 release모드에서도 발생할 수 있는 거 아닌가...? 그럼 assert쓰면 안되지 않나?
// A : 그렇다. 이런 경우는 assert가 아닌 exit()을 쓰는게 좋다.
// https://stackoverflow.com/questions/34486414/handling-error-checking-with-assert

// TODO: 충격적인건, 어떤 시스템(ex Mac) 의 경우 malloc 함수 내부에서 null 반환시 errno를 지가 설정해 준데...
// 그럼 나는 따로 할 필요가 없는 거 아니냐? 
// https://www.reddit.com/r/C_Programming/comments/pgeivx/do_malloccallocrealloc_set_errno/

#include <stdlib.h>
#include "libft.h"

/** Error log :  
 *
 * (1) total_len이 0일 때는 빈 문자열 넣어줘라
 *
 * */

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	total_len;
	char	*pa_str;
	char	*pa_tmp;

	if (!s)
		return (NULL);
	total_len = 0;
	while (s[start + total_len] && total_len < len)
		++total_len;
	/** if (total_len == 0) */
	/**     return (NULL); */
	pa_str = malloc(sizeof(*pa_str) * (total_len + 1));
	if (!pa_str)
		return (NULL);
	pa_tmp = pa_str;
	while (total_len-- > 0)
		*(pa_tmp++) = s[start++];
	*pa_tmp = '\0';
	return (pa_str);
}

/** #include <stdio.h> */
/** int main(int ac, char *av[]) */
/** { */
/**     if (ac != 4) */
/**         return 0; */
/**     char *s = ft_substr(av[1], atoi(av[2]), atoi(av[3])); */
/**     printf("str : %s\n", s); */
/** } */
