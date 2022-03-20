/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:45:16 by minkyeki          #+#    #+#             */
/*   Updated: 2022/03/11 13:27:12 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

// TODO : https://stackoverflow.com/questions/36594569/which-header-should-i-include-for-size-t
/* TODO: 헤더에서 stdlib을 include하면, 다른 함수들까지 모두 
 * stdlib.h를 include해서 파일 용량이 커지지 않나...?  
 * 아닌가...? 내가 볼땐 이게 확실하다. 존나게.. 그냥 따로 해야 된다.*/

/* 여기는 stddef.h 만 include하는게 좋을 듯. stddef.h는 함수는 함수 정의가 없고 5개의 타입만 정의하기 때문에 더 가볍다고 생각함. . */
extern int		ft_isalpha(int c);
extern int		ft_isdigit(int c);
extern int		ft_isalnum(int c);
extern int		ft_isascii(int c);
extern int		ft_isprint(int c);
extern size_t	ft_strlen(const char *str);
extern void		ft_bzero(void *s, size_t n);
extern size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);
extern size_t	ft_strlcat(char *dest, const char *src, size_t n);
extern int		ft_toupper(int c);
extern int		ft_tolower(int c);
extern char		*ft_strchr(const char *s, int c);
extern char		*ft_strrchr(const char *s, int c);
extern int		ft_strncmp(const char *s1, const char *s2, size_t n);
extern void		*ft_memset(void *b, int c, size_t len);
extern void		*ft_memcpy(void *dst, const void *src, size_t n);
extern void		*ft_memmove(void *dst, const void *src, size_t len);
extern void		*ft_memchr(const void *s, int c, size_t n);
extern int		ft_memcmp(const void *s1, const void *s2, size_t n);
extern char		*ft_strnstr(const char *haystack, const char *needle, size_t len);

/* below functions include <stdlib.h> int each *.c file */
extern int		ft_atoi(const char *str);
extern void		*ft_calloc(size_t count, size_t size);
extern char		*ft_strdup(const char *s1);

# endif
