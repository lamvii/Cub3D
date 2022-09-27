/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaamaou <rnaamaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 13:11:25 by ael-idri          #+#    #+#             */
/*   Updated: 2022/09/27 19:00:10 by rnaamaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_in(char *str)
{
	int	i;

	i = 0;
	if (!str || ft_strlen(str) < 4)
	{
		write(2, "invalid ifile : (.cub)\n", 23);
		return (false);
	}
	i = ft_strlen(str) - 4;
	if (!ft_strncmp(str + i, ".cub", 4))
		return (true);
	write(2, "invalid ifile : (.cub)\n", 23);
	return (false);
}

bool	read_map(char *file, t_data *data)
{
	int		i;
	int		fd;
	char	*line;

	if (!check_in(file))
		return (false);
	fd = ft_open(file);
	data->o_map = (char **)malloc(sizeof(char *));
	if (!data->o_map || !fd)
		return (false);
	line = get_next_line(fd);
	i = 0;
	data->o_map[i] = line;
	while (line)
	{	
		line = get_next_line(fd);
		if (line && i < 6 && line[0] == '\n')
			continue;
		i++;
		data->o_map = ft_realoc(data->o_map, i + 1);
		data->o_map[i] = line;
	}
	return (true);
}

bool	check_map(char *str, t_data *data)
{
	if (!read_map(str, data))
		return (false);
	if(!check_assets(data))
		return(false);
	return (true);
}
