/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-idri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:32:47 by ael-idri          #+#    #+#             */
/*   Updated: 2021/11/03 17:19:35 by ael-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	int			i;

	d = dst;
	s = src;
	i = 0;
	if (d == NULL && s == NULL)
		return (NULL);
	while (n > 0)
	{
		d[i] = s[i];
		i++;
		n--;
	}
	return (d);
}
