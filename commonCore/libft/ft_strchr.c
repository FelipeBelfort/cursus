/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:40:40 by fbelfort          #+#    #+#             */
/*   Updated: 2022/11/17 12:52:10 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strchr(char *string, int c)
{
    int i;

    i = 0;
    while (string[i])
    {
        if (string[i] == c)
        {
            return (string[i]);
        }
        i++;
    }
    return (NULL);
}