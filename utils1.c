/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-idri <ael-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 18:26:53 by rnaamaou          #+#    #+#             */
/*   Updated: 2022/09/29 19:26:23 by ael-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_type(char *str)
{
	if (!ft_strncmp(str, "NO ", 3))
		return (NO);
	if (!ft_strncmp(str, "SO ", 3))
		return (SO);
	if (!ft_strncmp(str, "WE ", 3))
		return (WE);
	if (!ft_strncmp(str, "EA ", 3))
		return (EA);
	if (!ft_strncmp(str, "F ", 2))
		return (F);
	if (!ft_strncmp(str, "C ", 2))
		return (C);
	return (0);
}

char	*pass_w_space(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (ft_isspace(str[i]))
		i++;
	return (str + i);
}

//need test
char	*trim(char *str, char **dist, int from)
{
	int		start;
	int		end;

	start = from;
	end = ft_strlen(str);
	while (str[start] == ' ')
		start++;
	while (str[end] == ' ')
		end--;
	if (end - start <= 0)
		*dist = ft_strdup("");
	else
		*dist = ft_substr(str, start, end - start);
	return (*dist);
}

bool	get_texture(t_data *data, int type, int index)
{
	if (type == NO)
	{
		trim(data->o_map[index], &data->no, 3);
		if (!check_xpm(data->no))
			return (false);
	}
	if (type == SO)
	{
		trim(data->o_map[index], &data->so, 3);
		if (!check_xpm(data->so))
			return (false);
	}
	if (type == WE)
	{
		trim(data->o_map[index], &data->we, 3);
		if (!check_xpm(data->we))
			return (false);
	}
	if (type == EA)
	{
		trim(data->o_map[index], &data->ea, 3);
		if (!check_xpm(data->ea))
			return (false);
	}
	return (true);
}

bool	ft_isdigit(char *str)
{
	int	i;
	int	pos;

	i = 0;
	if (!str)
		return (false);
	pos = ft_strlen(str) - 2;
	while (str[pos] == ' ')
		pos--;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] <= '9' && str[i] >= '0')
			i++;
		else if (i == pos + 1)
			break ;
		else
			return (false);
	}
	return (true);
}

void	free__tab(char ***tab)
{
	char	**t;
	int		i;

	t = *tab;
	i = 0;
	if (!t)
		return ;
	while (t[i])
		free(t[i++]);
	free(t);
}

bool	parse_color(t_data *data, int index, char flag)
{
	char	**tmp;
	char	*colo;
	int		i;

	i = 0;
	tmp = ft_split(trim(data->o_map[index], &colo, 2), ',');
	if (!tmp)
		return (false);
	if (check_length(tmp) != 3)
		return (false);
	while (i < 3)
	{
		if (!ft_isdigit(tmp[i]) || tmp[i][0] == '\n')
			return (false);
		if (flag == 'f')
			data->f[i] = ft_atoi(tmp[i]);
		else
			data->c[i] = ft_atoi(tmp[i]);
		i++;
	}
	free__tab(&tmp);
	free(colo);
	return (true);
}

bool	get_colors(t_data *data, int type, int index)
{
	if (type == F)
	{
		if (!parse_color(data, index, 'f'))
		{
			printf("floor color invalid\n");
			return (false);
		}
	}
	if (type == C)
	{
		if (!parse_color(data, index, 'c'))
		{
			printf("ceilling color invalid\n");
			return (false);
		}
	}
	return (true);
}

int	tab__length(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return (0);
	while (map[i])
		i++;
	return (i);
}

bool	parse_assets(t_data *data)
{
	int	i;
	int	type;

	i = 0;
	while (i < 6)
	{
		type = ft_type(data->o_map[i]);
		if (!type)
		{
			printf("assests not valid\n");
			return (false);
		}
		if (type == F || type == C)
		{
			if (!get_colors(data, type, i))
				return (false);
		}
		else
		{
			if (!get_texture(data, type, i))
				return (false);
		}
		i++;
	}
	return (true);
}

bool	check_tab(int *tab)
{
	int		i;

	i = 0;
	while (i < 3)
	{
		if (tab[i] == -1 || !check_range(tab[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	check_assets(t_data *data)
{
	int	i;

	i = 0;
	if (check_length(data->o_map) < 9)
	{
		printf("non valid map\n");
		return (false);
	}
	if (!parse_assets(data))
		return (false);
	if (!data->no || !data->so || !data->we || !data->ea
		|| !check_tab(data->f) || !check_tab(data->c))
	{
		printf("assests not valid\n");
		return (false);
	}
	return (true);
}
