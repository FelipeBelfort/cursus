/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:37:32 by fbelfort          #+#    #+#             */
/*   Updated: 2022/11/20 16:31:55 by fbelfort         ###   ########.fr       */
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
	strjoined = malloc(sizeof(strjoined) * len + 1);
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
	return (strjoined);
}
