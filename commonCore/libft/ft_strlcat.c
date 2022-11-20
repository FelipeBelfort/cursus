/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:56:37 by fbelfort          #+#    #+#             */
/*   Updated: 2022/11/20 16:57:36 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	len_dst;

	len_dst = ft_strlen(dst);
	ft_strlcpy(&dst[len_dst], src, dstsize - len_dst);
	len_dst = ft_strlen(dst);
	return (len_dst);
}
