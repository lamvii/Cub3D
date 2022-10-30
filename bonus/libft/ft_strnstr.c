/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-idri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 11:26:14 by ael-idri          #+#    #+#             */
/*   Updated: 2021/11/20 15:35:24 by ael-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		count;
	char		*hay;

	i = ft_strlen(needle);
	j = 0;
	hay = (char *)haystack;
	if (i == 0 || haystack == needle)
		return (hay);
	while (hay[j] && j < len)
	{
		count = 0;
		while (count < i && j + count < len)
		{
			if (hay[j + count] != needle[count])
				break ;
			else
				count++;
		}
		if (count == i)
			return (hay + j);
		j++;
	}
	return (0);
}
