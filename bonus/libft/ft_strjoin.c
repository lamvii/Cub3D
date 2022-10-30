/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-idri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:28:31 by ael-idri          #+#    #+#             */
/*   Updated: 2021/11/15 01:26:09 by ael-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str1;
	char	*str2;
	char	*ret;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	str1 = (char *)s1;
	str2 = (char *)s2;
	ret = (char *)malloc(ft_strlen(str1) + ft_strlen(str2)+ 1);
	if (!ret)
		return (NULL);
	ft_memcpy(ret, str1, ft_strlen(s1));
	ft_memcpy(ret + ft_strlen(s1), str2, ft_strlen(s2));
	ret[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (ret);
}
