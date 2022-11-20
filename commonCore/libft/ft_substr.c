/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:22:46 by fbelfort          #+#    #+#             */
/*   Updated: 2022/11/20 16:28:35 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	int		i;

	i = 0;
	substr = malloc(sizeof(*substr) * len + 1);
	if (!substr)
		return (NULL);
	while (s[start])
	{
		if (substr[i])
		{
			substr[i] = s[start];
			i++;
		}
		else
			break ;
		start++;
	}
	return (substr);
}
