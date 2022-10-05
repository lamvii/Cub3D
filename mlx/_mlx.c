/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _mlx.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-idri <ael-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:26:45 by ael-idri          #+#    #+#             */
/*   Updated: 2022/10/05 14:34:36 by ael-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	*mmlx_init(void)
{
	void	*mlx_p;

	mlx_p = mlx_init();
	if (!mlx_p)
	{
		printf("Error\n");
		exit(1);
	}
	return (mlx_p);
}

void	*mmlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title)
{

}
