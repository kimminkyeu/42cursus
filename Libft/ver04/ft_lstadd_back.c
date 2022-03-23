/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:44:47 by minkyeki          #+#    #+#             */
/*   Updated: 2022/03/17 01:51:58 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		printf("*lst : %d\n", *(int*)(*lst)->content);
		tmp = *lst;
		while (*lst != NULL)
		{
			printf("tmp : %d\n", *(int*)(tmp)->content);
			*lst = (*lst)->next;
		}
		*lst = new;
		printf("*head of **lst : %d\n", *(int*)(tmp)->content);
	}
}


void	print_all(t_list *head)
{
	while (head != NULL)
	{
		printf("%d->", *((int*)head->content));
		head = head -> next;
	}
	printf("\n");
}

int main()
{
	int a = 1;
	int b = 2;
	int c = 3;
	int	d = 4;
	t_list **lst = &(ft_lstnew(&a));

	ft_lstadd_back(lst, ft_lstnew(&b));
	ft_lstadd_back(lst, ft_lstnew(&c));
	ft_lstadd_back(lst, ft_lstnew(&d));

	t_list *tmp;
	tmp = *lst;
	printf("size : %d\n", ft_lstsize(*lst));
	while (tmp != NULL)
	{
		printf("all_%d\n", *((int*)tmp->content));
		tmp = tmp->next;
	}
	print_all(lst);
	return (0);
}
