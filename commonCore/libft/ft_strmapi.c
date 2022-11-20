/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:01:49 by fbelfort          #+#    #+#             */
/*   Updated: 2022/11/20 17:00:35 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		len;
	char	*final_str;

	i = 0;
	len = ft_strlen((char *)s);
	final_str = ft_calloc(len + 1, sizeof(final_str));
	while (s[i])
	{
		final_str[i] = (*f)(i, s[i]);
		i++;
	}
	return (final_str);
}
