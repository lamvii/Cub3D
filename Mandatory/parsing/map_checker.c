/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-idri <ael-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 13:11:25 by ael-idri          #+#    #+#             */
/*   Updated: 2022/10/04 16:59:56 by ael-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

bool	check_map(char *str, t_data *data)
{
	init_data(data);
	if (!read_map(str, data))
		return (false);
	if (!check_assets(data))
		return (false);
	if (!check_player_map(data))
		return (false);
	return (true);
}
