/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-idri <ael-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:19:43 by ael-idri          #+#    #+#             */
/*   Updated: 2022/10/05 09:41:15 by ael-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_ractangle(t_cub *cub, int posy, int posx, int size, int color)
{
	int	i;
	int	j;

	if ((int)cub->py - 10 >= 0)
		posy -= ((int)cub->py - 10) * 10;
	if ((int)cub->px - 10 >= 0)
		posx -= ((int)cub->py - 10) * 10;
	i = posy;
	j = posx;
	printf("posx = %d posy= %d\n",posx, posy);
	while (posy <= i + size)
	{
		posx = j;
		while (posx <= j + size)
		{
			img_pixel_put(cub->img, posx, posy, color);
			posx++;
		}
		posy++;
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
				draw_ractangle(cub, i * 10, j * 10, 10, 0x555753);
	}
	draw_ractangle(cub, ((int)cub->py * 10) + ((int)fmod(cub->py, 1) * 10),
		((int)cub->px * 10) + ((int)fmod(cub->px, 1) * 10), 4, 0xFF);
}
