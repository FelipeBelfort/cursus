/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:48:39 by fbelfort          #+#    #+#             */
/*   Updated: 2023/02/04 21:04:17 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_istotrim(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

/**
 * @brief
 * Allocates (with malloc(3)) and returns a copy of ’s1’ 
 * with the characters specified in ’set’ removed 
 * from the beginning and the end of the string.
 * @param s1: The string to be trimmed.
 * @param set: The reference set of characters to trim.
 * @return
 * The trimmed string.
NULL if the allocation fails.
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*strtrimmed;
	int		start_i;
	int		end_i;

	end_i = ft_strlen(s1) - 1;
	start_i = 0;
	if (set == s1 || !s1 || end_i < 1)
		return (ft_calloc(1, sizeof(char)));
	if (!set)
		return ((char *) s1);
	while (ft_istotrim(s1[start_i], set))
		start_i++;
	while (ft_istotrim(s1[end_i], set))
		end_i--;
	strtrimmed = ft_substr(s1, start_i, end_i - start_i + 1);
	return (strtrimmed);
}
