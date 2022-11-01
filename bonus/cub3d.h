/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaamaou <rnaamaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:41:16 by ael-idri          #+#    #+#             */
/*   Updated: 2022/11/01 18:41:47 by rnaamaou         ###   ########.fr       */
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
# define HORI 7
# define VERT 8

# define ESC 53
# define W  13
# define A 0
# define S 1
# define D 2
# define ARROW_L 123
# define ARROW_R 124

# define M_TILE 10
# define CUBWIDTH 800
# define CUBHIGHT 700
# define CUB_TILE 10

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

typedef union u_color
{
	unsigned char	rgb[4];
	int				color;
}			t_color;

typedef struct s_tex
{
	void	*wall;
}			t_tex;

typedef struct s_point
{
	double	y;
	double	x;
}				t_point;

typedef struct s_img
{
	void	*img_ptr;
	int		*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		height;
	int		width;
}			t_img;

typedef struct s_cub
{
	t_data		*data;
	t_point		player;
	double		mstep;
	double		rstep;
	double		rayangle;
	double		dist_projection_plane;
	double		fov;
	void		*mlx_p;
	void		*mlx_w;
	t_img		img;
	t_img		wall_no;
	t_img		wall_so;
	t_img		wall_we;
	t_img		wall_ea;
	t_color		ceilling;
	t_color		floor;
	int			flag;
	double		texture_offset;
	double		wall_hight;
	bool		up;
	bool		down;
	bool		left;
	bool		ro_left;
	bool		right;
	bool		ro_right;
	int			mouse;
}				t_cub;

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

//		setup_texture.c
void	setup_texture(t_cub *cub);
void	ea_texture(t_cub *cub);
void	we_texture(t_cub *cub);
void	so_texture(t_cub *cub);
void	no_texture(t_cub *cub);

//		setup_cub.c
void	setup_cub(t_cub	*cub, t_data *data);
void	setup_color(int endian, unsigned char rgb[4], int color[4]);
void	setup_img(t_cub *cub);
void	setup_player(t_cub *cub);

//		mini_map.c
void	draw_mmap(t_cub *cub);
void	put_line(t_cub cub, t_point player, t_point end);
void	draw_ractangle(t_cub *cub, t_point p, int size, int color);
void	displacement(t_cub cub, double *pos, char flag);

//		intersection_vert.c
t_point	find_intersection(t_cub *cub, double alpha, double *distance);
t_point	vertical_intersection(t_cub cub, double alpha, double *distance);
t_point	vertical_intersection_left(t_cub cub, double alpha);
t_point	vertical_intersection_right(t_cub cub, double alpha);

//		intersection_hori.c
t_point	horizontal_intersection(t_cub cub, double alpha, double *distance);
t_point	horizontal_intersection_down(t_cub cub, double alpha);
t_point	horizontal_intersection_up(t_cub cub, double alpha);
bool	is_outside_map(int i, int j, int hight, int width);

//		map.c
void	draw_map(t_cub cub);
void	rendring_walls(t_cub cub, int ray_id, double ray_distance);

//		moving_player.c
void	player_move(t_cub *cub, int keycode);
void	move_back(t_cub *cub);
void	move_forward(t_cub *cub);
void	move_right(t_cub *cub);
void	move_left(t_cub *cub);

//		cub3d.c
int		exit_cub(void	*data);

//		mlx/_mlx.c
void	*mmlx_init(void);
int		*mmlx_get_data_addr( t_cub *cub);
void	*mmlx_new_image(void *mlx_ptr, int size_x, int size_y);
void	*mmlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);
void	mlx_update_image(t_cub *cub);

//		mlx/mlx1.c
void	mmlx_destroy_image(void *mlx_ptr, void *img_ptr);
void	mmlx_put_image_to_window(void *mlx_ptr, void *win_ptr,
			void *img_ptr, t_point	p);
void	mmlx_destroy_window(void *mlx_ptr, void *img_ptr);
void	img_pixel_put(t_img img, int x, int y, int color);

//		redering_texture.c
void	rendering_texture(t_cub cub, int len, int ray_id, int *i);

//extra.c
void	frame(t_cub	*cub);
void	move_c(t_cub *cub, char c);
int		exit_cub(void	*data);
#endif