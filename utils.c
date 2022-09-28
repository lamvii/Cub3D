/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaamaou <rnaamaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 13:26:46 by rnaamaou          #+#    #+#             */
/*   Updated: 2022/09/28 11:27:50 by rnaamaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while ((s1[i] != '\0' || s2[i] != '\0')
		&& i != n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		||c == '\f' || c == '\r' || c == ' ')
		return (true);
	return (false);
}

int	ft_open(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error");
		strerror(errno);
		return (0);
	}
	return (fd);
}

char	**ft_realoc(char **tab, int size)
{
	int		i;
	char	**n_tab;

	i = 0;
	n_tab = (char **)malloc(sizeof(char *) * size);
	while (i < size - 1)
	{
		n_tab[i] = tab[i];
		i++;
	}
	free(tab);
	return (n_tab);
}

void	init_data(t_data *data)
{
	int	i;

	data->o_map = NULL;
	data->map = NULL;
	data->no = NULL;
	data->so = NULL;
	data->we = NULL;
	data->ea = NULL;
	i = 0;
	while (i < 3)
	{
		data->f[i] = -1;
		data->c[i] = -1;
		i++;
	}
}
