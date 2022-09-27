/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-idri <ael-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 18:26:53 by rnaamaou          #+#    #+#             */
/*   Updated: 2022/09/27 20:23:53 by ael-idri         ###   ########.fr       */
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

char	*pass_w_space(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (ft_ispace(str[i]))
		i++;
	return (str + i);
}

void	get_asset(t_data *data, int type, int index)
{
	if (type == NO)
		data->no = pass_w_space(data->o_map[index] + 3);
	if (type == SO)
		data->so = pass_w_space(data->o_map[index] + 3);
	if (type == WE)
		data->we = pass_w_space(data->o_map[index] + 3);
	if (type == EA)
		data->ea = pass_w_space(data->o_map[index] + 3);
	//elem =split by ',' --> f[i] =atoi(elems) kmelhom llah irdi3lik
	// if (type == F)
	// 	data->f = data->o_map[index];
	// if (type == C)
	// 	data->c = data->o_map[index];
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

bool	parse_assets(t_data *data)
{
	int	i;
	int	type;

	i = 0;
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
	return (true);
}

bool	check_assets(t_data *data)
{
	int	i;

	i = 0;
	if (map_length(data->o_map) < 9)
	{
		printf("non valid map\n");
		return (false);
	}
	if (!parse_assets(data))
		return (false);
	if (!data->no || !data->so || !data->we || !data->ea
		|| !data->f || !data->c)
	{
		printf("assests not valid\n");
		return (false);
	}
	return (true);
}
