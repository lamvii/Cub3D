/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaamaou <rnaamaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:41:16 by ael-idri          #+#    #+#             */
/*   Updated: 2022/10/05 16:57:11 by rnaamaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <stdbool.h> 
# include <errno.h> 
# include <stdio.h>
# include <limits.h>
# include <math.h>

# include "libft/libft.h"
# include "./GNL/get_next_line.h"

# define NO 1
# define SO 2
# define WE 3
# define EA 4
# define F 5
# define C 6

# define ESC 53
# define W  13
# define A 0
# define S 1
# define D 2

# define CUBWIDTH 1000
# define CUBHIGHT 1000

typedef struct s_data
{
	char	**o_map;
	char	**map;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f[3];
	int		c[3];
	int		mhight;
	int		mwidth;
	int		px;
	int		py;
	double	rot_angle;
}				t_data;

typedef struct s_tex
{
	void	*wall;
}			t_tex;

typedef struct s_img
{
	void	*img_ptr;
	int		*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_cub
{
	t_data	*data;
	double	px;
	double	py;
	void	*mlx_p;
	void	*mlx_w;
	t_img	img;
	t_tex	*wall_no;
	t_tex	*wall_so;
	t_tex	*wall_we;
	t_tex	*wall_ea;
}				t_cub;

typedef struct s_point
{
	int	y;
	int	x;
}				t_point;

//		parsing/utils.c
int		ft_type(char *str);
char	*trim(char *str, char **dist);
bool	ft_isdigit(char *str);
void	free__tab(char ***tab);
int		tab__length(char **map);

//		parsing/utlis1.c
bool	check_tab(int *tab);
bool	check_range(int n);
int		check_length(char **tab);
int		max_width(char **str);
bool	check_xpm(char *str);

//		parsing/utils2.c
bool	is_player(char c);
int		ft_strlen_n(const char *s);
bool	check_zero_sides(char **player_map, int i, int j);
char	*trim_n_line(char *str);

//		parsing/read_map.c
bool	check_in(char *str);
bool	is_emptyline(char **line, int i);
int		ft_open(char *file);
char	**ft_realoc(char **tab, int size);
bool	read_map(char *file, t_data *data);

//		parsing/check_assets.c
bool	get_texture(t_data *data, int type, int index);
bool	parse_color(t_data *data, int index, char flag);
bool	get_colors(t_data *data, int type, int index);
bool	parse_assets(t_data *data);
bool	check_assets(t_data *data);

//		parsing/check_playermap.c
bool	check_player_map(t_data *data);
bool	pmap_valid(t_data	*data);
bool	check_map_elem(int *player_nb, t_data *data, int i, int j);
bool	init_playermap(t_data *data);
char	*str_refine(char *str, int width);

//		parsing/map_checker.c
void	init_data(t_data *data);
bool	check_map(char *str, t_data *data);

//		mini_map.c
void	draw_mmap(t_cub *cub);
void	draw_ractangle(t_cub *cub, t_point p, int size, int color);

//		image_handling.c
void	img_pixel_put(t_img img, int x, int y, int color);

//		moving_player.c
int		key_hook(int keycode, void *pram);

//		mlx/_mlx.c
void	*mmlx_init(void);
int		*mmlx_get_data_addr( t_cub *cub);
void	*mmlx_new_image(void *mlx_ptr, int size_x, int size_y);
void	*mmlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);
void	mlx_update_image(t_cub *cub);

#endif