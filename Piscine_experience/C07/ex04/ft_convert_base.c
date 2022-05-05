/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 09:29:00 by minkyeki          #+#    #+#             */
/*   Updated: 2022/02/24 09:34:24 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	get_base_size(char *base)
{
	int	size;

	size = 0;
	while (base[size] != '\0')
		size++;
	return (size);
}

int	is_valid(char *base)
{
	int		i;
	int		j;

	i = 0;
	if (base[i] == '\0' || get_base_size(base) < 2)
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' \
				|| (base[i] >= 9 && base[i] <= 13) || base[i] == ' ')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			++j;
		}
		++i;
	}
	return (1);
}

int	has_base(char one_char, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (one_char == base[i])
			return (1);
		++i;
	}
	return (0);
}

int	find_base_index(char target, char *base)
{
	int	index;

	index = 0;
	while (base[index])
	{
		if (base[index] == target)
			return (index);
		++index;
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	long long	sign;
	long long	sum;
	long long	size;
	long long	to_add;

	sum = 0;
	sign = 1;
	size = get_base_size(base);
	while (*str && ((*str == ' ') || (*str >= 9 && *str <= 13)))
		++str;
	while (*str && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			sign *= -1;
		++str;
	}
	while (has_base(*str, base))
	{
		to_add = find_base_index(*str, base);
		sum = (sum * size) + (long long)to_add;
		++str;
	}
	return ((int)(sum * sign));
}
