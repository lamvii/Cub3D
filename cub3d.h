/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-idri <ael-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:41:16 by ael-idri          #+#    #+#             */
/*   Updated: 2022/09/27 14:45:11 by ael-idri         ###   ########.fr       */
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

typedef struct s_data
{
	char	**map;
}				t_data;

// int		ft_strlen(char *c);
int		ft_strncmp(char *s1, char *s2, int n);
bool	check_map(char *str, t_data *data);
int		ft_open(char *file);
char	**ft_realoc(char **tab, int size);

#endif