/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-idri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 21:01:44 by ael-idri          #+#    #+#             */
/*   Updated: 2021/11/11 06:20:32 by ael-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		sl;
	char	*str;

	sl = ft_strlen(s);
	i = sl - 1;
	str = (char *)s;
	if (c == '\0')
		return (str + sl);
	while (i >= 0 && str[i] && str[i] != (unsigned char)c)
		i--;
	if (i < 0)
		return (NULL);
	else
		return (str + i);
}
