/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _mlx.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-idri <ael-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:26:45 by ael-idri          #+#    #+#             */
/*   Updated: 2022/10/25 21:42:07 by ael-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	*mmlx_init(void)
{
	void	*mlx_p;

	mlx_p = mlx_init();
	if (!mlx_p)
	{
		ft_putstr_fd("Error :mlx error\n", 2);
		exit(1);
	}
	return (mlx_p);
}

void	*mmlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title)
{
	void	*mlx_w;

	mlx_w = mlx_new_window(mlx_ptr, size_x, size_y, title);
	if (!mlx_w)
	{
		ft_putstr_fd("Error :mlx error\n", 2);
		exit(1);
	}
	return (mlx_w);
}

void	*mmlx_new_image(void *mlx_ptr, int size_x, int size_y)
{
	void	*img_ptr;

	img_ptr = mlx_new_image(mlx_ptr, size_x, size_y);
	if (!img_ptr)
	{
		ft_putstr_fd("Error :mlx error\n", 2);
		exit(1);
	}
	return (img_ptr);
}

int	*mmlx_get_data_addr( t_cub *cub)
{
	int	*img_addr;

	img_addr = (int *) mlx_get_data_addr(cub->img.img_ptr,
			&cub->img.bpp, &cub->img.line_len, &cub->img.endian);
	if (!img_addr)
	{
		ft_putstr_fd("Error :mlx error\n", 2);
		exit(1);
	}
	return (img_addr);
}

void	mlx_update_image(t_cub *cub)
{
	mlx_destroy_image(cub->mlx_p, cub->img.img_ptr);
	cub->img.img_ptr = mmlx_new_image(cub->mlx_p, CUBWIDTH, CUBWIDTH);
	cub->img.addr = (int *)mmlx_get_data_addr(cub);
}
