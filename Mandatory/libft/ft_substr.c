/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-idri <ael-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:42:53 by ael-idri          #+#    #+#             */
/*   Updated: 2022/10/03 18:25:18 by ael-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strncpy(char *dest, const char *src, unsigned int n)
{
	unsigned int	i;
	char			*s;

	i = 0;
	s = (char *)src;
	while (i < n && s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	char		*ret;
	size_t		i;

	if (!s)
		return (NULL);
	str = (char *)s;
	i = ft_strlen(s + start);
	if (len > i)
		len = i;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	ret = (char *)malloc(sizeof(char) * len + 1);
	if (!ret)
		return (NULL);
	ft_strncpy(ret, str + start, len);
	return (ret);
}
