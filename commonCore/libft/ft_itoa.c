/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:01:32 by fbelfort          #+#    #+#             */
/*   Updated: 2022/11/17 17:58:40 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_itoa(int n)
{
    unsigned int    nb;
    unsigned int    len;
    char            *str;

    len = 1;
    nb = n;
    if (n < 0)
    {
        len++;
        nb = -n;
        n = -n;
    }
    while (n > 0)
    {
        n /= 10;
        len++;
    }
    str = ft_calloc(len, sizeof(str));
    str[0] = '-';
    while (nb > 0)
    {
        str[--len] = nb % 10 + '0';
        nb /= 10;
    }
    return (str);
}