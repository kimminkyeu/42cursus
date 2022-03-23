/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 10:26:11 by minkyeki          #+#    #+#             */
/*   Updated: 2022/03/11 15:09:00 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	if (dst_len >= dstsize)
		return (dstsize + src_len);
	while (src[i] && (dst_len + i + 1 < dstsize))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}


// Error log : 애플 코드를 봐도 원리는 똑같다. 복사가 일어나지 않았다면 널을 넣으면 안된다.
/* * void	ft_print_result(int n) */
/** { */
/**     char c; */
/**  */
/**     if (n >= 10) */
/**         ft_print_result(n / 10); */
/**     c = n % 10 + '0'; */
/**     write (1, &c, 1); */
/** } */
/**  */
/** int main() */
/** { */
/**     char dest[40]; */
/**     memset(dest, 0, 15); */
/**     memset(dest, 'r', 6); */
/**     memset(dest, 'r', 15); */
/**     ft_print_result(ft_strlcat(dest, "lorem ipsum dolor sit amet", 5)); */
/**     write(1, "\n", 1); */
/**     write(1, dest, 15); */
/**     write(1, "\n", 1); */
/**     printf("rrrrrrrrrrrrrrr  -> answer"); */
/**     return 0; */
/** } */
