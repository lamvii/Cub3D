/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaamaou <rnaamaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 16:49:01 by ael-idri          #+#    #+#             */
/*   Updated: 2022/09/29 18:38:51 by rnaamaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
//#include "../libft/libft.h"

# define BUFFER_SIZE 1

char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char *line, char *buffer);
char	*ft_strchr_gnl(const char *s, int c);
char	*ft_strdup_gnl(const char *src);
int		ft_strlen_gnl(const char *s);

#endif
