/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:00:24 by fbelfort          #+#    #+#             */
/*   Updated: 2022/11/20 17:02:51 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_str_inside(char *str, char *to_find)
{
	int	i;

	i = 0;
	while (to_find[i])
	{
		if (to_find[i] != str[i])
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strnstr(char *haystack, char *needle, size_t len)
{
	size_t	i;
	size_t	len_needle;

	i = 0;
	len_needle = ft_strlen(needle);
	if (!needle)
		return (haystack);
	while (i < (len - len_needle))
	{
		if (ft_str_inside(&haystack[i], needle))
			return (&haystack[i]);
		i++;
	}
	return (NULL);
}
