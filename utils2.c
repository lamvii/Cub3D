/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-idri <ael-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:47:46 by rnaamaou          #+#    #+#             */
/*   Updated: 2022/09/29 14:10:06 by ael-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

bool	check_xpm(char *str)
{
	if (!ft_strncmp(str +(ft_strlen(str) - 5), ".xpm", 4))
		return (true);
	return (false);
}