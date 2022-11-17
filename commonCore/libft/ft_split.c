/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:04:18 by fbelfort          #+#    #+#             */
/*   Updated: 2022/11/17 16:03:46 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char **ft_split(char const *s, char c)
{
    //create tab
    while (s[i])
    {
        if (s[i] != c && s[i + 1] == c)
            words++;
        i++;
    }
    
    //look for word

    //create str and copy
}