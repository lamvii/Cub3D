/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaamaou <rnaamaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:47:46 by rnaamaou          #+#    #+#             */
/*   Updated: 2022/09/28 16:04:39 by rnaamaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_range(int n)
{
	if (n < 0 || n > 255)
		return (false);
	return (true);	
}

bool	check_lenght(int *tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	if (i != 3)
		return (false);
	return (true);
}

