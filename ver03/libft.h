/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:45:16 by minkyeki          #+#    #+#             */
/*   Updated: 2022/03/15 21:15:55 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h> //--> this includes null
//# include <sys/types.h> // no NUll defined...
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/* Part 1. Functions that doesn't use <stdlib.h> */
// -> remove upper description!

/* add description */
extern int		ft_isalpha(int c);

/* add description */
extern int		ft_isdigit(int c);

/* add description */
extern int		ft_isalnum(int c);

/* add description */
extern int		ft_isascii(int c);

/* add description */
extern int		ft_isprint(int c);

/* add description */
extern size_t	ft_strlen(const char *str);

/* add description */
extern void		ft_bzero(void *s, size_t n);

/* add description */
extern size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);

/* add description */
extern size_t	ft_strlcat(char *dest, const char *src, size_t n);

/* add description */
extern int		ft_toupper(int c);

/* add description */
extern int		ft_tolower(int c);

/* add description */
extern char		*ft_strchr(const char *s, int c);

/* add description */
extern char		*ft_strrchr(const char *s, int c);

/* add description */
extern int		ft_strncmp(const char *s1, const char *s2, size_t n);

/* add description */
extern void		*ft_memset(void *b, int c, size_t len);

/* add description */
extern void		*ft_memcpy(void *dst, const void *src, size_t n);

/* add description */
extern void		*ft_memmove(void *dst, const void *src, size_t len);

/* add description */
extern void		*ft_memchr(const void *s, int c, size_t n);

/* add description */
extern int		ft_memcmp(const void *s1, const void *s2, size_t n);

/* add description */
extern char		*ft_strnstr(const char *haystack, \
		const char *needle, size_t len);

/* Part 1. Functions that use <stdlib.h> */

/* add description */
extern int		ft_atoi(const char *str);

/* add description */
extern void		*ft_calloc(size_t count, size_t size);

/* add description */
extern char		*ft_strdup(const char *s1);

/* Part 2. Additional Functions */
extern char		*ft_substr(char const *s, unsigned int start, size_t len);

/* add description */
extern char		*ft_strjoin(char const *s1, char const *s2);

/* add description */
extern char		*ft_strtrim(char const *s1, char const *set);

/* add description */
extern char		**ft_split(char const *s, char c);

/* add description */
extern char		*ft_itoa(int n);

/* add description */
extern char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/* add description */
extern void		ft_striteri(char *s, void (*f)(unsigned int, char*));

/* add description */
extern void		ft_putchar_fd(char c, int fd);

/* add description */
extern void		ft_putstr_fd(char *s, int fd);

/* add description */
extern void		ft_putendl_fd(char *s, int fd);

/* add description */
extern void		ft_putnbr_fd(int n, int fd);

/* Part 3. Bonus Part (s_list) */

/* add description */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/* add description */
extern t_list	*ft_lstnew(void *content);

/* add description */
extern void		ft_lstadd_front(t_list **lst, t_list *new);

/* add description */
extern int		ft_lstsize(t_list *lst);

/* add description */
extern t_list	*ft_lstlast(t_list *lst);

/* add description */
extern void		ft_lstadd_back(t_list **lst, t_list *new);

/* add description */
extern void		ft_lstdelone(t_list *lst, void (*del)(void *));

/* add description */
extern void		ft_lstclear(t_list **lst, void (*del)(void *));

/* add description */
extern void		ft_lstiter(t_list *lst, void (*f)(void *));

/* add description */
extern t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), \
		void (*del)(void *));

#endif
