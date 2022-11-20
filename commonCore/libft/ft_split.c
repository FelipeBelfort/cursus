/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:04:18 by fbelfort          #+#    #+#             */
/*   Updated: 2022/11/20 16:40:21 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_filltab(char const *s, char c, int words)
{
	char	**tab;
	int		i;
	int		j;
	int		tab_i;

	i = 0;
	tab_i = 0;
	tab = ft_calloc(words + 1, sizeof(tab));
	tab[words] = NULL;
	while (s[i++])
	{
		if (s[i] == c)
			i++;
		else
		{
			j = 0;
			while (s[i + j] != c)
				j++;
			tab[tab_i++] = ft_substr(s, i, j - 1);
			i += j;
		}
	}
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c && s[i + 1] == c)
			words++;
		i++;
	}
	return (ft_filltab(s, c, words));
}
