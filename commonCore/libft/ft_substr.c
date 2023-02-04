/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:22:46 by fbelfort          #+#    #+#             */
/*   Updated: 2023/02/04 21:01:54 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief
 * Allocates (with malloc(3)) and returns a substring from the string ’s’.
 * The substring begins at index ’start’ and is of maximum size ’len’.
 * @param s: The string from which to create the substring.
 * @param start: The start index of the substring in the string ’s’.
 * @param len: The maximum length of the substring.
 * @return
 * The substring.
NULL if the allocation fails.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	len_substr;

	if (!s)
		return (NULL);
	if ((unsigned int) ft_strlen(s) < start)
	{
		substr = ft_calloc(1, sizeof(char));
		if (!substr)
			return (NULL);
	}
	else
	{
		len_substr = (unsigned int) ft_strlen((const char *) &s[start]);
		if (len_substr >= len)
			len_substr = len;
		substr = ft_calloc(len_substr + 1, sizeof(char));
		if (!substr)
			return (NULL);
		ft_memcpy(substr, (char *) &s[start], len_substr);
		substr[len_substr] = '\0';
	}
	return (substr);
}
