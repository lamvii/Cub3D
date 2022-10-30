/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-idri <ael-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 18:26:53 by rnaamaou          #+#    #+#             */
/*   Updated: 2022/10/04 16:59:52 by ael-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

bool	check_range(int n)
{
	if (n < 0 || n > 255)
		return (false);
	return (true);
}

int	check_length(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	max_width(char **str)
{
	int		i;
	int		max;

	i = 0;
	max = 0;
	while (str[i])
	{
		if (ft_strlen_n(str[i]) > max)
			max = ft_strlen_n(str[i]);
		i++;
	}
	return (max);
}

bool	check_xpm(char *str)
{
	if (!ft_strncmp(str +(ft_strlen(str) - 4), ".xpm", 4))
		return (true);
	printf("texture invalid (.xpm)");
	return (false);
}
