/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaamaou <rnaamaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:41:16 by ael-idri          #+#    #+#             */
/*   Updated: 2022/09/27 16:02:36 by rnaamaou         ###   ########.fr       */
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

#include "./GNL/get_next_line.h"

# define SUCCESS 0
# define FAILED 1
# define NO 2
# define SO 3
# define WE 4
# define EA 5
# define F 6
# define C 7

typedef struct s_data
{
	char	**o_map;
	char	**map;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
}				t_data;


// int		ft_strlen(char *c);
int		ft_strncmp(char *s1, char *s2, int n);
bool	check_map(char *str, t_data *data);
int		ft_open(char *file);
char	**ft_realoc(char **tab, int size);

#endif