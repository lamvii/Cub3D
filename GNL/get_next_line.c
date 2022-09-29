/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaamaou <rnaamaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:45:08 by ael-idri          #+#    #+#             */
/*   Updated: 2022/09/29 18:37:35 by rnaamaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
	return (*ptr);
}

void	ft_trait2(char **line, char **tem)
{
	char	*ptr;
	char	*tmp;

	ptr = ft_strchr_gnl(*tem, '\n');
	*ptr = '\0';
	*line = ft_strjoin_gnl(*line, *tem);
	*line = ft_strjoin_gnl(*line, "\n");
	if (*(ptr + 1) != '\0')
	{
		tmp = *tem;
		*tem = ft_strdup_gnl(ptr + 1);
		free(tmp);
	}
	else
		ft_free(tem);
}

char	*ft_check_tem(char *line, int *sz, char **tem)
{
	if (*tem)
	{
		if (ft_strchr_gnl(*tem, '\n'))
		{
			ft_trait2(&line, tem);
			*sz = 0;
		}
		else
		{
			line = ft_strjoin_gnl(line, *tem);
			ft_free(tem);
		}
	}
	return (line);
}

int	ft_trait1(char **line, char *buff, char **tem, int *sz)
{
	char	*ptr;

	if (*sz == 0)
		return (0);
	ptr = ft_strchr_gnl(buff, '\n');
	if (ptr)
	{
		*ptr = '\0';
		*line = ft_strjoin_gnl(*line, buff);
		*line = ft_strjoin_gnl(*line, "\n");
		if (*(ptr + 1) != '\0')
			*tem = ft_strdup_gnl(ptr + 1);
		return (0);
	}
	else
		*line = ft_strjoin_gnl(*line, buff);
	return (1);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*tem;
	char		buff[BUFFER_SIZE + 1];
	int			sz;
	int			nb;

	sz = 1;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (line);
	line = ft_check_tem(line, &sz, &tem);
	while (sz)
	{
		sz = read(fd, buff, BUFFER_SIZE);
		if (sz < 0)
		{
			ft_free(&tem);
			return (ft_free(&line));
		}
		buff[sz] = '\0';
		nb = ft_trait1(&line, buff, &tem, &sz);
		if (!nb)
			break ;
	}
	return (line);
}
