/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-idri <ael-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:41:18 by ael-idri          #+#    #+#             */
/*   Updated: 2022/09/27 19:59:30 by ael-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



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
