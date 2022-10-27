/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-idri <ael-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:32:48 by ael-idri          #+#    #+#             */
/*   Updated: 2022/10/27 21:26:24 by ael-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	rendering_texture(t_cub cub, int len, int ray_id, int *i)
// {
// 	int		pos;
// 	double	step;
// 	double	offset_y;

// 	step = (double)texture->height / cub.wall_hight;
// 	cub.texture_offset = (cub.texture_offset - floor(cub.texture_offset))
// 		* texture->width;
// 	while (*i < len)
// 	{
// 		offset_y = (double)(*i - CUBHIGHT / 2 + cub.wall_hight / 2) * step;
// 		pos = texture->addr[(int)(cub.texture_offset) +
// 			(int)offset_y * texture->width];
// 		img_pixel_put(cub.img, ray_id, *i, pos);
// 		(*i)++;
// 	}
// }

void	rendering_texture(t_cub cub, int len, int ray_id, int *i)
{
	int		pos;
	double	step;
	double	offset_y;
	double	alpha;
	t_img	*texture;

	texture = NULL;
	alpha = fmod(cub.data->rot_angle
			- cub.fov / 2 + ray_id * cub.rayangle, 2 * M_PI);
	if (alpha < 0)
		alpha = alpha + 2 * M_PI;
	
	if (alpha >= 0 && alpha < M_PI && cub.flag == HORI)
		texture = &cub.wall_so;
	else if (!(alpha >= 0 && alpha < M_PI) && cub.flag == HORI)
		texture = &cub.wall_no;
	else if (alpha >= M_PI_2 && alpha < 1.5 * M_PI)
		texture = &cub.wall_we;
	else
		texture = &cub.wall_ea;
	step = (double)texture->height / cub.wall_hight;
	cub.texture_offset = (cub.texture_offset - floor(cub.texture_offset))
		* texture->width;
	while (*i < len)
	{
		offset_y = (double)(*i - CUBHIGHT / 2 + cub.wall_hight / 2) * step;
		pos = texture->addr[(int)(cub.texture_offset) +
			(int)offset_y * texture->width];
		img_pixel_put(cub.img, ray_id, *i, pos);
		(*i)++;
	}
}
