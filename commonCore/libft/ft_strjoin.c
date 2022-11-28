/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:37:32 by fbelfort          #+#    #+#             */
/*   Updated: 2022/11/24 13:02:11 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
