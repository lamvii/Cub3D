/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_playermap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaamaou <rnaamaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 22:07:11 by ael-idri          #+#    #+#             */
/*   Updated: 2022/09/30 18:42:28 by rnaamaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*str_refine(char *str, int width)
{
	char	*spacestr;
	char	*trim_nline;
	char	*tmp;
	int		i;

	i = 0;
	if (width - (int)ft_strlen(str) == 0)
		return (ft_substr(str, 0, ft_strlen(str) - 1));
	spacestr = (char *)malloc(sizeof(char) * (width - (int)ft_strlen(str)+ 1));
	if (!spacestr)
		return (NULL);
	while (i < (width - (int)ft_strlen(str)))
		spacestr[i++] = ' ';
	spacestr[i] = '\0';
	trim_nline = ft_substr(str, 0, ft_strlen(str) - 1);
	tmp = ft_strjoin(trim_nline, spacestr);
	free(trim_nline);
	free(spacestr);
	return (tmp);
}

bool	init_playermap(t_data *data)
{
	int	length;
	int	width;
	int	i;

	i = 0;
	length = tab__length(data->o_map + 6);
	width = max_width(data->o_map + 6);
	data->map = (char **)malloc(sizeof(char *) * length);
	if (!data->map)
		return (false);
	while (i < length)
	{
		data->map[i] = str_refine(data->o_map[i + 6], width);
		if (!data->map[i])
			return (false);
		i++;
	}
	data->map[i] = NULL;
	return (true);
}

bool	check_map_elem(int *player_nb, char	**player_map, int i, int j)
{
	if (player_map[i][j] == '0')
	{
		if (!check_zero_sides(player_map, i, j))
			return (printf("map border is open !!\n"), false);
	}
	else if (is_player(player_map[i][j]))
	{	
		if ((++(*player_nb)) != 1)
			return (printf("player (number) !valid\n"), false);
		if (!check_zero_sides(player_map, i, j))
			return (printf("player position !valid\n"), false);
	}
	else if (player_map[i][j] != ' ' && player_map[i][j] != '1')
		return (printf("caracter not valid\n"), false);
	return (true);
}

bool	pmap_valid(char	**player_map)
{
	int	i;
	int	j;
	int	player_nb;

	i = -1;
	player_nb = 0;
	while (player_map[++i])
	{
		j = -1;
		while (player_map[i][++j])
		{
			if (!check_map_elem(&player_nb, player_map, i, j))
				return (false);
		}
	}
	if (player_nb != 1)
		return (printf("player position(number) !valid\n"), false);
	return (true);
}

bool	check_player_map(t_data *data)
{
	if (!init_playermap(data))
	{
		printf("fail init map!!\n");
		return (false);
	}
	if (!pmap_valid(data->map))
	{
		printf("player map not valide\n");
		return (false);
	}
	return (1);
}
