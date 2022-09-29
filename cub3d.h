/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-idri <ael-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:41:16 by ael-idri          #+#    #+#             */
/*   Updated: 2022/09/29 18:45:21 by ael-idri         ###   ########.fr       */
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

# include "libft/libft.h"
# include "./GNL/get_next_line.h"

# define NO 1
# define SO 2
# define WE 3
# define EA 4
# define F 5
# define C 6

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
}				t_data;

//split.c
// char	**ft_split(char const *s, char c);

//atoi.c
// int		ft_atoi(const char *str);

//		utils.c
void	init_data(t_data *data);
int		ft_open(char *file);
int		ft_isspace(char c);

//		utlis1.c
char	**ft_realoc(char **tab, int size);
bool	check_assets(t_data *data);

//utils2
bool	check_range(int n);
bool	check_xpm(char *str);
int		check_length(char **tab);

//		map_checker.c
bool	check_map(char *str, t_data *data);

#endif