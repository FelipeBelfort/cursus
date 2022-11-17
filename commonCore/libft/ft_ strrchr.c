/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ strrchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:02:54 by fbelfort          #+#    #+#             */
/*   Updated: 2022/11/17 12:52:10 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strrchr(char *string, int c)
{
    int i;

    i = ft_strlen(string);
    while (--i >= 0)
    {
        if (string[i] == c)
        {
            return (string[i]);
        }
    }
    return (NULL);    
}