/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_assets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-idri <ael-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 21:43:58 by ael-idri          #+#    #+#             */
/*   Updated: 2022/10/04 17:00:04 by ael-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	get_texture(t_data *data, int type, int index)
{
	if (type == NO)
	{
		trim(data->o_map[index] + 3, &data->no);
		if (!check_xpm(data->no))
			return (false);
	}
	if (type == SO)
	{
		trim(data->o_map[index] + 3, &data->so);
		if (!check_xpm(data->so))
			return (false);
	}
	if (type == WE)
	{
		trim(data->o_map[index] + 3, &data->we);
		if (!check_xpm(data->we))
			return (false);
	}
	if (type == EA)
	{
		trim(data->o_map[index] + 3, &data->ea);
		if (!check_xpm(data->ea))
			return (false);
	}
	return (true);
}

bool	parse_color(t_data *data, int index, char flag)
{
	char	**tmp;
	char	*colo;
	int		i;

	i = 0;
	tmp = ft_split(trim(data->o_map[index] + 2, &colo), ',');
	if (!tmp)
		return (false);
	if (check_length(tmp) != 3)
		return (false);
	while (i < 3)
	{
		if (!ft_isdigit(tmp[i]))
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
