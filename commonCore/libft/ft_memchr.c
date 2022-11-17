/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:58:15 by fbelfort          #+#    #+#             */
/*   Updated: 2022/11/17 17:58:40 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memchr(const void *s, int c, size_t n)
{
    size_t  i;
    char    *str;

    i = 0;
    str = (char*) s;
    while (i <= n)
    {
        if (str[i] == c)
            return (str[i]);
        i++;
    }
    return (NULL);
}