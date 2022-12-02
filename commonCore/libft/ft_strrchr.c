/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:02:54 by fbelfort          #+#    #+#             */
/*   Updated: 2022/12/02 17:01:02 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		i;
	const char	*res;

	i = 0;
	res = NULL;
	while (s[i])
	{
		if (s[i] == (unsigned char) c)
			res = &s[i];
		i++;
	}
	if (s[i] == (unsigned char) c)
		res = &s[i];
	return ((char *) res);
}
