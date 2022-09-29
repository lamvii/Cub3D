/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_playermap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-idri <ael-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 22:07:11 by ael-idri          #+#    #+#             */
/*   Updated: 2022/09/29 22:53:57 by ael-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	max_width(char **str)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (str[i])
	{
		if (ft_strlen(str[i]) > max)
			max = ft_strlen(str[i]);
		i++;
	}
	return (max);
}

bool	init_palyermap(t_data *data)
{
	int	length;
	int	width;
	int	i;

	i = 0;
	length = tab__length(data->o_map + 6);
	width = max_width(data->o_map + 6);
	data->map = (char **)malloc(sizeof(char *) * length);
	if (!data->map)
		return (false);
	// case null !!
	while (i < length)
	{
		data->map[i] = str_refine(data->o_map + 6 + i, width);
		if (!data->map[i])
			return (false);
		i++;
	}
	return (true);
}

bool	check_player_map(t_data *data)
{
	if (init_playermap(data))
	{
		printf("fail init map!!\n");
		return (false);
	}
	return (1);
}
