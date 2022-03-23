/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:45:16 by minkyeki          #+#    #+#             */
/*   Updated: 2022/03/17 00:58:50 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

/* Check if c is an alphabetic character.
 * it is equivalent to (isupper(c) || islower(c)).*/
extern int		ft_isalpha(int c);

/* Check if c is a digit (0 through 9). */
extern int		ft_isdigit(int c);

/* Check if c is an alphanumeric character. 
 * it is equivalent to (isalpha(c) || isdigit(c)). */
extern int		ft_isalnum(int c);

/* Check whether c is a 7-bit unsigned char value 
 * that fits into the ASCII character set. */
extern int		ft_isascii(int c);

/* Check whether c is a printable character including space. */
extern int		ft_isprint(int c);

/* Return the length of str. */
extern size_t	ft_strlen(const char *str);

/* Set n bytes of s to 0. */
extern void		ft_bzero(void *s, size_t n);

/* Copy up to dstsize - 1 characters from the NUL-terminated 
 * string src to dest, NUL-terminating the result. */
extern size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);

/* Append the NUL-terminated string src to the end of dest.
 * It will append at most size - strlen(dest) - 1 bytes, 
 * NUL-terminating the result. */
extern size_t	ft_strlcat(char *dest, const char *src, size_t n);

/* Convert lowercase letter c to uppercase. */
extern int		ft_toupper(int c);

/* Convert uppercase letter c to lowercase. */
extern int		ft_tolower(int c);

/* Returns a pointer to the first occurrence of 
 * the character c in the string s. */
extern char		*ft_strchr(const char *s, int c);

/* Returns a pointer to the last occurrence of 
 * the character c in the string s. */
extern char		*ft_strrchr(const char *s, int c);

/* Compare n characters of s1 and s2. */
extern int		ft_strncmp(const char *s1, const char *s2, size_t n);

/* Fill the first len bytes of the memory area 
 * pointed to by b with the constant byte c. */
extern void		*ft_memset(void *b, int c, size_t len);

/* Copy n bytes from memory area src to memory area dst.
 * The memory areas must not overlap.
 * Use ft_memmove if the memory areas do overlap. */
extern void		*ft_memcpy(void *dst, const void *src, size_t n);

/* Copy len bytes from memory area src to memory area dst.
 * The memory areas may overlap: copying takes place as 
 * though the bytes in src are first copied into a temporary array 
 * that does not overlap src or dest, and the bytes are then copied 
 * from the temporary array to dest. */
extern void		*ft_memmove(void *dst, const void *src, size_t len);

/* Scan the initial n bytes of the memory area pointed to 
 * by s for the first instance of c.
 * Both c and the bytes of the memory area pointed to 
 * by s are interpreted as unsigned char. */
extern void		*ft_memchr(const void *s, int c, size_t n);

/* Compares the first n bytes (each interpreted as unsigned char) 
 * of the memory areas s1 and s2. */
extern int		ft_memcmp(const void *s1, const void *s2, size_t n);

/* Locates the first occurrence of the null-terminated string needle
 * in the string haystack, where not more than len characters are searched. */
extern char		*ft_strnstr(const char *haystack, \
		const char *needle, size_t len);

/* Convert the initial portion of the string pointed to by str to int. 
 * ft_atoi() does not detect errors, such as overflow. */
extern int		ft_atoi(const char *str);

/* Allocates memory for an array of count elements of size bytes each.
 * Returns a pointer to the allocated memory, which is set to zero. 
 * If the multiplication of count and size would result in integer 
 * overflow, then ft_calloc() sets errno to indicate error.*/
extern void		*ft_calloc(size_t count, size_t size);

/* Return a pointer to a new string which is a duplicate of the string s1. */
extern char		*ft_strdup(const char *s1);

/* Allocates and returns a substring from the string ’s’.
 * The substring begins at index ’start’ and is of maximum size ’len’.*/
extern char		*ft_substr(char const *s, unsigned int start, size_t len);

/* Allocates and returns a new string, which is the result 
 * of the concatenation of ’s1’ and ’s2’ */
extern char		*ft_strjoin(char const *s1, char const *s2);

/* Allocates and returns a copy of ’s1’ with the characters 
 * specified in ’set’ removed from the beginning and the end of the string. */
extern char		*ft_strtrim(char const *s1, char const *set);

/* Allocates and returns an array of strings obtained by splitting 
 * ’s’ using the character ’c’ as a delimiter. */
extern char		**ft_split(char const *s, char c);

/* Allocates and returns a string representing the integer 
 * received as an argument. */
extern char		*ft_itoa(int n);

/* Allocates and returns a string resulting from successive 
 * applications of ’f’ to each character of the string ’s’.*/
extern char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/* Applies the function 'f' to each character of the string 
 * passed as argument, and passing its index to 'f' as first argument. */
extern void		ft_striteri(char *s, void (*f)(unsigned int, char*));

/* Outputs the character ’c’ to the given file descriptor. */
extern void		ft_putchar_fd(char c, int fd);

/* Outputs the string ’s’ to the given file descriptor. */
extern void		ft_putstr_fd(char *s, int fd);

/* Outputs the string ’s’ to the given file descriptor, 
 * followed by a newline. */
extern void		ft_putendl_fd(char *s, int fd);

/* Outputs the integer ’n’ to the given file descriptor. */
extern void		ft_putnbr_fd(int n, int fd);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/* Allocates and returns a pointer to the new element of t_list.
 * (1) t_list variable ’content’ is initialized with the value 
 * of the parameter ’content’.
 * (2) t_list variable 'next' is initialized to NULL. */
extern t_list	*ft_lstnew(void *content);

/* Adds the element ’new’ at the beginning of the list. */
extern void		ft_lstadd_front(t_list **lst, t_list *new);

/* Counts the number of elements in a list. */
extern int		ft_lstsize(t_list *lst);

/* Returns the last element of the list. */
extern t_list	*ft_lstlast(t_list *lst);

/* Adds the element ’new’ at the end of the list. */
extern void		ft_lstadd_back(t_list **lst, t_list *new);

/* Delete one element pointed by 'lst' using the function 'del',
 * then free the element. */
extern void		ft_lstdelone(t_list *lst, void (*del)(void *));

/* Delete content (using 'del') and free every element of the list,
 * then set the pointer to the list to NULL. */
extern void		ft_lstclear(t_list **lst, void (*del)(void *));

/* Iterates the list and applies the function ’f’ 
 * to the content of each element. */
extern void		ft_lstiter(t_list *lst, void (*f)(void *));

/* Iterates the list and applies the function ’f’
 * to the content of each element.
 * Allocates a new list resulting of the successive applications 
 * of the function ’f’. The ’del’ function is used to delete 
 * the content of an element if needed. */
extern t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), \
		void (*del)(void *));

#endif
