/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-idri <ael-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:19:43 by ael-idri          #+#    #+#             */
/*   Updated: 2022/10/05 18:23:57 by ael-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_ractangle(t_cub *cub, t_point p, int size, int color)
{
	int	i;
	int	j;

	if ((int)cub->py - 10 >= 0)
		p.y -= ((int)cub->py - 10) * M_TILE;
	if ((int)cub->px - 10 >= 0)
		p.x -= ((int)cub->px - 10) * M_TILE;
	i = p.y;
	j = p.x;
	while (p.y <= i + size)
	{
		p.x = j;
		while (p.x <= j + size)
		{
			img_pixel_put(cub->img, p.x, p.y, color);
			p.x++;
		}
		p.y++;
	}
}

void	draw_rotation_line(t_cub *cub)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = cub->py + (int)(fmod(cub->py, 1) * 10) * M_TILE;
	j = cub->px + (int)(fmod(cub->px, 1) * 10) * M_TILE;
	x = i + 10 * cos()
}

// need to be focused on player
void	draw_mmap(t_cub *cub)
{
	int	i;
	int	j;
	int	miniwidth;
	int	minihight;

	i = (int)cub->py - 10 - 1;
	if (i < -1)
		i = -1;
	j = (int)cub->px - 10 - 1;
	if (j < -1)
		j = -1;
	miniwidth = 22 + j;
	minihight = 22 + i;
	while (++i <= minihight && cub->data->map[i])
	{
		j = (int)cub->px - 10 - 1;
		if (j < -1)
			j = -1;
		while (++j <= miniwidth && cub->data->map[i][j])
			if (cub->data->map[i][j] == '1')
				draw_ractangle(cub, (t_point){i * M_TILE, j * M_TILE}, M_TILE, 0x555753);
	}
	draw_ractangle(cub,
		(t_point){((int)cub->py * M_TILE) + ((int)(fmod(cub->py, 1.0) * M_TILE)) - 5,
		((int)cub->px * M_TILE) + ((int)(fmod(cub->px, 1.0) * M_TILE)) - 5}, 10, 0xFF);
}
