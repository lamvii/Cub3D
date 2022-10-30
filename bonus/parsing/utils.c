/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-idri <ael-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 13:26:46 by rnaamaou          #+#    #+#             */
/*   Updated: 2022/10/04 16:59:42 by ael-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

char	*trim(char *str, char **dist)
{
	int		start;
	int		end;

	start = 0;
	end = ft_strlen(str) - 2;
	while (str[start] == ' ')
		start++;
	while (str[end] == ' ')
		end--;
	if (end - start < 0)
		*dist = ft_strdup("");
	else
		*dist = ft_substr(str, start, end - start + 1);
	return (*dist);
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
		free(t[i++]);
	free(t);
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
