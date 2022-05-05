/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 09:30:51 by minkyeki          #+#    #+#             */
/*   Updated: 2022/02/21 14:50:11 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_seperator(char *word, char *charset)
{
	while (*charset)
	{
		if (*word == *charset)
			return (1);
		++charset;
	}
	return (0);
}

unsigned int	count_word(char *str, char *charset)
{
	unsigned int	cnt;
	int				is_after_word;

	if (!*str)
		return (0);
	cnt = 0;
	is_after_word = 0;
	while (*str)
	{
		if (!is_seperator(str, charset))
			is_after_word = 1;
		if (is_after_word && is_seperator(str, charset))
		{
			is_after_word = 0;
			++cnt;
		}
		++str;
	}
	if (!is_seperator(--str, charset))
		++cnt;
	return (cnt);
}

unsigned int	get_word_len(char *word_start, char *charset)
{
	unsigned int	word_len;

	word_len = 0;
	while (*word_start && !is_seperator(word_start, charset))
	{
		++word_start;
		++word_len;
	}
	return (word_len);
}

char	*each_word_malloc(char *word_start, char *charset)
{
	unsigned int	len;
	char			*tmp;
	unsigned int	cnt;

	cnt = 0;
	len = get_word_len(word_start, charset);
	tmp = malloc((sizeof(*tmp) * len) + 1);
	if (!tmp)
		return (NULL);
	while (cnt < len)
	{
		tmp[cnt] = *word_start;
		++word_start;
		++cnt;
	}
	tmp[len] = '\0';
	return (tmp);
}

char	**ft_split(char *str, char *charset)
{
	char			**result;
	unsigned int	word_count;
	unsigned int	i;

	word_count = count_word(str, charset);
	result = malloc((sizeof(*result) * (word_count + 1)));
	if (!result)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		while (is_seperator(str, charset))
			++str;
		result[i] = each_word_malloc(str, charset);
		++i;
		str += get_word_len(str, charset);
	}
	result[word_count] = NULL;
	return (result);
}
