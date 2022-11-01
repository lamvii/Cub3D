/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaamaou <rnaamaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:33:29 by rnaamaou          #+#    #+#             */
/*   Updated: 2022/11/01 18:40:43 by rnaamaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	frame(t_cub	*cub)
{
	mlx_clear_window(cub->mlx_p, cub->mlx_w);
	mlx_update_image(cub);
	draw_map(*cub);
	draw_mmap(cub);
	mmlx_put_image_to_window(cub->mlx_p, cub->mlx_w,
		cub->img.img_ptr, (t_point){0, 0});
}

void	move_c(t_cub *cub, char c)
{
	if (c == 'l')
	{
		move_left(cub);
		frame(cub);
	}
	if (c == 'r')
	{
		move_right(cub);
		frame(cub);
	}
	if (c == 'u')
	{
		move_forward(cub);
		frame(cub);
	}
	if (c == 'd')
	{
		move_back(cub);
		frame(cub);
	}
}

int	exit_cub(void	*data)
{
	t_cub	*cub;

	cub = (t_cub *)data;
	free__tab(&cub->data->o_map);
	free__tab(&cub->data->map);
	free(cub->data->no);
	free(cub->data->ea);
	free(cub->data->we);
	free(cub->data->so);
	exit(0);
	return (0);
}
