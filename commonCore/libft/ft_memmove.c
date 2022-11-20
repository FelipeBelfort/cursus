/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:55:48 by fbelfort          #+#    #+#             */
/*   Updated: 2022/11/20 16:11:53 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void *src, size_t len)
{
	char	*str_src;
	char	*str_dst;
	char	*str_tmp;
	size_t	i;

	i = 0;
	str_dst = (char *) dst;
	str_src = (char *) src;
	str_tmp = ft_calloc(len, sizeof(str_tmp));
	while (i < len)
	{
		str_tmp[i] = str_src[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		str_dst[i] = str_tmp[i];
		i++;
	}
	return (dst);
}
