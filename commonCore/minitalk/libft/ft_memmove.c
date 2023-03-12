/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:55:48 by fbelfort          #+#    #+#             */
/*   Updated: 2022/11/28 21:34:50 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*str_src;
	char	*str_dst;

	str_src = (char *) src;
	str_dst = (char *) dst;
	if (!str_src && !str_dst && len)
		return (NULL);
	if ((str_src < str_dst) && (str_dst < str_src + len))
	{
		while (len--)
			str_dst[len] = str_src[len];
	}
	else
	{
		while (len--)
			*str_dst++ = *str_src++;
	}
	return (dst);
}
