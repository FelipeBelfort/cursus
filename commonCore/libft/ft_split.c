/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:04:18 by fbelfort          #+#    #+#             */
/*   Updated: 2022/11/28 22:30:13 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_filltab(char const *str, char charset, char **tab)
{
	int		i;
	int		j;
	int		tab_i;

	i = 0;
	tab_i = 0;
	while (str[i])
	{
		if (str[i] == charset)
			i++;
		else
		{
			j = 1;
			while (str[i + j] && str[i + j] != charset)
				j++;
			tab[tab_i] = ft_substr(str, i, j);
			tab_i++;
			i += j;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	int		i;
	size_t	words;
	char	**tab;

	i = 0;
	words = 1;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			words++;
		i++;
	}
	tab = malloc(sizeof(tab) * words);
	if (!tab)
		return (NULL);
	while (words > 0)
		tab[--words] = 0;
	ft_filltab(s, c, tab);
	if (!tab)
		return (NULL);
	return (tab);
}

// 	i = 1;
// 	words = 1;
// 	if (!s)
// 	{
// 		if (!(tab = ft_calloc(2, sizeof(char *))))
// 			return (NULL);
// 		if (!(tab[0] = ft_calloc(1, sizeof(char))))
// 			return (NULL);
// 		return (tab);
// 	}
// 	if (s[0] != c)
// 		words++;
// 	while (s[i])
// 	{
// 		if (s[i] != c && s[i - 1] == c)
// 			words++;
// 		i++;
// 	}
// 	tab = ft_calloc(words, sizeof(char *));
// 	if (!tab)
// 		return (NULL);
// 	ft_filltab(s, c, tab);
// 	return (tab);
// }
