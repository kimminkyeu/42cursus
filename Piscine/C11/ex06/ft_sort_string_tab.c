/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 20:53:26 by minkyeki          #+#    #+#             */
/*   Updated: 2022/02/23 09:58:10 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	my_strcmp(char *a, char *b)
{
	while (*a == *b && *a && *b)
	{
		++a;
		++b;
	}
	return ((int)(*a - *b));
}

void	ft_sort_string_tab(char **tab)
{
	int		i;
	int		j;
	int		len;
	char	*tmp;

	len = 0;
	while (tab[len])
		++len;
	i = 0;
	while (i + 1 < len)
	{
		j = i;
		while (j + 1 < len)
		{
			if (my_strcmp(tab[j], tab[j + 1]) > 0)
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			++j;
		}
		--len;
	}
}
