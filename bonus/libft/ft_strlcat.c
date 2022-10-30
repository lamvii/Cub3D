/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-idri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:25:36 by ael-idri          #+#    #+#             */
/*   Updated: 2021/11/03 16:16:16 by ael-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d;
	size_t	s;
	int		i;

	i = 0;
	d = ft_strlen(dst);
	s = ft_strlen(src);
	if (d >= dstsize)
		s = s + dstsize;
	else
		s = s + d;
	if (dstsize == 0)
		return (s);
	while (src[i] && d < (dstsize - 1))
	{
		dst[d] = src[i];
		i++;
		d++;
	}
	if (d <= (dstsize - 1))
		dst[d] = '\0';
	return (s);
}
