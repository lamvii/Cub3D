/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-idri <ael-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:59:12 by rnaamaou          #+#    #+#             */
/*   Updated: 2022/10/05 16:06:03 by ael-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_forward_back(int move)
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

static int	player_move(t_cub *cub, int move)
{
	cub->py += ft_forward_back(move);
	cub->px += ft_right_left(move);
	mlx_clear_window(cub->mlx_p, cub->mlx_w);
	mlx_update_image(cub);
	draw_mmap(cub);
	mlx_put_image_to_window(cub->mlx_p, cub->mlx_w, cub->img.img_ptr, 0, 0);
	return (0);
}

int	key_hook(int keycode, void *pram)
{
	t_cub	*cub;

	cub = (t_cub *)pram;
	if (keycode == ESC)
		exit(0);
	if (keycode != ESC && keycode != W && keycode != A && keycode != S
		&& keycode != D)
		return (1);
		//why
	if (player_move(cub, keycode) == 1)
		exit (0);
	return (0);
}
