/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-idri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 16:48:31 by ael-idri          #+#    #+#             */
/*   Updated: 2021/12/27 16:48:33 by ael-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	if (!s)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	int		i;
	int		j;
	char	*s;
	char	*dest;

	i = 0;
	s = (char *)src;
	j = ft_strlen(s);
	dest = (char *)malloc(sizeof(char) * (j + 1));
	if (dest == NULL)
		return (NULL);
	else
	{
		while (s[i])
		{
			dest[i] = s[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (dest);
}

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

void	*ft_memcpy(void *dst, const void *src, int n)
{
	char		*d;
	const char	*s;
	int			i;

	d = dst;
	s = src;
	i = 0;
	if (d == NULL && s == NULL)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}

char	*ft_strjoin(char *line, char *buffer)
{
	char	*nline;

	if (!line && !buffer)
		return (NULL);
	if (!line)
		return (ft_strdup(buffer));
	if (!buffer)
		return (line);
	nline = (char *)malloc(ft_strlen(buffer) + ft_strlen(line) + 1);
	if (!nline)
		return (NULL);
	ft_memcpy(nline, line, ft_strlen(line));
	ft_memcpy(nline + ft_strlen(line), buffer, ft_strlen(buffer));
	nline[ft_strlen(line) + ft_strlen(buffer)] = '\0';
	free(line);
	return (nline);
}
