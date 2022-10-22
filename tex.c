#include "cub3d.h"


void    no_texture(t_cub *cub)
{
    int i;
    
    cub->wall_no.img_ptr = mlx_xpm_file_to_image(cub->mlx_p,cub->data->no,CUB_TILE,CUB_TILE);
    if (!cub->wall_no.img_ptr)
    {
        perror("unable to load texture");
        return;
    }
    cub->wall_no.addr = mmlx_get_data_addr(cub);
    cub->wall_no.bpp = 
}