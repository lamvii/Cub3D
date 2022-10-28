/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vert_intersection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-idri <ael-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:33:37 by ael-idri          #+#    #+#             */
/*   Updated: 2022/10/28 15:34:17 by ael-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_point	vertical_intersection_right(t_cub cub, double alpha)
{
	t_point	intersection;
	t_point	variant_xy;
	int		flag;

	intersection = (t_point)
	{(1 - fmod(cub.player.x, 1)) * tan(alpha) + cub.player.y,
		(int)cub.player.x + 1};
	variant_xy = (t_point){tan(alpha), 1};
	flag = 1;
	while (flag)
	{
		if (is_outside_map((int)intersection.y,
				(int)intersection.x, cub.data->mhight, cub.data->mwidth))
			return (cub.player);
		if (cub.data->map[(int)intersection.y][(int)intersection.x] == '1')
		{
			flag = 0;
			continue ;
		}
		intersection.y += variant_xy.y;
		intersection.x += variant_xy.x;
	}
	return (intersection);
}

t_point	vertical_intersection_left(t_cub cub, double alpha)
{
	t_point	intersection;
	t_point	variant_xy;
	int		flag;

	intersection = (t_point){-fmod(cub.player.x, 1) * tan(alpha) + cub.player.y,
		(int)cub.player.x};
	variant_xy = (t_point){-tan(alpha), -1};
	flag = 1;
	while (flag)
	{
		if (is_outside_map((int)intersection.y,
				(int)intersection.x - 1, cub.data->mhight, cub.data->mwidth))
			return (cub.player);
		if (cub.data->map[(int)intersection.y][(int)intersection.x - 1] == '1')
		{
			flag = 0;
			break ;
		}
		intersection.y += variant_xy.y;
		intersection.x += variant_xy.x;
	}
	return (intersection);
}

t_point	vertical_intersection(t_cub cub, double alpha, double *distance)
{
	t_point	vertical;

	if (cos(alpha) == 0)
	{
		vertical = cub.player;
		*distance = INFINITY;
	}
	if (cos(alpha) > 0)
		vertical = vertical_intersection_right(cub, alpha);
	else
		vertical = vertical_intersection_left(cub, alpha);
	if (vertical.x - cub.player.x == 0)
		*distance = INFINITY;
	else
		*distance = (vertical.x - cub.player.x) / cos(alpha);
	return (vertical);
}

t_point	find_intersection(t_cub *cub, double alpha, double *distance)
{
	t_point	horizontal;
	t_point	vertical;
	double	ver_dist;
	double	hor_dist;

	horizontal = horizontal_intersection(*cub, alpha, &hor_dist);
	vertical = vertical_intersection(*cub, alpha, &ver_dist);
	if (hor_dist <= ver_dist)
	{
		cub->flag = HORI;
		return (*distance = hor_dist, horizontal);
	}
	cub->flag = VERT;
	return (*distance = ver_dist, vertical);
}
