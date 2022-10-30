/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-idri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 20:50:23 by ael-idri          #+#    #+#             */
/*   Updated: 2021/11/20 15:39:34 by ael-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*courant;

	while (*lst)
	{	
		courant = (*lst);
		*lst = (*lst)->next;
		ft_lstdelone(courant, del);
	}
	lst = NULL;
}
