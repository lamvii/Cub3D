#include "cub3d.h"


void    no_texture(t_cub *cub)
{
	int i;
	int height;
	int width;
	
	cub->wall_no.img_ptr = mlx_xpm_file_to_image(cub->mlx_p,cub->data->no,&height,&width);
	if (!cub->wall_no.img_ptr)
	{
		perror("unable to load texture");
		exit(1);
	}
	cub->wall_no.addr = mmlx_get_data_addr(cub);
	cub->wall_no.width = width;
	cub->wall_no.height = height;
}

void    so_texture(t_cub *cub)
{
	int i;
	int height;
	int width;
	
	cub->wall_so.img_ptr = mlx_xpm_file_to_image(cub->mlx_p,cub->data->so,&height,&width);
	if (!cub->wall_no.img_ptr)
	{
		perror("unable to load texture");
		exit(1);
	}
	cub->wall_so.addr = mmlx_get_data_addr(cub);
	cub->wall_so.width = width;
	cub->wall_so.height = height;
}

void    we_texture(t_cub *cub)
{
	int i;
	int height;
	int width;
	
	cub->wall_we.img_ptr = mlx_xpm_file_to_image(cub->mlx_p,cub->data->we,&height,&width);
	if (!cub->wall_we.img_ptr)
	{
		perror("unable to load texture");
		exit(1);
	}
	cub->wall_we.addr = mmlx_get_data_addr(cub);
	cub->wall_we.width = width;
	cub->wall_we.height = height;
}

void    ea_texture(t_cub *cub)
{
	int i;
	int height;
	int width;
	
	cub->wall_ea.img_ptr = mlx_xpm_file_to_image(cub->mlx_p,cub->data->ea,&height,&width);
	if (!cub->wall_ea.img_ptr)
	{
		perror("unable to load texture");
		exit(1);
	}
	cub->wall_ea.addr = mmlx_get_data_addr(cub);
	cub->wall_ea.width = width;
	cub->wall_ea.height = height;
}

void setup_texture(t_cub *cub)
{
	ea_texture(cub);
	so_texture(cub);
    we_texture(cub);
	no_texture(cub);
}