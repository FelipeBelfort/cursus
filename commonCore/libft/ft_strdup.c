/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:55:23 by fbelfort          #+#    #+#             */
/*   Updated: 2022/11/28 12:27:09 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	int		i;
	size_t	src_len;
	char	*src_copy;

	i = 0;
	src_len = ft_strlen(src);
	src_copy = ft_calloc(src_len + 1, sizeof(char));
	if (!src_copy)
		return (NULL);
	ft_memcpy(src_copy, src, src_len);
	src_copy[src_len] = '\0';
	return (src_copy);
}
