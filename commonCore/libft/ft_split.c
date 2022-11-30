/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:04:18 by fbelfort          #+#    #+#             */
/*   Updated: 2022/11/30 14:21:15 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_freetab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	tab = NULL;
}

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
			if (!tab[tab_i])
			{
				ft_freetab(tab);
				return ;
			}
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
	words = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			words++;
		i++;
	}
	tab = (char **) malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	tab[words] = 0;
	ft_filltab(s, c, tab);
	if (!tab)
		return (NULL);
	return (tab);
}
