/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:45:29 by minkyeki          #+#    #+#             */
/*   Updated: 2022/02/12 10:48:12 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	char	*tmp;
	char	is_first_char;

	tmp = str;
	is_first_char = 1;
	while (*tmp != '\0')
	{
		if (!((*tmp >= '0' && *tmp <= '9') || (*tmp >= 'A' && *tmp <= 'Z') \
					|| (*tmp >= 'a' && *tmp <= 'z')))
			is_first_char = 1;
		else if (is_first_char && (*tmp < 'a' || *tmp > 'z'))
			is_first_char = 0;
		else if (is_first_char && *tmp >= 'a' && *tmp <= 'z')
		{
			*tmp -= 32;
			is_first_char = 0;
		}
		else if (!is_first_char && *tmp >= 'A' && *tmp <= 'Z')
			*tmp += 32;
		++tmp;
	}
	return (str);
}
