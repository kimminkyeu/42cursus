/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 18:11:25 by minkyeki          #+#    #+#             */
/*   Updated: 2022/03/13 18:17:29 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*prev;

	tmp = *lst;
	while (tmp != NULL)
	{
		prev = tmp;
		tmp = tmp->next;
		del(prev);
		free(prev);
		prev = NULL;
	}
	lst = NULL;
}
