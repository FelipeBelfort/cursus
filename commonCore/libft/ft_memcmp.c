/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:00:04 by fbelfort          #+#    #+#             */
/*   Updated: 2022/11/20 16:09:37 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*str1;
	char	*str2;
	size_t	i;

	str1 = (char *) s1;
	str2 = (char *) s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] == str2[i])
			i++;
		else if (str1[i] > str2[i])
			return (1);
		else if (str1[i] < str2[i])
			return (-1);
	}
	return (0);
}
