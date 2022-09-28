/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaamaou <rnaamaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:16:01 by ael-idri          #+#    #+#             */
/*   Updated: 2022/09/28 12:31:48 by rnaamaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		s;
	int		r;
	char	*ptr;

	i = 0;
	s = 1;
	r = 0;
	ptr = (char *)str;
	if (str[0] == '\0')
		return (-1);
	while (ptr[i] == 32 || (ptr[i] >= 9 && ptr[i] <= 13))
		i++;
	if (ptr[i] == '-' || ptr[i] == '+')
	{
		if (ptr[i] == '-')
			s = s * (-1);
		i++;
	}
	while (ptr[i] >= '0' && ptr[i] <= '9' )
	{
		r = r * 10 + ptr[i] - 48;
		i++;
	}
	return (s * r);
}