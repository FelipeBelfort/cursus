/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:37:32 by fbelfort          #+#    #+#             */
/*   Updated: 2023/02/04 21:01:44 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief
 * Allocates (with malloc(3)) and returns a new string, 
 * which is the result of the concatenation of ’s1’ and ’s2’.
 * @param s1: The prefix string.
 * @param s2: The sufix string.
 * @return
 * The new string.
NULL if the allocation fails.
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoined;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	strjoined = malloc(sizeof(char) * len + 1);
	if (!strjoined)
		return (NULL);
	while (s1[i])
	{
		strjoined[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		strjoined[i] = s2[j];
		i++;
		j++;
	}
	strjoined[i] = 0;
	return (strjoined);
}
