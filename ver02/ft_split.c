/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 09:44:06 by minkyeki          #+#    #+#             */
/*   Updated: 2022/03/13 18:20:32 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** TODO : const char *str 과 char const *str은 같은거임. char * const str이 다른거임. */

/** TODO : free를 해줘야 하나? 해줘야 한다면 어디서? 
 *			-> TODO: 왜냐면 허용 함수에 free가 있다.... 왜 있지?		
 *			*/ 

/** 
 *		앗 알았다. 하나라도 객체 생성에 실패하면, 그 이전까지 했던 모든걸 free해줘야 하잖아. 
 *		왜냐면 하나를 실패해서 null ptr이 들어오게 되면 그건 split 전체 코드가 실패하는 거니까.
 *		
 *
 *
 * */

#include <stdlib.h>
#include <stdbool.h>

static size_t	count_word(const char *str, char c)
{
	size_t	cnt;
	bool	is_after_word;

	if (!*str)
		return (0);
	cnt = 0;
	is_after_word = false;
	while (*str)
	{
		if (*str != c && *str != '\0')
			is_after_word = true;
		if (is_after_word && (*str == c || *str == '\0'))
		{
			is_after_word = false;
			++cnt;
		}
		++str;
	}
	return (cnt);
}

static size_t	get_word_len(const char *word_start, char c)
{
	size_t	word_len;

	word_len = 0;
	while (*word_start && *word_start != c && *word_start != '\0')
	{
		++word_start;
		++word_len;
	}
	return (word_len);
}

static char	*each_word_malloc(const char *word_start, char c)
{
	size_t	len;
	size_t	cnt;
	char	*pa_word;

	cnt = 0;
	len = get_word_len(word_start, c);
	pa_word = malloc((sizeof(*pa_word) * len) + 1);
	if (!pa_word)
		return (NULL);
	while (cnt < len)
	{
		if (*word_start != c)
		{
			pa_word[cnt] = *word_start;
			++cnt;
		}
		++word_start;
	}
	pa_word[len] = '\0';
	return (pa_word);
}

static void	free_all(char **strs, size_t idx)
{
	size_t	i;

	i = 0;
	while (i <= idx)
	{
		free(strs[i]);
		strs[i] = NULL;
		i++;
	}
	free(strs);
	strs = NULL;
}

char	**ft_split(char const *s, char c)
{
	char			**pa_result;
	size_t			word_count;
	size_t			i;

	word_count = count_word(s, c);
	pa_result = malloc((sizeof(*pa_result) * (word_count + 1)));
	if (!pa_result)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		pa_result[i] = each_word_malloc(s, c);
		if (pa_result[i] == NULL)
		{
			free_all(pa_result, i);
			return (NULL);
		}
		++i;
		s += get_word_len(s, c);
	}
	pa_result[word_count] = NULL;
	return (pa_result);
}
