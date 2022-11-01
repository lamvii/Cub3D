/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaamaou <rnaamaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:41:18 by ael-idri          #+#    #+#             */
/*   Updated: 2022/11/01 18:49:54 by rnaamaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_hook(int keycode, void *pram)
{
	t_cub	*cub;

	cub = (t_cub *)pram;
	if (keycode == ESC)
		exit_cub(cub);
	if (keycode == W || keycode == A || keycode == S
		|| keycode == D || keycode == ARROW_L || keycode == ARROW_R)
		player_move(cub, keycode);
	return (0);
}

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

int	rendering_frames(void	*data)
{
	t_cub	*cub;

	cub = (t_cub *)data;
	if (cub->left)
		move_c(cub, 'l');
	if (cub->right)
		move_c(cub, 'r');
	if (cub->up)
		move_c(cub, 'u');
	if (cub->down)
		move_c(cub, 'd');
	if (cub->ro_left)
	{
		cub->data->rot_angle -= cub->rstep;
		frame(cub);
	}
	if (cub->ro_right)
	{
		cub->data->rot_angle += cub->rstep;
		frame(cub);
	}
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
	// mlx_hook(cub.mlx_w, 2 , 0, key_hook, &cub);
	mlx_hook(cub.mlx_w, 2, 0, key_press, &cub);
	mlx_hook(cub.mlx_w, 3, 0, key_release, &cub);
	mlx_hook(cub.mlx_w, 17, 0, exit_cub, &cub);
	mlx_loop_hook(cub.mlx_p, &rendering_frames, &cub);
	mlx_loop(&cub.mlx_p);
	return (0);
}
