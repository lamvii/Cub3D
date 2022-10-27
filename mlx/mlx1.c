/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-idri <ael-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:58:30 by rnaamaou          #+#    #+#             */
/*   Updated: 2022/10/27 15:57:02 by ael-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mmlx_destroy_image(void *mlx_ptr, void *img_ptr)
{
	if (!mlx_ptr || !img_ptr)
	{
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
	mlx_destroy_image(mlx_ptr,img_ptr);
}

void	mmlx_put_image_to_window(void *mlx_ptr,
	void *win_ptr, void *img_ptr, int x, int y)
{
	if (!mlx_ptr || !img_ptr || !win_ptr)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, x, y);
}

void	mmlx_destroy_window(void *mlx_ptr,void *img_ptr)
{
	if (!mlx_ptr || !img_ptr)
	{
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
	mlx_destroy_window(mlx_ptr, img_ptr);
}