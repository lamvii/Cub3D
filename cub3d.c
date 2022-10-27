/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-idri <ael-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:41:18 by ael-idri          #+#    #+#             */
/*   Updated: 2022/10/27 16:34:46 by ael-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//protect
void	img_pixel_put(t_img img, int x, int y, int color)
{
	if (x > CUBWIDTH || y > CUBHIGHT || x < 0 || y < 0)
		return ;
		img.addr[x + (y * CUBWIDTH)] = color;
}

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
	// puts("hh");
	setup_img(cub);
	// puts("hh");
	setup_color(cub->img.endian, cub->ceilling.rgb, cub->data->c);
	setup_color(cub->img.endian, cub->floor.rgb, cub->data->f);
	cub->mlx_w = mmlx_new_window(cub->mlx_p, CUBWIDTH, CUBHIGHT, "Cube3D");
	// puts("hh");
	setup_texture(cub);
	draw_rays(*cub);
	// puts("hh");
	draw_mmap(cub);
	// puts("hh");
	mlx_put_image_to_window(cub->mlx_p, cub->mlx_w, cub->img.img_ptr, 0, 0);
}

int	main(int ac, char **av)
{
	t_data	data;
	t_cub	cub;

	if (ac != 2)
	{
		write (2, "Error invalide arg\n", 20);
		return (1);
	}
	if (!check_map(av[1], &data))
		return (1);
	setup_cub(&cub, &data);
	mlx_hook(cub.mlx_w, 2, 0, key_hook, &cub);
	mlx_loop(&cub.mlx_p);
	// free__tab(&data.o_map);
	// free(&data.map);
	// free(data.no);
	// free(data.ea);
	// free(data.we);
	// free(data.so);
	return (0);
}