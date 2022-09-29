/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-idri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 20:43:20 by ael-idri          #+#    #+#             */
/*   Updated: 2021/11/19 01:06:35 by ael-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_start(const char *s1, const char *set)
{	
	int	found;
	int	j;
	int	i;

	i = 0;
	while (s1[i])
	{
		j = 0;
		found = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				found = 1;
			j++;
		}
		if (found == 1)
			i++;
		else
			break ;
	}
	return (i);
}

static int	ft_end(const char *s1, const char *set)
{
	int	i;
	int	j;
	int	found;

	i = ft_strlen(s1) - 1;
	while (s1[i])
	{
		j = 0;
		found = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				found = 1;
			j++;
		}
		if (found == 1)
			i--;
		else
			break ;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int			i;
	int			j;
	size_t		start;
	char		*ret;

	if (s1 == NULL)
		return (NULL);
	start = ft_start(s1, set);
	if (start == ft_strlen(s1))
		return (ft_strdup(""));
	i = ft_end(s1, set) - ft_start(s1, set);
	ret = (char *)malloc(sizeof(char) * (i + 2));
	if (!ret)
		return (NULL);
	j = 0;
	while (i >= 0)
	{
		ret[j] = s1[start + j];
		j++;
		i--;
	}
	ret[j] = '\0';
	return (ret);
}
