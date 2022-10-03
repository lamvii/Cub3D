/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_playermap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-idri <ael-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 22:07:11 by ael-idri          #+#    #+#             */
/*   Updated: 2022/10/03 14:42:40 by ael-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*trim_n_line(char *str)
{
	if (str[ft_strlen(str) - 1] == '\n')
		return (ft_substr(str, 0, ft_strlen(str) - 1));
	return (ft_strdup(str));
}

char	*str_refine(char *str, int width)
{
	char	*spacestr;
	char	*trim_nline;
	char	*tmp;
	int		i;

	i = 0;
	puts("dsf");
	if (width - (int)ft_strlen_n(str) == 0)
		return (ft_substr(str, 0, ft_strlen_n(str)));
	spacestr = (char *)malloc(sizeof(char) * (width - (int)ft_strlen_n(str) + 1));
	if (!spacestr)
		return (NULL);
	while (i < (width - (int)ft_strlen_n(str)))
		spacestr[i++] = ' ';
	spacestr[i] = '\0';
	trim_nline = trim_n_line(str);
	tmp = ft_strjoin(trim_nline, spacestr);
	free(trim_nline);
	free(spacestr);
	puts("123");
	return (tmp);
}

bool	init_playermap(t_data *data)
{
	int	i;

	i = 0;
	data->mhight = tab__length(data->o_map + 6);
	data->mwidth = max_width(data->o_map + 6);
	data->map = (char **)malloc(sizeof(char *) * (data->mhight + 1));
	if (!data->map)
		return (false);
	while (i < data->mhight)
	{
		printf("alo\n");
		data->map[i] = str_refine(data->o_map[i + 6], data->mwidth);
		if (!data->map[i])
			return (false);
		i++;
	}
	data->map[i] = NULL;
	return (true);
}

bool	check_map_elem(int *player_nb, t_data *data, int i, int j)
{
	if (data->map[i][j] == '0')
	{
		if (!check_zero_sides(data->map, i, j))
			return (printf("map border is open !!\n"), false);
	}
	else if (is_player(data->map[i][j]))
	{	
		if ((++(*player_nb)) != 1)
			return (printf("player (number) !valid\n"), false);
		if (!check_zero_sides(data->map, i, j))
			return (printf("player position !valid\n"), false);
		data->px = j;
		data->py = -i;
		if (data->map[i][j] == 'N')
			data->rot_angle = 1.5 * M_PI;
		if (data->map[i][j] == 'S')
			data->rot_angle = M_PI / 2;
		if (data->map[i][j] == 'E')
			data->rot_angle = 0;
		if (data->map[i][j] == 'W')
			data->rot_angle = M_PI;
	}
	else if (data->map[i][j] != ' ' && data->map[i][j] != '1')
		return (printf("caracter not valid\n"), false);
	return (true);
}

bool	pmap_valid(t_data	*data)
{
	int	i;
	int	j;
	int	player_nb;

	i = -1;
	player_nb = 0;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (!check_map_elem(&player_nb, data, i, j))
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
	if (!pmap_valid(data))
	{
		printf("player map not valide\n");
		return (false);
	}
	return (1);
}
