/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:55:23 by fbelfort          #+#    #+#             */
/*   Updated: 2022/11/17 16:03:46 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
    int     i;
    char    *src_copy;

    i = 0;
    src_copy = malloc(sizeof(src_copy) * ft_strlen(src) + 1);
    if (!src_copy)
        return (NULL);
    while (src[i])
    {
        src_copy[i] = src[i];
        i++;
    }
    src_copy[i] = '\0';
    return (src_copy);
}