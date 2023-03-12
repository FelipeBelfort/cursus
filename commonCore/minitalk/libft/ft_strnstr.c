/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:00:24 by fbelfort          #+#    #+#             */
/*   Updated: 2022/11/27 12:54:25 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_str_inside(char *str, char *to_find)
{
	int	i;

	i = 0;
	while (to_find[i])
	{
		if (to_find[i] != str[i] || !str[i])
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		len_needle;
	char	*ptr_haystack;
	char	*ptr_needle;

	i = 0;
	ptr_haystack = (char *) haystack;
	ptr_needle = (char *) needle;
	len_needle = ft_strlen(needle);
	if ((size_t) ft_strlen(haystack) < len)
		len = (size_t) ft_strlen(haystack);
	if (len_needle == 0 || ptr_haystack == ptr_needle)
		return (ptr_haystack);
	while (i <= ((int) len - len_needle))
	{
		if (ft_str_inside(&ptr_haystack[i], ptr_needle))
			return (&ptr_haystack[i]);
		i++;
	}
	return (NULL);
}
