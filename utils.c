/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-idri <ael-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 13:26:46 by rnaamaou          #+#    #+#             */
/*   Updated: 2022/09/29 18:49:44 by ael-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
