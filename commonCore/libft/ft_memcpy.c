/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:55:29 by fbelfort          #+#    #+#             */
/*   Updated: 2022/11/20 17:54:05 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	char	*str_src;
	char	*str_dst;
	size_t	i;

	i = 0;
	str_src = (char *) src;
	str_dst = (char *) dst;
	while (i < n && str_src[i] && str_dst[i])
	{
		str_dst[i] = str_src[i];
		i++;
	}
	return (str_dst);
}
