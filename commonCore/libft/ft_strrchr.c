/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:02:54 by fbelfort          #+#    #+#             */
/*   Updated: 2022/11/22 15:59:03 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *string, int c)
{
	size_t	i;
	char	*res;

	i = 0;
	res = NULL;
	while (string[i])
	{
		if (string[i] == (unsigned char) c)
			res = &string[i];
		i++;
	}
	if (string[i] == (unsigned char) c)
		res = &string[i];
	return (res);
}
