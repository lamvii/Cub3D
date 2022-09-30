/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaamaou <rnaamaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:47:46 by rnaamaou          #+#    #+#             */
/*   Updated: 2022/09/30 18:42:02 by rnaamaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
	return (false);
}

bool	check_zero_sides(char **player_map, int i, int j)
{
	if (i == 0 || j == 0 || i == check_length(player_map) - 1
		|| j == max_width(player_map) - 1)
		return (false);
	if (player_map[i - 1][j] == ' ')
		return (false);
	if (player_map[i + 1][j] == ' ')
		return (false);
	if (player_map[i][j - 1] == ' ')
		return (false);
	if (player_map[i][j + 1] == ' ')
		return (false);
	return (true);
}