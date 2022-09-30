/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaamaou <rnaamaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 16:48:31 by ael-idri          #+#    #+#             */
/*   Updated: 2022/09/30 18:40:01 by rnaamaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//same as libft
int	ft_strlen_gnl(const char *s)
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

//same
char	*ft_strdup_gnl(const char *src)
{
	int		i;
	int		j;
	char	*s;
	char	*dest;

	i = 0;
	s = (char *)src;
	j = ft_strlen_gnl(s);
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

// not the same !!
char	*ft_strchr_gnl(const char *s, int c)
{
	int		i;
	int		sl;
	char	*str;

	i = 0;
	sl = ft_strlen_gnl(s);
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

//same
void	*ft_memcpy_gnl(void *dst, const void *src, int n)
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

// not the same free(line)!!
char	*ft_strjoin_gnl(char *line, char *buffer)
{
	char	*nline;

	if (!line && !buffer)
		return (NULL);
	if (!line)
		return (ft_strdup_gnl(buffer));
	if (!buffer)
		return (line);
	nline = (char *)malloc(ft_strlen_gnl(buffer) + ft_strlen_gnl(line) + 1);
	if (!nline)
		return (NULL);
	ft_memcpy_gnl(nline, line, ft_strlen_gnl(line));
	ft_memcpy_gnl(nline + ft_strlen_gnl(line), buffer, ft_strlen_gnl(buffer));
	nline[ft_strlen_gnl(line) + ft_strlen_gnl(buffer)] = '\0';
	free(line);
	return (nline);
}
