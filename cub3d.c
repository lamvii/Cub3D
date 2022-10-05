/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaamaou <rnaamaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:41:18 by ael-idri          #+#    #+#             */
/*   Updated: 2022/10/05 15:05:24 by rnaamaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int	loop_hook(void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	mlx_clear_window(cub->mlx_p, cub->mlx_w);
	draw_mmap(cub);
	return (0);
}
//protect
void	img_pixel_put(t_img img, int x, int y, int color)
{
	img.addr[x + (y * CUBWIDTH)] = color;
}

void	setup_player(t_cub *cub)
{
	cub->px = cub->data->px + 0.5;
	cub->py = cub->data->py + 0.5;
	cub->data->map[cub->data->py][cub->data->px] = '0';
}

void	setup_cub(t_cub	*cub, t_data *data)
{
	cub->data = data;
	cub->mlx_p = mmlx_init();
	//setup colors
	setup_player(cub);
	cub->mlx_w = mmlx_new_window(cub->mlx_p, CUBWIDTH, CUBHIGHT, "Cube3D");
	cub->img.img_ptr = mmlx_new_image(cub->mlx_p, CUBWIDTH, CUBWIDTH);
	cub->img.addr = mmlx_img_ptr(cub);
	draw_mmap(cub);
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
	// while (data.map[i])
	// {
	// 	printf("|%s|\n", data.map[i]);
	// 	i++;
	// }
	draw_mmap(&cub);
	movement(&cub);
	mlx_loop_hook(cub.mlx_p,loop_hook,&cub);
	mlx_loop(&cub.mlx_p);

	// free__tab(&data.o_map);
	// free(&data.map);
	// free(data.no);
	// free(data.ea);
	// free(data.we);
	// free(data.so);
	return (0);
}
