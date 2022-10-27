/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-idri <ael-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:32:48 by ael-idri          #+#    #+#             */
/*   Updated: 2022/10/27 15:55:40 by ael-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rendering_texture(t_cub cub, int len, int ray_id, int *i)
{
	int		pos;
	double	step;
	double	offset_y;

	step = (double)cub.wall_no.height / cub.wall_hight;
	cub.texture_offset = (cub.texture_offset - floor(cub.texture_offset))
		* cub.wall_no.width;
	while (*i < len)
	{
		offset_y = (double)(*i - CUBHIGHT / 2 + cub.wall_hight / 2) * step;
		pos = cub.wall_no.addr[(int)(cub.texture_offset)
			+ (int)offset_y * cub.wall_no.width];
		img_pixel_put(cub.img, ray_id, *i, pos);
		(*i)++;
	}
}
