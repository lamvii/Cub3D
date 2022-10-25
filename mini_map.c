/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-idri <ael-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:19:43 by ael-idri          #+#    #+#             */
/*   Updated: 2022/10/25 21:47:41 by ael-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	displacement(t_cub cub, double *pos, char flag)
{
	if (flag == 'x')
	{
		if ((int)cub.player.x - 10 >= 0)
			*pos -= ((int)cub.player.x - 10) * M_TILE;
	}
	else
	{
		if ((int)cub.player.y - 10 >= 0)
			*pos -= ((int)cub.player.y - 10) * M_TILE;
	}
}

void	draw_ractangle(t_cub *cub, t_point p, int size, int color)
{
	int	i;
	int	j;

	displacement(*cub, &p.y, 'y');
	displacement(*cub, &p.x, 'x');
	i = p.y;
	j = p.x;
	while (p.y <= i + size)
	{
		p.x = j;
		while (p.x <= j + size)
		{
			img_pixel_put(cub->img, p.x, p.y, color);
			p.x = p.x + 1;
		}
		p.y = p.y + 1;
	}
}

void	put_line(t_cub cub, t_point player, t_point end)
{
	t_point	var;
	float	dx;
	float	dy;
	float	steps;
	int		i;

	displacement(cub, &player.x, 'x');
	displacement(cub, &player.y, 'y');
	displacement(cub, &end.x, 'x');
	displacement(cub, &end.y, 'y');
	dx = (float)(end.x - player.x);
	dy = (float)(end.y - player.y);
	steps = fmax(fabs(dy), fabs(dx));
	dx = dx / steps;
	dy = dy / steps;
	var.x = player.x;
	var.y = player.y;
	i = 1;
	while (i <= steps)
	{
		img_pixel_put(cub.img, round(var.x), round(var.y), 0x0000FF);
		var.x += dx;
		var.y += dy;
		i++;
	}
}

// t_point point_to_pixel(t_point point)

// need to be focused on player
void	draw_mmap(t_cub *cub)
{
	t_point	var;
	int		miniwidth;
	int		minihight;

	var = (t_point){(int)cub->player.y - 11, (int)cub->player.x - 11};
	if (var.y < -1)
		var.y = -1;
	if (var.x < -1)
		var.x = -1;
	miniwidth = 22 + var.x;
	minihight = 22 + var.y;
	while (++var.y <= minihight && cub->data->map[(int)var.y])
	{
		var.x = (int)cub->player.x - 10 - 1;
		if (var.x < -1)
			var.x = -1;
		while (++var.x <= miniwidth && cub->data->map[(int)var.y][(int)var.x])
			if (cub->data->map[(int)var.y][(int)var.x] == '1')
				draw_ractangle(cub, (t_point){var.y * M_TILE, var.x * M_TILE},
					M_TILE, 0x555753);
	}
	draw_ractangle(cub, (t_point){(int)(cub->player.y * M_TILE) - 2,
		(int)(cub->player.x * M_TILE) - 2}, 4, 0xFF);
}

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
	// while (++i <= skyhight)
	// 	img_pixel_put(cub.img, ray_id, i, cub.ceilling.color);
	i = CUBHIGHT / 2 - wall_hight / 2;
	if (i < 0)
		i = 0;
	len = CUBHIGHT / 2 + wall_hight / 2;



	double	step;
	int		pos;
	double offset_y;
	printf("wallhight= %f\n",cub.wall_hight);
	step = cub.wall_no.height / cub.wall_hight;
	offset_y = (i - CUBHIGHT / 2 + cub.wall_hight / 2) * step;
	while (i < len)
	{
		// offset_y = (i - CUBHIGHT / 2 + wall_hight / 2) * step;
		// printf("width = %d hight= %d wallhight = %d offsety = %f step= %f pos = %d\n", cub.wall_no.width, cub.wall_no.height, wall_hight, offset_y, step, (int)(cub.texture_offset * cub.wall_no.width + offset_y * cub.wall_no.width));
		// y = i + cub.wall_hight / 2 - CUBHIGHT / 2;
		// d = fmod(data->alpha, 2 * M_PI);
		// if ((int)(cub.texture_offset * cub.wall_no.width + offset_y * cub.wall_no.width) < cub.wall_no.width * cub.wall_no.height)
		pos = cub.wall_no.addr[(int)(cub.texture_offset * cub.wall_no.width) + (int)(offset_y * cub.wall_no.width)];
		// else
			// pos = 0x0000FF;
		img_pixel_put(cub.img, ray_id, i, pos);
		offset_y += step;
		// y +=step;
		i++;
	}

	// cub.texture_offset = cub.texture_offset - floor(cub.texture_offset);
	// printf("width = %d, hight= %d, offset= %f step =%f\n", cub.wall_no.width,cub.wall_no.height,cub.texture_offset, step);
	// while (i < len)
	// {
	// 	y += step;
	// 	img_pixel_put(cub.img, ray_id, i, cub.wall_no.addr[(int)cub.texture_offset * cub.wall_no.width + (int)y * cub.wall_no.width]);
	// 	i++;
	// }
	// rendering_texture(cub, len, &i, ray_id);
	while (i < CUBHIGHT)
	{
		img_pixel_put(cub.img, ray_id, i, cub.floor.color);
		i++;
	}
}

void	draw_rays(t_cub cub)
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
		intersection = find_intersection(&cub, alpha, &ray_distance);
		if (cub.flag == HORI)
			cub.texture_offset = fmod(intersection.x, 1);
		else if (cub.flag == VERT)
			cub.texture_offset = fmod(intersection.y, 1);
		printf ("offset  x=%f\n", cub.texture_offset);
		// printf ("int.x=%f /int.y=%f fleag= %d\n", intersection.x, intersection.y, cub.flag);
		// rendring_walls(cub, ray_id, ray_distance);
		put_line(cub, (t_point){cub.player.y * M_TILE, cub.player.x * M_TILE},
			(t_point){intersection.y * M_TILE, intersection.x * M_TILE});
		ray_id++;
	}
}
