/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:20:04 by minkyeki          #+#    #+#             */
/*   Updated: 2022/03/11 16:15:08 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** The strncmp() function compares not more than n characters.  Because */
/**      strncmp() is designed for comparing strings rather than binary data, */
/**      characters that appear after a `\0' character are not compared. */
/**  */

// TODO : (1) 위 설명중에서, strncmp는 널 다음을 비교하지 않기 위해서라는데... ㅇ;간 strcmp도 똑같지 않냐? 무슨 차이지?
// TODO : (2) 굳이 복사를 해야 하나? 그냥 원본 써도 되지 않나? -> 2차코드에선 이 부분 수정해도 되겠음. 
#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char *s1_uchar;
	const unsigned char *s2_uchar;

	s1_uchar = (const unsigned char *)s1;
	s2_uchar = (const unsigned char *)s2;
	while (*s1_uchar && *s2_uchar && (*s1_uchar == *s2_uchar) && n > 0)
	{
		s1_uchar++;
		s2_uchar++;
		n--;
	}
	// TODO : 대부분의 오류가 바로 아래 n==0 일때를 고려하지 않아서 틀림.
	if (n == 0)
		return (0);
	else
		return ((int)(*s1_uchar - *s2_uchar));
}
