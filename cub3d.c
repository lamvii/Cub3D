/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaamaou <rnaamaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:41:18 by ael-idri          #+#    #+#             */
/*   Updated: 2022/10/05 14:00:08 by rnaamaou         ###   ########.fr       */
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

void	setup_cub(t_cub	*cub, t_data *data)
{
	cub->data = data;
	cub->mlx_p = mlx_init();
	if (!cub->mlx_p)
	{
		perror("Error");
		exit(1);
	}
	//setup colors
	cub->px = data->px + 0.5;
	cub->py = data->py + 0.5;
	// cub->data->map[data->py][data->px] = '0';
	cub->mlx_w = mlx_new_window(cub->mlx_p, CUBWIDTH, CUBHIGHT, "Cube3D");
	cub->img.img_ptr = mlx_new_image(cub->mlx_p, CUBWIDTH, CUBWIDTH);
	if (!cub->img.img_ptr)
	{
		printf("error img ptr\n");
		exit(1);
	}
	cub->img.addr = (int *)mlx_get_data_addr(cub->img.img_ptr, &cub->img.bpp,
			&cub->img.line_len, &cub->img.endian);
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
