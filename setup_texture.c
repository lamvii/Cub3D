/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-idri <ael-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:47:41 by ael-idri          #+#    #+#             */
/*   Updated: 2022/10/27 15:53:11 by ael-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	no_texture(t_cub *cub)
{
	cub->wall_no.img_ptr = mlx_xpm_file_to_image(cub->mlx_p, cub->data->no,
			&cub->wall_no.width, &cub->wall_no.height);
	if (!cub->wall_no.img_ptr)
	{
		perror("unable to load texture");
		exit(1);
	}
	cub->wall_no.addr = (int *)mlx_get_data_addr(cub->wall_no.img_ptr,
			&cub->wall_no.bpp, &cub->wall_no.line_len, &cub->wall_no.endian);
}

void	so_texture(t_cub *cub)
{
	cub->wall_so.img_ptr = mlx_xpm_file_to_image(cub->mlx_p, cub->data->so,
			&cub->wall_so.width, &cub->wall_so.height);
	if (!cub->wall_so.img_ptr)
	{
		perror("unable to load texture");
		exit(1);
	}
	cub->wall_so.addr = (int *)mlx_get_data_addr(cub->wall_so.img_ptr,
			&cub->wall_so.bpp, &cub->wall_so.line_len, &cub->wall_so.endian);
}

void	we_texture(t_cub *cub)
{
	cub->wall_we.img_ptr = mlx_xpm_file_to_image(cub->mlx_p, cub->data->we,
			&cub->wall_we.width, &cub->wall_we.height);
	if (!cub->wall_we.img_ptr)
	{
		perror("unable to load texture");
		exit(1);
	}
	cub->wall_we.addr = (int *)mlx_get_data_addr(cub->wall_we.img_ptr,
			&cub->wall_we.bpp, &cub->wall_we.line_len, &cub->wall_we.endian);
}

void	ea_texture(t_cub *cub)
{
	cub->wall_ea.img_ptr = mlx_xpm_file_to_image(cub->mlx_p, cub->data->ea,
			&cub->wall_ea.width, &cub->wall_ea.height);
	if (!cub->wall_ea.img_ptr)
	{
		perror("unable to load texture");
		exit(1);
	}
	cub->wall_ea.addr = (int *)mlx_get_data_addr(cub->wall_ea.img_ptr,
			&cub->wall_ea.bpp, &cub->wall_ea.line_len, &cub->wall_ea.endian);
}

void	setup_texture(t_cub *cub)
{
	ea_texture(cub);
	so_texture(cub);
	we_texture(cub);
	no_texture(cub);
}
