/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaamaou <rnaamaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 13:11:25 by ael-idri          #+#    #+#             */
/*   Updated: 2022/09/27 13:36:27 by rnaamaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_in(char *str)
{
	int i = 0;
	if (!str || ft_strlen(str) < 4)
		return(false);
	i = ft_strlen(str) - 4;
	if (!ft_strncmp(str+i,".cub",4))
	{
		printf("worked!!!\n");
		return (true);
	}
	return(false);
}