/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-idri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 21:06:12 by ael-idri          #+#    #+#             */
/*   Updated: 2021/11/20 18:08:51 by ael-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nlist;
	t_list	*node;

	if (!lst)
		return (NULL);
	node = ft_lstnew(f(lst->content));
	if (!node)
	{
		ft_lstclear(&nlist, del);
		return (NULL);
	}
	nlist = node;
	lst = lst->next;
	while (lst)
	{
		node = ft_lstnew(f(lst->content));
		if (!node)
		{
			ft_lstclear(&nlist, del);
			break ;
		}
		ft_lstadd_back(&nlist, node);
		lst = lst->next;
	}
	return (nlist);
}
