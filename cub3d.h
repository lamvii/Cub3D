/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-idri <ael-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:41:16 by ael-idri          #+#    #+#             */
/*   Updated: 2022/10/03 13:52:32 by ael-idri         ###   ########.fr       */
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

# define CUBWIDTH 640
# define CUBHIGHT 420

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

typedef struct s_cub
{
	t_data	*data;
	void	*mlx_p;
	void	*mlx_w;
	t_tex	*wall_no;
	t_tex	*wall_so;
	t_tex	*wall_we;
	t_tex	*wall_ea;
}				t_cub;

//		utils.c
int		ft_type(char *str);
char	*trim(char *str, char **dist);
bool	ft_isdigit(char *str);
void	free__tab(char ***tab);
int		tab__length(char **map);

//		utlis1.c
bool	check_tab(int *tab);
bool	check_range(int n);
int		check_length(char **tab);
int		max_width(char **str);
bool	check_xpm(char *str);
int		ft_strlen_n(const char *s);

//utils2.c
bool	is_player(char c);

//		read_map.c
bool	check_in(char *str);
bool	is_emptyline(char **line, int i);
int		ft_open(char *file);
char	**ft_realoc(char **tab, int size);
bool	read_map(char *file, t_data *data);

//		check_assets.c
bool	get_texture(t_data *data, int type, int index);
bool	parse_color(t_data *data, int index, char flag);
bool	get_colors(t_data *data, int type, int index);
bool	parse_assets(t_data *data);
bool	check_assets(t_data *data);

//		check_playermap.c
bool	check_player_map(t_data *data);
bool	check_zero_sides(char **player_map, int i, int j);

//		map_checker.c
void	init_data(t_data *data);
bool	check_map(char *str, t_data *data);

#endif