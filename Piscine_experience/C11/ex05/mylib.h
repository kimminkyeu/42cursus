/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:25:19 by minkyeki          #+#    #+#             */
/*   Updated: 2022/02/23 20:26:19 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYLIB_H
# define MYLIB_H

# include <unistd.h>

int				ft_atoi(char *str);
unsigned int	itoa(char *data, unsigned int tmp);
void			ft_putnbr(int nb);
void			ft_putstr(char *str);
void			operator_add(int a, int b);
void			operator_sub(int a, int b);
void			operator_mul(int a, int b);
void			operator_div(int a, int b);
void			operator_mod(int a, int b);
void			do_operator(int a, int b, char *operator);

#endif
