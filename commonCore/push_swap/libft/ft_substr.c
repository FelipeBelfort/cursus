/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:22:46 by fbelfort          #+#    #+#             */
/*   Updated: 2022/11/27 22:05:50 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
