/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-idri <ael-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:47:14 by ael-idri          #+#    #+#             */
/*   Updated: 2022/10/09 21:20:36 by ael-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "math.h"
int main() {
	// void *mlx = mlx_init();
	// void *win = mlx_new_window(mlx, 1000, 1000, "mlx");
	// void *img = mlx_new_image(mlx, 1000, 1000);
	// int e, ps, sl;
	// int *buffer = (int*)mlx_get_data_addr(img, &ps, &sl, &e);
	// int x = 0;
	// int y = 0;
	// while (y < 1000) {
	// 	while (x < 1000)
	// 	{
	// 		buffer[x + (y * 1000)] = 0xFF00;
	// 		x++;
	// 	}
	// 	x = 0;
	// 	y++;
	// }
	// mlx_put_image_to_window(mlx, win, img, 0, 0);
	// mlx_loop(mlx);
	double i = 18.2356;
	printf ("%d--- %d\n", 18 * 10 + (int)(fmod(i, 1) * 10), );
}
