/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-idri <ael-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 20:02:31 by rnaamaou          #+#    #+#             */
/*   Updated: 2022/10/25 21:52:23 by ael-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	rendering_texture(t_cub cub, int len , int *i , int ray_id)
// { 
// 	double	step;
// 	double	y;

// 	y = 0;
// 	cub.texture_offset = cub.texture_offset * cub.wall_no.width;
// 	step = cub.wall_no.height / cub.wall_hight;
// 	printf("width = %d, hight= %d, offset= %f step =%f\n", cub.wall_no.width,cub.wall_no.height,cub.texture_offset, step);
// 	while (*i < len)
// 	{
// 		img_pixel_put(cub.img, ray_id, *i, cub.wall_no.addr[(int)cub.texture_offset + (int)y * cub.wall_no.width]);
// 		y = y + step;
// 		(*i)++;
// 	}
// }