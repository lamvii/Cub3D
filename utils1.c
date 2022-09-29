/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-idri <ael-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 18:26:53 by rnaamaou          #+#    #+#             */
/*   Updated: 2022/09/29 14:12:46 by ael-idri         ###   ########.fr       */
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

bool	get_texture(t_data *data, int type, int index)
{
	if (type == NO)
	{
		data->no = pass_w_space(data->o_map[index] + 3);
		if (!check_xpm(data->no))
			return (false);
	}
	if (type == SO)
	{
		data->so = pass_w_space(data->o_map[index] + 3);
		if (!check_xpm(data->so))
			return (false);
	}
	if (type == WE)
	{
		data->we = pass_w_space(data->o_map[index] + 3);
		if (!check_xpm(data->we))
			return (false);
	}
	if (type == EA)
	{
		data->ea = pass_w_space(data->o_map[index] + 3);
		if (!check_xpm(data->ea))
			return (false);
	}
	return (true);
}

bool	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (false);
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (false);
		i++;
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
		free(t[i]);
	free(t);
}

bool	parse_color(t_data *data, int index, char flag)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_split(pass_w_space(data->o_map[index] + 2), ',');
	if (check_length(tmp) != 3)
		return (false);
	while (i < 3)
	{
		puts("dsf");
		// printf("%s\n",tmp[i]);
		if (!ft_isdigit(tmp[i]))
			return (false);
		if (flag == 'f')
			data->f[i] = ft_atoi(tmp[i]);
		else
			data->c[i] = ft_atoi(tmp[i]);
		i++;
	}
	free__tab(&tmp);
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
			printf("ciell color invalid\n");
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
			{puts("color");
				return (false);
			}
		}
		else
		{
			if (!get_texture(data, type, i))
			{puts("tex");
				return (false);}
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
	//no need already checked
	// if (!check_length(tab))
	// 	return (false);
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
	{puts("parse");
		return (false);}
	if (!data->no || !data->so || !data->we || !data->ea
		|| !check_tab(data->f) || !check_tab(data->c))
	{
		printf("assests not valid\n");
		return (false);
	}
	return (true);
}
