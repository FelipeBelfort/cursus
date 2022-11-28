/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:55:29 by fbelfort          #+#    #+#             */
/*   Updated: 2022/11/21 18:42:06 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*str_src;
	char	*str_dst;
	size_t	i;

	i = 0;
	str_src = (char *) src;
	str_dst = (char *) dst;
	if (n == 0 || dst == src)
		return (str_dst);
	while (i < n)
	{
		str_dst[i] = str_src[i];
		i++;
	}
	return (str_dst);
}
