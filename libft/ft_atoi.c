/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-idri <ael-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:16:01 by ael-idri          #+#    #+#             */
/*   Updated: 2022/09/29 18:47:41 by ael-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	ft_atoi(const char *str)
{
	int			i;
	int			s;
	long long	r;
	char		*ptr;

	i = 0;
	s = 1;
	r = 0;
	ptr = (char *)str;
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
	if ((s * r) > INT_MAX || (s * r) < INT_MIN)
		return (-1);
	return (s * r);
}
