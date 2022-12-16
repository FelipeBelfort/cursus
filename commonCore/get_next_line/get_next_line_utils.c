/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:23:33 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2022/12/16 11:55:44 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	len_substr;

	if (!s)
		return (NULL);
	if ((unsigned int) ft_strlen(s) < start)
	{
		substr = malloc(sizeof(char));
		if (!substr)
			return (NULL);
	}
	else
	{
		len_substr = (unsigned int) ft_strlen((const char *) &s[start]);
		if (len_substr >= len)
			len_substr = len;
		substr = malloc((len_substr + 1) * sizeof(char));
		if (!substr)
			return (NULL);
		ft_memcpy(substr, (char *) &s[start], len_substr);
		substr[len_substr] = '\0';
	}
	return (substr);
}

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char) c)
			return (i);
		i++;
	}
	if (s[i] == (unsigned char) c)
		return (i);
	return (0);
}
