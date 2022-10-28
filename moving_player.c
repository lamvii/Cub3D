/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-idri <ael-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:59:12 by rnaamaou          #+#    #+#             */
/*   Updated: 2022/10/28 15:46:38 by ael-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_left(t_cub *cub)
{
	t_point	intersection;
	double	ray_distance;

	intersection = find_intersection(cub,
			fmod(-M_PI_2 + cub->data->rot_angle, 2 * M_PI), &ray_distance);
	if (cub->mstep < ray_distance)
	{
		cub->player.x -= cos(M_PI_2 + cub->data->rot_angle) * cub->mstep;
		cub->player.y -= sin(M_PI_2 + cub->data->rot_angle) * cub->mstep;
		return ;
	}
	if (ray_distance <= 0.01)
		return ;
	ray_distance -= 0.01;
	cub->player.x -= cos(M_PI_2 + cub->data->rot_angle) * ray_distance;
	cub->player.y -= sin(M_PI_2 + cub->data->rot_angle) * ray_distance;
}

void	move_right(t_cub *cub)
{
	t_point	intersection;
	double	ray_distance;

	intersection = find_intersection(cub,
			fmod(M_PI_2 + cub->data->rot_angle, 2 * M_PI), &ray_distance);
	if (cub->mstep < ray_distance)
	{
		cub->player.x += cos(M_PI_2 + cub->data->rot_angle) * cub->mstep;
		cub->player.y += sin(M_PI_2 + cub->data->rot_angle) * cub->mstep;
		return ;
	}
	if (ray_distance <= 0.01)
		return ;
	ray_distance -= 0.01;
	cub->player.x += cos(M_PI_2 + cub->data->rot_angle) * ray_distance;
	cub->player.y += sin(M_PI_2 + cub->data->rot_angle) * ray_distance;
}

void	move_forward(t_cub *cub)
{
	t_point	intersection;
	double	ray_distance;

	intersection = find_intersection(cub,
			fmod(cub->data->rot_angle, 2 * M_PI), &ray_distance);
	if (cub->mstep < ray_distance)
	{
		cub->player.x += cos(cub->data->rot_angle) * cub->mstep;
		cub->player.y += sin(cub->data->rot_angle) * cub->mstep;
		return ;
	}
	if (ray_distance <= 0.01)
		return ;
	ray_distance -= 0.01;
	cub->player.x += cos(cub->data->rot_angle) * ray_distance;
	cub->player.y += sin(cub->data->rot_angle) * ray_distance;
}

void	move_back(t_cub *cub)
{
	t_point	intersection;
	double	ray_distance;

	intersection = find_intersection(cub,
			fmod(cub->data->rot_angle - M_PI, 2 * M_PI), &ray_distance);
	if (cub->mstep < ray_distance)
	{
		cub->player.x -= cos(cub->data->rot_angle) * cub->mstep;
		cub->player.y -= sin(cub->data->rot_angle) * cub->mstep;
		return ;
	}
	if (ray_distance <= 0.01)
		return ;
	ray_distance -= 0.01;
	cub->player.x -= cos(cub->data->rot_angle) * ray_distance;
	cub->player.y -= sin(cub->data->rot_angle) * ray_distance;
}

void	player_move(t_cub *cub, int keycode)
{
	if (keycode == A)
		move_left(cub);
	if (keycode == D)
		move_right(cub);
	if (keycode == W)
		move_forward(cub);
	if (keycode == S)
		move_back(cub);
	if (keycode == ARROW_L)
		cub->data->rot_angle -= cub->rstep;
	if (keycode == ARROW_R)
		cub->data->rot_angle += cub->rstep;
	mlx_clear_window(cub->mlx_p, cub->mlx_w);
	mlx_update_image(cub);
	draw_map(*cub);
	draw_mmap(cub);
	mmlx_put_image_to_window(cub->mlx_p, cub->mlx_w, cub->img.img_ptr, 0, 0);
}
