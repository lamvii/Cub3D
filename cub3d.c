/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-idri <ael-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:41:18 by ael-idri          #+#    #+#             */
/*   Updated: 2022/10/11 18:39:53 by ael-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//protect
void	img_pixel_put(t_img img, int x, int y, int color)
{
	img.addr[x + (y * CUBWIDTH)] = color;
}

void	setup_player(t_cub *cub)
{
	cub->player.x = cub->data->px + 0.5;
	cub->player.y = cub->data->py + 0.5;
	cub->rstep = (M_PI / 180) * 10;
	cub->mstep = 0.3;
	cub->data->map[cub->data->py][cub->data->px] = '0';
}

void	setup_img(t_cub *cub)
{
	cub->img.img_ptr = mmlx_new_image(cub->mlx_p, CUBWIDTH, CUBWIDTH);
	cub->img.addr = mmlx_get_data_addr(cub);
}

void	setup_cub(t_cub	*cub, t_data *data)
{
	cub->data = data;
	cub->mlx_p = mmlx_init();
	cub->fov = 60 * (M_PI / 180);
	cub->rayangle = cub->fov / CUBWIDTH;
	// setup_color(cub);
	setup_player(cub);
	setup_img(cub);
	cub->mlx_w = mmlx_new_window(cub->mlx_p, CUBWIDTH, CUBHIGHT, "Cube3D");
	draw_mmap(cub);
	draw_rays(*cub);
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