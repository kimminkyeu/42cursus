/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:44:47 by minkyeki          #+#    #+#             */
/*   Updated: 2022/03/14 18:17:38 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

// TODO: 2중포인터 리스트를 받을때는 그냥 일단 다르게 하자...

void	ft_lstadd_back(t_list **lst, t_list *new)
{

	/** if (!lst || !new)
	  *     return ;
	  * if (!*lst)
	  *     *lst = new;
	  * else
	  *     ft_lstlast(*lst)->next = new; */

	//---------------------------------------------------------------------
  /*     // TODO : 
   *
   *     왜 이렇게 하면 안될까?? 왜 위처럼 하면 로직이 안되는거지?? 대체 왜??? */

/**     t_list	*tmp;
  *
  *     if (!lst || !new)
  *         return ;
  *     if (!*lst)
  *         *lst = new;
  *     else
  *     {
  *         tmp = *lst;
  *         while (tmp != NULL)
  *             tmp = tmp->next;
  *         tmp = new;
  *     } */

	/* TODO: 근데 아래처럼 하면 또 되요....왜냐고... ㅠㅜ  */

/**     t_list	*tmp;
  *
  *     if (!lst || !new)
  *         return ;
  *     if (!*lst)
  *         *lst = new;
  *     else
  *     {
  *         tmp = *lst;
  *         while (tmp->next != NULL)
  *             tmp = tmp->next;
  *         tmp->next = new;
  *     } */

	/* TODO: 근데 아래처럼 하면 또 되요....왜냐고... ㅠㅜ  */

	t_list	*tmp;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = new;
    }

}
/**  */
/** #include <stdio.h> */
/**  */
/** int main() */
/** { */
/**     int a = 1; */
/**     int b = 2; */
/**     int c = 3; */
/**     int	d = 4; */
/**     t_list *lst = ft_lstnew(&a); */
/**  */
/**     ft_lstadd_back(&lst, ft_lstnew(&b)); */
/**     ft_lstadd_back(&lst, ft_lstnew(&c)); */
/**     ft_lstadd_back(&lst, ft_lstnew(&d)); */
/**  */
/**     t_list *tmp; */
/**     tmp = lst; */
/**     printf("size : %d\n", ft_lstsize(lst)); */
/**     while (tmp != NULL) */
/**     { */
/**         printf("%d\n", *((int*)tmp->content)); */
/**         tmp = tmp->next; */
/**     } */
/**     return (0); */
/** } */
