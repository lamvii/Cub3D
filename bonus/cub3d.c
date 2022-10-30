/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaamaou <rnaamaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:41:18 by ael-idri          #+#    #+#             */
/*   Updated: 2022/10/28 16:21:43 by rnaamaou         ###   ########.fr       */
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
	mlx_hook(cub.mlx_w, 17, 0, exit_cub, &cub);
	mlx_loop(&cub.mlx_p);
	return (0);
}
