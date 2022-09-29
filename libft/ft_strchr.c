/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-idri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:52:02 by ael-idri          #+#    #+#             */
/*   Updated: 2021/11/13 22:56:06 by ael-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		sl;
	char	*str;

	i = 0;
	sl = ft_strlen(s);
	str = (char *)s;
	if (c == '\0')
	{
		while (str[i] && str[i] != '\0')
			i++;
		if (str[i] == '\0')
			return (str + i);
		return (NULL);
	}
	while (str[i] && str[i] != (unsigned char)c)
		i++;
	if (i >= sl)
		return (NULL);
	else
		return (str + i);
}
