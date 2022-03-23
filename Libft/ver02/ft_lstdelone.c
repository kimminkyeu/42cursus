/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 18:06:35 by minkyeki          #+#    #+#             */
/*   Updated: 2022/03/13 18:16:27 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/** TODO: The memory of ’next’ must not be freed. */

void ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst)
	{
		del(lst);
		free(lst);
		lst = NULL;
	}
}
