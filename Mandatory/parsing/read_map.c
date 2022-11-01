/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaamaou <rnaamaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 21:42:15 by ael-idri          #+#    #+#             */
/*   Updated: 2022/10/31 19:10:59 by rnaamaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

bool	is_emptyline(char **line, int i)
{
	if (*line && i < 6 && *line[0] == '\n')
	{
		free (*line);
		return (false);
	}
	return (true);
}

int	ft_open(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error");
		strerror(errno);
		return (0);
	}
	return (fd);
}

char	**ft_realoc(char **tab, int size)
{
	int		i;
	char	**n_tab;

	i = 0;
	n_tab = (char **)malloc(sizeof(char *) * size);
	if (!n_tab)
		return (NULL);
	while (i < size - 1)
	{
		n_tab[i] = tab[i];
		i++;
	}
	free(tab);
	return (n_tab);
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
		if (!is_emptyline(&line, i))
			continue ;
		i++;
		data->o_map = ft_realoc(data->o_map, i + 1);
		if (!data->o_map)
			return (false);
		data->o_map[i] = line;
	}
	return (true);
}
