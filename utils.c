/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-idri <ael-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 13:26:46 by rnaamaou          #+#    #+#             */
/*   Updated: 2022/09/27 17:29:22 by ael-idri         ###   ########.fr       */
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

int	ft_type(char *str)
{
	if (!ft_strncmp(str, "NO ", 3))
		return (NO);
	if (!ft_strncmp(str, "SO ", 3))
		return (SO);
	if (!ft_strncmp(str, "WE ", 3))
		return (WE);
	if (!ft_strncmp(str, "EA ", 3))
		return (EA);
	if (!ft_strncmp(str, "F ", 2))
		return (F);
	if (!ft_strncmp(str, "C ", 2))
		return (C);
	return (0);
}

void	get_asset(t_data *data, int type, int index)
{
	if (type == NO)
		data->no = data->o_map[index];
	if (type == SO)
		data->so = data->o_map[index];
	if (type == WE)
		data->we = data->o_map[index];
	if (type == EA)
		data->ea = data->o_map[index];
	if (type == F)
		data->f = data->o_map[index];
	if (type == C)
		data->c = data->o_map[index];
}

int	map_length(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return (0);
	while (map[i])
		i++;
	return (i);
}

bool	check_assets(t_data *data)
{
	int	i;
	int	type;

	i = 0;
	if (map_length(data->o_map) < 9)
	{
		printf("non valid map");
		return (FAILED);
	}
	while (i < 6)
	{
		type = ft_type(data->o_map[i]);
		if (!type)
		{
			printf("assests not valid\n");
			return (FAILED);
		}
		get_asset(data, type, i);
	}
	if (!data->no || !data->so || !data->we || !data->ea || !data->f || !data->c )
	{
		printf("assests not valid\n");
		return (FAILED);
	}
	return (SUCCESS);
}
