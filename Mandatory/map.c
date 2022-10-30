/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaamaou <rnaamaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:56:07 by ael-idri          #+#    #+#             */
/*   Updated: 2022/10/30 17:47:50 by rnaamaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_ray(t_cub cub, t_point intersection)
{
	put_line(cub, (t_point){cub.player.y * M_TILE, cub.player.x * M_TILE},
		(t_point){intersection.y * M_TILE, intersection.x * M_TILE});
}

void	rendring_walls(t_cub cub, int ray_id, double ray_distance)
{
	int		wall_hight;
	int		skyhight;
	int		len;
	int		i;

	wall_hight = cub.dist_projection_plane
		/ (ray_distance * cos(cub.fov / 2 - (ray_id * cub.rayangle)));
	cub.wall_hight = wall_hight;
	if (wall_hight > CUBHIGHT)
		wall_hight = CUBHIGHT;
	skyhight = (CUBHIGHT - wall_hight) / 2;
	i = -1;
	while (++i <= skyhight)
		img_pixel_put(cub.img, ray_id, i, cub.ceilling.color);
	len = CUBHIGHT / 2 + wall_hight / 2;
	rendering_texture(cub, len, ray_id, &i);
	while (i < CUBHIGHT)
	{
		img_pixel_put(cub.img, ray_id, i, cub.floor.color);
		i++;
	}
}

void	draw_map(t_cub cub)
{
	t_point	intersection;
	double	ray_distance;
	int		ray_id;
	double	alpha;

	ray_id = 0;
	while (ray_id < CUBWIDTH)
	{
		alpha = fmod(cub.data->rot_angle
				- cub.fov / 2 + ray_id * cub.rayangle, 2 * M_PI);
		if (alpha < 0)
			alpha = alpha + 2 * M_PI;
		intersection = find_intersection(&cub, alpha, &ray_distance);
		if (cub.flag == HORI)
			cub.texture_offset = intersection.x;
		else
			cub.texture_offset = intersection.y;
		rendring_walls(cub, ray_id, ray_distance);
		//draw_ray(cub, intersection);
		ray_id++;
	}
}
