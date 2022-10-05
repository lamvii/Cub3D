/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-idri <ael-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:19:43 by ael-idri          #+#    #+#             */
/*   Updated: 2022/10/05 11:59:28 by ael-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_ractangle(t_cub *cub, t_point p, int size, int color)
{
	int	i;
	int	j;

	// printf("%d -- %d\n",p.y,p.x);
	if ((int)cub->py - 10 >= 0)
		p.y -= ((int)cub->py - 10) * 30;
	if ((int)cub->px - 10 >= 0)
		p.x -= ((int)cub->px - 10) * 30;
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
				draw_ractangle(cub, (t_point){i * 30, j * 30}, 30, 0x555753);
	}
	draw_ractangle(cub, (t_point){((int)cub->py * 30) + ((int)(fmod(cub->py, 1.0) * 30)) - 5,
		((int)cub->px * 30) + ((int)(fmod(cub->px, 1.0) * 30)) - 5}, 10, 0xFF);
}
