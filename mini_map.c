/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-idri <ael-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:19:43 by ael-idri          #+#    #+#             */
/*   Updated: 2022/10/09 17:48:35 by ael-idri         ###   ########.fr       */
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

void put_line(t_cub *cub, t_point player, t_point end)
{  
    float x, y,dx,dy,steps;
	int i;
	if ((int)cub->px - 10 >= 0)
	{
		player.x -= ((int)cub->px - 10) * M_TILE;
		end.x -= ((int)cub->px - 10) * M_TILE;
	}
	if ((int)cub->py - 10 >= 0)
	{
		player.y -= ((int)cub->py - 10) * M_TILE;
		end.y -= ((int)cub->py - 10) * M_TILE;
	}
    dx = (float)(end.x - player.x);
    dy = (float)(end.y - player.y);
    steps = fmax(fabs(dy), fabs(dx));
    dx = dx/steps;  
    dy = dy/steps;  
    x = player.x;
    y = player.y;
    i = 1;  
    while(i<= steps)  
    {  
		img_pixel_put(cub->img, round(x),round(y), 0xFF00);
        x += dx;  
        y += dy;  
        i++;  
	}
}

// need to be focused on player
void	draw_mmap(t_cub *cub)
{
	int	i;
	int	j;
	int	miniwidth;
	int	minihight;
	t_point	player;
	t_point	end;

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
			{
				draw_ractangle(cub, (t_point){i * M_TILE, j * M_TILE}, M_TILE, 0x555753);
			}
	}
	draw_ractangle(cub,
		(t_point){((int)cub->py * M_TILE) + ((int)(fmod(cub->py, 1) * M_TILE)) - 2,
		((int)cub->px * M_TILE) + ((int)(fmod(cub->px, 1) * M_TILE)) - 2}, 4, 0xFF);

	player = (t_point){((int)cub->py * M_TILE) + ((int)(fmod(cub->py, 1) * M_TILE)) ,
		((int)cub->px * M_TILE) + ((int)(fmod(cub->px, 1) * M_TILE)) };
	end = (t_point){sin(-2 * M_PI + cub->data->rot_angle) * 2 + player.y,
		cos(-2 * M_PI + cub->data->rot_angle) * 2 + player.x};
	put_line(cub, player, end);
}
