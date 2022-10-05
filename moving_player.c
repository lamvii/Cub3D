/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaamaou <rnaamaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:59:12 by rnaamaou          #+#    #+#             */
/*   Updated: 2022/10/05 14:06:05 by rnaamaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_up_down(int move)
{
	if (move == W)
		return (-1);
	if (move == S)
		return (1);
	return (0);
}

int	ft_right_left(int move)
{
	if (move == A)
		return (-1);
	if (move == D)
		return (1);
	return (0);
}
static int	player_move(t_cub *cub,int move)
{
	// int	curr_x;
	// int	curr_y;
	//int	curr_x;

	// curr_x = (int)cub->px;
	// curr_y = (int)cub->py;
	cub->py += ft_up_down(move);
	cub->px += ft_right_left(move);
	// map[curr_x][curr_y] = '0';
	// map[(int)cub->px][(int)cub->py] = 'P';
	
	return (0);
}

static int key_hook(int keycode, void *pram)
{
	t_cub *cub;

	printf("sdfsd\n");
	cub = (t_cub *)pram;
	if (keycode == ESC)
	{
		exit(0);
	}
	if (keycode != ESC && keycode != W && keycode != A && keycode != S
		&& keycode != D)
		return (1);
	if (player_move(cub, keycode) == 1)
	{
		exit (0);
	}
	return (0);
}
void	movement(t_cub *map)
{
	mlx_hook(map->mlx_w, 2, 0, key_hook, map);
}