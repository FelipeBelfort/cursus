/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:48:39 by fbelfort          #+#    #+#             */
/*   Updated: 2022/11/20 17:07:14 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_trimstart(char const *s1, char const *set, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		if (j == len)
			j = 0;
		if (s1[i] != set[j])
			break ;
		i++;
		j++;
	}
	return (i);
}

static int	ft_find_trimend(char const *s1, char const *set, int len)
{
	int	i;
	int	j;

	i = ft_strlen((char *)s1);
	j = len;
	while (i > 0)
	{
		if (j == 0)
			j = len;
		if (s1[i] != set[j])
			break ;
		i--;
		j--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*strtrimmed;
	int		start_i;
	int		end_i;
	int		len;

	len = ft_strlen((char *)set);
	end_i = ft_find_trimend(s1, set, len);
	start_i = ft_find_trimstart(s1, set, len);
	strtrimmed = ft_substr(s1, start_i, end_i);
	return (strtrimmed);
}
