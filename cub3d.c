/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-idri <ael-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:41:18 by ael-idri          #+#    #+#             */
/*   Updated: 2022/09/29 19:27:32 by ael-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
	{
		write (2, "Error invalide arg\n", 20);
		return (1);
	}
	init_data(&data);
	if (!check_map(av[1], &data))
		return (1);
	printf("%d---/%d---/%d\n",data.c[0],data.c[1],data.c[2]);
	printf("%d---/%d---/%d\n",data.f[0],data.f[1],data.f[2]);
	printf("kolchi mzyan\n");
	return (0);
}
