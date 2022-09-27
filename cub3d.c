/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaamaou <rnaamaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:41:18 by ael-idri          #+#    #+#             */
/*   Updated: 2022/09/27 18:25:29 by rnaamaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	init_data(t_data *data)
{
	data->o_map = NULL;
	data->map = NULL;
	data->no = NULL;
	data->so = NULL;
	data->we = NULL;
	data->ea = NULL;
	data->f = NULL;
	data->c = NULL;
}

int	main(int ac, char **av)
{
	t_data	data;

	if ( ac != 2)
	{
		write (2, "Error invalide arg\n", 20);
		return (1);
	}
	init_data(&data);
	if (!check_map(av[1],&data))
		return (1);
	printf("kolchi mzyan\n");
	return (0);
}
