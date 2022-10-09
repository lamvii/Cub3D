/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-idri <ael-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:59:12 by rnaamaou          #+#    #+#             */
/*   Updated: 2022/10/09 17:56:08 by ael-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	ft_right_left(int keycode, t_cub *cub)
// {
// 	if (keycode == A)
// 		return (-1);
// 	if (keycode == D)
// 		return (1);
// 	return (0);
// }

void	ft_forward_back(int keycode, t_cub *cub)
{
	if (keycode == W)
	{
		cub->px += cos(-2 * M_PI + cub->data->rot_angle) * cub->mstep;
		cub->py += sin(-2 * M_PI + cub->data->rot_angle) * cub->mstep;
	}
	if (keycode == S)
	{
		cub->px -= cos(-2 * M_PI + cub->data->rot_angle) * cub->mstep;
		cub->py -= sin(-2 * M_PI + cub->data->rot_angle) * cub->mstep;
	}

}

// int	ft_hit_wall(t_cub *cub, int keycode)
// {
// 	int	x;
// 	int	y;

// 	x = cub->px + ft_right_left(keycode);
// 	y = cub->py + ft_forward_back(keycode);
// 	if (cub->data->map[y][x]  == '1')
// 		return (1);
// 	return (0);
// }

void	player_move(t_cub *cub, int keycode)
{
	// int		hit;

	// hit = ft_hit_wall(cub, keycode);
	// if (hit == 1)
	// 	return ;
	// cub->px += ft_right_left(keycode, cub);
	ft_forward_back(keycode, cub);
	mlx_clear_window(cub->mlx_p, cub->mlx_w);
	mlx_update_image(cub);
	draw_mmap(cub);
	mlx_put_image_to_window(cub->mlx_p, cub->mlx_w, cub->img.img_ptr, 0, 0);
}

void	rotate_player(t_cub *cub, int keycode)
{
	if (keycode == ARROW_L)
		cub->data->rot_angle -= cub->rstep;
	else
		cub->data->rot_angle += cub->rstep;
	mlx_clear_window(cub->mlx_p, cub->mlx_w);
	mlx_update_image(cub);
	draw_mmap(cub);
	mlx_put_image_to_window(cub->mlx_p, cub->mlx_w, cub->img.img_ptr, 0, 0);
}

int	key_hook(int keycode, void *pram)
{
	t_cub	*cub;

	cub = (t_cub *)pram;
	if (keycode == ESC)
		exit(0);
	if (keycode == W || keycode == A || keycode == S
		|| keycode == D)
		player_move(cub, keycode);
	if (keycode == ARROW_L || keycode == ARROW_R)
		rotate_player(cub, keycode);
	return (0);
}
