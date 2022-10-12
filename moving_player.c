/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-idri <ael-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:59:12 by rnaamaou          #+#    #+#             */
/*   Updated: 2022/10/12 19:58:11 by ael-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_right_left(int keycode, t_cub *cub)
{
	t_point	intersection;
	double	ray_distance;

	if (keycode == D)
	{
		intersection = find_intersection(*cub,
				fmod(M_PI_2 + cub->data->rot_angle, 2 * M_PI), &ray_distance);
		printf("%f----%f\n",cub->mstep, ray_distance);
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
	if (keycode == A)
	{
		intersection = find_intersection(*cub,
				fmod(-M_PI_2 + cub->data->rot_angle, 2 * M_PI), &ray_distance);
		printf("%f----%f\n",cub->mstep, ray_distance);
		if (cub->mstep < ray_distance )
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
}

void	move_forward_back(int keycode, t_cub *cub)
{
	t_point	intersection;
	double	ray_distance;

	if (keycode == W)
	{
	intersection = find_intersection(*cub, fmod(cub->data->rot_angle, 2 * M_PI), &ray_distance);
		printf("%f----%f\n",cub->mstep, ray_distance);
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
	if (keycode == S)
	{
	intersection = find_intersection(*cub, fmod(cub->data->rot_angle - M_PI, 2 * M_PI), &ray_distance);
		printf("%f----%f\n",cub->mstep, ray_distance);
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
	// move_switch_direction(keycode, cub);
	ft_right_left(keycode, cub);
	move_forward_back(keycode, cub);
	mlx_clear_window(cub->mlx_p, cub->mlx_w);
	mlx_update_image(cub);
	draw_mmap(cub);
	draw_rays(*cub);
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
	draw_rays(*cub);
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
