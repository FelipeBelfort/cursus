/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:40:40 by fbelfort          #+#    #+#             */
/*   Updated: 2022/11/22 15:45:37 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *string, int c)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == (unsigned char) c)
			return (&string[i]);
		i++;
	}
	if (string[i] == (unsigned char) c)
		return (&string[i]);
	return (NULL);
}
