/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:55:23 by fbelfort          #+#    #+#             */
/*   Updated: 2022/12/02 16:47:34 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	size_t	src_len;
	char	*src_copy;

	i = 0;
	src_len = ft_strlen(s1);
	src_copy = ft_calloc(src_len + 1, sizeof(char));
	if (!src_copy)
		return (NULL);
	ft_memcpy(src_copy, s1, src_len);
	src_copy[src_len] = '\0';
	return (src_copy);
}
