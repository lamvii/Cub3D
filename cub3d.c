/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaamaou <rnaamaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:41:18 by ael-idri          #+#    #+#             */
/*   Updated: 2022/10/04 15:33:02 by rnaamaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
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
	cub->px = data->px + 0.5;
	cub->py = data->py + 0.5;
	cub->data->map[data->py][data->px] = '0';
	cub->mlx_w = mlx_new_window(cub->mlx_p, CUBWIDTH, CUBHIGHT, "Cube3D");//protect
	cub->img.img_ptr = mlx_new_image(cub->mlx_p, CUBWIDTH, CUBWIDTH);//protect
	cub->img.addr = mlx_get_data_addr(cub->img.img_ptr, &cub->img.bpp,
			&cub->img.line_len, &cub->img.endian);//protect
	draw_mmap(cub);
	mlx_loop(cub->mlx_p);
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

	// free__tab(&data.o_map);
	// free(&data.map);
	// free(data.no);
	// free(data.ea);
	// free(data.we);
	// free(data.so);
	return (0);
}
