/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 09:20:34 by minkyeki          #+#    #+#             */
/*   Updated: 2022/02/14 11:37:10 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

const char	*g_hex;
char		g_output[2];

void	ft_putstr_16byte_non_printable(const char *input, unsigned int size)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)input;
	while (size > 0)
	{
		if (*tmp >= 32 && *tmp <= 126)
			write(1, tmp, 1);
		else
			write(1, ".", 1);
		--size;
		++tmp;
	}
}

void	print_last(unsigned int size)
{
	unsigned int	cnt1;
	unsigned int	cnt2;
	unsigned int	cnt3;

	cnt1 = 2 * (size % 2);
	cnt2 = ((16 - size) % 2) + ((16 - size) / 2);
	cnt3 = ((16 - size) / 2) * 4;
	while (cnt1 > 0)
	{
		write(1, " ", 1);
		--cnt1;
	}
	while (cnt2 > 0)
	{
		write(1, " ", 1);
		--cnt2;
	}
	while (cnt3 > 0)
	{
		write(1, " ", 1);
		--cnt3;
	}
}

void	print_char_to_hex(const char *input, unsigned int size)
{
	unsigned int		tmp;
	unsigned int		data_1byte;
	unsigned int		size_cpy;

	size_cpy = size;
	while (size_cpy > 0)
	{
		data_1byte = *((char *)input - size_cpy + size);
		tmp = 0;
		while (tmp < 2)
		{
			g_output[1 - tmp] = g_hex[(data_1byte) % 16];
			data_1byte = data_1byte / 16;
			++tmp;
		}
		write(1, g_output, 2);
		if ((size - size_cpy) % 2 == 1)
			write(1, " ", 1);
		--size_cpy;
	}
	if (size_cpy == 0 && size < 16)
		print_last(size);
}

void	print_address_to_hex(const void *input)
{
	unsigned long long	_8byte;
	char				output[16];
	unsigned int		count;

	count = 16;
	_8byte = (unsigned long long)input;
	while (count > 0)
	{
		output[count - 1] = g_hex[(_8byte % 16)];
		_8byte = _8byte / 16;
		--count;
	}
	write(1, output, 16);
	write(1, ": ", 2);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char				*_1byte;
	unsigned int		line_count;
	unsigned int		line_last_size;

	if (size == 0)
		return (addr);
	g_hex = "0123456789abcdef";
	_1byte = (char *)addr;
	line_count = size / 16;
	line_last_size = size % 16;
	while (line_count > 0)
	{
		print_address_to_hex(_1byte);
		print_char_to_hex(_1byte, 16);
		ft_putstr_16byte_non_printable(_1byte, 16);
		write(1, "\n", 1);
		--line_count;
		_1byte += 16;
	}
	print_address_to_hex(_1byte);
	print_char_to_hex(_1byte, line_last_size);
	ft_putstr_16byte_non_printable(_1byte, line_last_size);
	if (size != 0)
		write(1, "\n", 1);
	return (addr);
}
