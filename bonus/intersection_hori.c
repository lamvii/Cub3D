/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_hori.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-idri <ael-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:31:38 by ael-idri          #+#    #+#             */
/*   Updated: 2022/10/28 15:37:15 by ael-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_outside_map(int i, int j, int hight, int width)
{
	if (i < 0 || j < 0 || i >= hight || j >= width)
		return (true);
	return (false);
}

t_point	horizontal_intersection_up(t_cub cub, double alpha)
{
	t_point	intersection;
	t_point	variant_xy;
	int		flag;

	intersection = (t_point){(int)cub.player.y,
		-fmod(cub.player.y, 1) / tan(alpha) + cub.player.x};
	variant_xy = (t_point){1, -1 / tan(alpha)};
	flag = 1;
	while (flag)
	{
		if (is_outside_map((int)intersection.y - 1,
				(int)intersection.x, cub.data->mhight, cub.data->mwidth))
			return (cub.player);
		if (cub.data->map[(int)intersection.y - 1][(int)intersection.x] == '1')
		{
			flag = 0;
			continue ;
		}
		intersection.y -= variant_xy.y;
		intersection.x += variant_xy.x;
	}
	return (intersection);
}

t_point	horizontal_intersection_down(t_cub cub, double alpha)
{
	t_point	intersection;
	t_point	variant_xy;
	int		flag;

	intersection = (t_point){(int)cub.player.y + 1,
		(1 - fmod(cub.player.y, 1)) / tan(alpha) + cub.player.x};
	variant_xy = (t_point){1, 1 / tan(alpha)};
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

t_point	horizontal_intersection(t_cub cub, double alpha, double *distance)
{
	t_point	horizontal;

	if (sin(alpha) == 0)
	{
		horizontal = cub.player;
		*distance = INFINITY;
	}
	else if (sin(alpha) < 0)
		horizontal = horizontal_intersection_up(cub, alpha);
	else
		horizontal = horizontal_intersection_down(cub, alpha);
	if (horizontal.y - cub.player.y == 0)
		*distance = INFINITY;
	else
		*distance = (horizontal.y - cub.player.y) / sin(alpha);
	return (horizontal);
}
