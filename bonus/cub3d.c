/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaamaou <rnaamaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:41:18 by ael-idri          #+#    #+#             */
/*   Updated: 2022/11/01 11:58:53 by rnaamaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int keycode, void *pram)
{
	t_cub	*cub;

	cub = (t_cub *)pram;
	if (keycode == ESC)
		exit_cub(cub);
	if (keycode == A)
		cub->left = 1;
	if (keycode == D)
		cub->right = 1;
	if (keycode == W)
		cub->up = 1;
	if (keycode == S)
		cub->down = 1;
	if (keycode == ARROW_L)
		cub->ro_left = 1;
	if (keycode == ARROW_R)
		cub->ro_right = 1;
	return (0);
}

int	key_release(int keycode, void *pram)
{
	t_cub	*cub;

	cub = (t_cub *)pram;
	if (keycode == A)
		cub->left = 0;
	if (keycode == D)
		cub->right = 0;
	if (keycode == W)
		cub->up = 0;
	if (keycode == S)
		cub->down = 0;
	if (keycode == ARROW_L)
		cub->ro_left = 0;
	if (keycode == ARROW_R)
		cub->ro_right = 0;
	return (0);
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

int	rendering_frames(void	*data)
{
	t_cub	*cub;

	cub = (t_cub *)data;
	if (cub->left)
		move_left(cub);
	if (cub->right)
		 move_right(cub);
	if (cub->up)
		 move_forward(cub);
	if (cub->down)
		 move_back(cub);
	if (cub->ro_left)
		cub->data->rot_angle -= cub->rstep;
	if (cub->ro_right)
		cub->data->rot_angle += cub->rstep;
	mlx_clear_window(cub->mlx_p, cub->mlx_w);
	mlx_update_image(cub);
	draw_map(*cub);
	draw_mmap(cub);
	mmlx_put_image_to_window(cub->mlx_p, cub->mlx_w,
		cub->img.img_ptr, (t_point){0, 0});
	return (0);
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
	if ((CUBHIGHT > 1800 || CUBHIGHT < 300)
		|| (CUBWIDTH > 5120 || CUBWIDTH < 300))
	{
		ft_putstr_fd("Erorr window size\n", 2);
		exit (1);
	}
	if (!check_map(av[1], &data))
		return (1);
	setup_cub(&cub, &data);
	mlx_hook(cub.mlx_w, 2, 0, key_press, &cub);
	mlx_hook(cub.mlx_w, 3, 0, key_release, &cub);
	mlx_hook(cub.mlx_w, 17, 0, exit_cub, &cub);
	mlx_loop_hook(cub.mlx_p, &rendering_frames, &cub);
	mlx_loop(&cub.mlx_p);
	return (0);
}
