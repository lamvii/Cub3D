/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-idri <ael-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:19:43 by ael-idri          #+#    #+#             */
/*   Updated: 2022/10/09 22:47:38 by ael-idri         ###   ########.fr       */
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

void	put_line(t_cub *cub, t_point player, t_point end)
{
	t_point	var;
	float	dx;
	float	dy;
	float	steps;
	int		i;

	displacement(*cub, &player.x, 'x');
	displacement(*cub, &player.y, 'y');
	displacement(*cub, &end.x, 'x');
	displacement(*cub, &end.y, 'y');
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
		img_pixel_put(cub->img, round(var.x), round(var.y), 0xFF00);
		var.x += dx;
		var.y += dy;
		i++;
	}
}

// need to be focused on player
void	draw_mmap(t_cub *cub)
{
	t_point	var;
	t_point	end;
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
	end = (t_point){sin(-2 * M_PI + cub->data->rot_angle) * 200 + cub->player.y * M_TILE,
		cos(-2 * M_PI + cub->data->rot_angle) * 200 + cub->player.x * M_TILE};
	put_line(cub, (t_point){cub->player.y * M_TILE, cub->player.x * M_TILE}, end);
}
