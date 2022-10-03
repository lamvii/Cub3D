/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-idri <ael-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:19:43 by ael-idri          #+#    #+#             */
/*   Updated: 2022/10/03 21:43:41 by ael-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_ractangle(t_cub *cub, int posy, int posx, int color)
{
	int	i;
	int	j;

	i = posy;
	j = posx;
	while (posy <= i + 10)
	{
		posx = j;
		while (posx <= j + 10)
		{
			mlx_pixel_put(cub->mlx_p, cub->mlx_w, posx, posy, color);
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

	i = -1;
	while (cub->data->map[++i])
	{
		j = -1;
		while (cub->data->map[i][++j])
		{
			if (cub->data->map[i][j] == '1')
				draw_ractangle(cub, i * 10, j * 10, 0x555753);
			if (is_player(cub->data->map[i][j]))
				draw_ractangle(cub, i * 10, j * 10, 0x34e2e2);
		}
	}
}
