/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-idri <ael-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:22:42 by ael-idri          #+#    #+#             */
/*   Updated: 2022/10/31 16:39:54 by ael-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	setup_player(t_cub *cub)
{
	cub->player.x = cub->data->px + 0.5;
	cub->player.y = cub->data->py + 0.5;
	cub->rstep = (M_PI / 180) * 10;
	cub->mstep = 0.5;
	cub->data->map[cub->data->py][cub->data->px] = '0';
}

void	setup_img(t_cub *cub)
{
	cub->img.img_ptr = mmlx_new_image(cub->mlx_p, CUBWIDTH, CUBWIDTH);
	cub->img.addr = mmlx_get_data_addr(cub);
}

void	setup_color(int endian, unsigned char rgb[4], int color[4])
{
	if (!endian)
	{
		rgb[0] = (unsigned char)color[2];
		rgb[1] = (unsigned char)color[1];
		rgb[2] = (unsigned char)color[0];
		rgb[3] = 0;
	}
	else
	{
		rgb[0] = 0;
		rgb[1] = (unsigned char)color[0];
		rgb[2] = (unsigned char)color[1];
		rgb[3] = (unsigned char)color[2];
	}
}

void	setup_cub(t_cub	*cub, t_data *data)
{
	cub->data = data;
	cub->mlx_p = mmlx_init();
	cub->fov = 60 * (M_PI / 180);
	cub->rayangle = cub->fov / CUBWIDTH;
	cub->dist_projection_plane = (CUBWIDTH / 2) / tan(cub->fov / 2);
	setup_player(cub);
	setup_img(cub);
	setup_color(cub->img.endian, cub->ceilling.rgb, cub->data->c);
	setup_color(cub->img.endian, cub->floor.rgb, cub->data->f);
	cub->mlx_w = mmlx_new_window(cub->mlx_p, CUBWIDTH, CUBHIGHT, "Cube3D");
	setup_texture(cub);
	draw_map(*cub);
	draw_mmap(cub);
	mmlx_put_image_to_window(cub->mlx_p, cub->mlx_w,
		cub->img.img_ptr, (t_point){0, 0});
}
