/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_playermap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-idri <ael-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 22:07:11 by ael-idri          #+#    #+#             */
/*   Updated: 2022/09/30 12:12:52 by ael-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	max_width(char **str)
{
	int		i;
	size_t	max;

	i = 0;
	max = 0;
	while (str[i])
	{
		if (ft_strlen(str[i]) > max)
			max = ft_strlen(str[i]);
		i++;
	}
	return (max);
}

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
		// printf("|%s|\n", data->map[i]);
		if (!data->map[i])
			return (false);
		i++;
	}
	data->map[i] = NULL;
	return (true);
}

bool	check_player_map(t_data *data)
{
	if (!init_playermap(data))
	{
		printf("fail init map!!\n");
		return (false);
	}
	return (1);
}
