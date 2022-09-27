/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-idri <ael-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 16:49:01 by ael-idri          #+#    #+#             */
/*   Updated: 2022/09/27 14:47:37 by ael-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUFFER_SIZE 1

char	*get_next_line(int fd);
char	*ft_strjoin(char *line, char *buffer);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *src);
int		ft_strlen(const char *s);

#endif
