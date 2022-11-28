/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:01:49 by fbelfort          #+#    #+#             */
/*   Updated: 2022/11/28 12:42:36 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		len;
	char	*final_str;

	i = 0;
	len = ft_strlen(s);
	final_str = ft_calloc(len + 1, sizeof(char));
	if (!final_str)
		return (NULL);
	while (s[i])
	{
		final_str[i] = (*f)(i, s[i]);
		i++;
	}
	return (final_str);
}
