/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:49:27 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/02/04 18:50:12 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief
 * This will return the copy of the LEN characteres of the 
 * string with the allocated memory.
*/
char	*ft_strndup(const char *s1, size_t len)
{
	char	*src_copy;

	src_copy = ft_calloc((len + 1), sizeof(char));
	if (!src_copy)
		return (NULL);
	ft_memcpy(src_copy, s1, len);
	src_copy[len] = '\0';
	return (src_copy);
}
