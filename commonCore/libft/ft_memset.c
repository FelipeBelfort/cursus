/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:12:32 by fbelfort          #+#    #+#             */
/*   Updated: 2022/11/20 16:12:06 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *p, int value, size_t count)
{
	int		i;
	char	*ptr_p;

	i = 0;
	ptr_p = (char *)p;
	while (count--)
		ptr_p[i++] = value;
	return (p);
}
