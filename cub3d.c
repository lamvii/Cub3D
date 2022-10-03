/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-idri <ael-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:41:18 by ael-idri          #+#    #+#             */
/*   Updated: 2022/10/03 14:23:47 by ael-idri         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_data	data;
	t_cub	cub;
	int		i = 0;

	if (ac != 2)
	{
		write (2, "Error invalide arg\n", 20);
		return (1);
	}
	if (!check_map(av[1], &data))
		return (1);
	while (data.map[i])
	{
		printf("|%s|\n", data.map[i]);
		i++;
	}
	printf("hhh\n");
	cub.data = &data;
	cub.mlx_p = mlx_init();
	cub.mlx_w = mlx_new_window(cub.mlx_p, CUBWIDTH, CUBHIGHT, "Cube3D");
	// import_texture(&cub);
	draw_mmap(&cub);
	// draw_ractangle(&cub, 32, 32, 0x34e2e2);
	mlx_loop(cub.mlx_p);
	free__tab(&data.o_map);
	free(&data.map);
	free(data.no);
	free(data.ea);
	free(data.we);
	free(data.so);
	return (0);
}
