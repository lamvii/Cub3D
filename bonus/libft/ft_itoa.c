/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-idri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 23:36:31 by ael-idri          #+#    #+#             */
/*   Updated: 2021/11/14 23:37:31 by ael-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr(long nb, char *str, int *i)
{
	if (nb < 0)
	{
		str[0] = '-';
		*i = *i + 1;
		nb = nb * -1;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, str, i);
		*i = *i + 1;
		ft_putnbr(nb % 10, str, i);
	}
	else
	{
		str[*i] = nb + 48;
	}
}

static int	ft_lenint(long n)
{
	int	i;

	i = 0;
	if (n < 0)
		n = n * -1;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long	nbr;
	char	*str;
	int		k;
	int		i;

	nbr = n;
	i = 0;
	k = 0;
	if (nbr < 0)
		k = 1;
	k += ft_lenint(nbr);
	str = (char *)malloc(sizeof(char) * (k + 1));
	if (!str)
		return (NULL);
	ft_putnbr(nbr, str, &i);
	str[i + 1] = '\0';
	return (str);
}
