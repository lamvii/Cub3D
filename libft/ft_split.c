/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaamaou <rnaamaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 00:12:28 by ael-idri          #+#    #+#             */
/*   Updated: 2022/09/29 18:27:13 by rnaamaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countword(const char *s, char c)
{
	int		word;
	int		i;
	char	*str;

	str = (char *)s;
	word = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] != '\0')
			word++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (word);
}

static char	**ft_filltab(char **tab, const char *s, char c)
{
	int	i;
	int	j;
	int	k;
	int	word;

	word = ft_countword(s, c);
	k = 0;
	i = 0;
	while (k < word)
	{
		while (s[i] && s[i] == c)
			i++;
		j = 0;
		while (s[i] && s[i] != c)
			tab[k][j++] = s[i++];
		tab[k][j] = '\0';
		k++;
	}
	tab[k] = NULL;
	return (tab);
}

static char	**ft_taballoc(char **tab, int j, int k)
{
	int	i;

	i = 0;
	tab[k] = (char *)malloc(sizeof(char) * (j + 1));
	if (!tab[k])
	{
		while (i < k)
		{
			free(tab[i]);
			i++;
		}
		free(tab);
		return (NULL);
	}
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		word;

	if (!s)
		return (NULL);
	word = ft_countword(s, c);
	tab = (char **)malloc(sizeof(char *) * (word + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (word > 0)
	{
		while (s[i] && s[i] == c)
			i++;
		j = 0;
		while (s[i] && s[i++] != c)
			j++;
		if (!ft_taballoc(tab, j, ft_countword(s, c) - word))
			return (NULL);
		word--;
	}
	tab = ft_filltab(tab, s, c);
	return (tab);
}
