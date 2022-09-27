/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaamaou <rnaamaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 18:26:53 by rnaamaou          #+#    #+#             */
/*   Updated: 2022/09/27 18:27:13 by rnaamaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		printf("non valid map\n");
		return (false);
	}
	while (i < 6)
	{
		type = ft_type(data->o_map[i]);
		if (!type)
		{
			printf("assests not valid\n");
			return (false);
		}
		get_asset(data, type, i);
		i++;
	}
	if (!data->no || !data->so || !data->we || !data->ea || !data->f || !data->c )
	{
		printf("assests not valid\n");
		return (false);
	}
	return (true);
}
