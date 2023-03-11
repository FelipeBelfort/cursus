/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:01:49 by fbelfort          #+#    #+#             */
/*   Updated: 2023/02/04 21:08:47 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief
 * Applies the function ’f’ to each character of the string ’s’, 
 * and passing its index as first argument 
 * to create a new string (with malloc(3)) 
 * resulting from successive applications of ’f’.
 * @param s: The string on which to iterate.
 * @param f: The function to apply to each character.
 * @return 
 * The string created from the successive applications of ’f’.
Returns NULL if the allocation fails.
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		len;
	char	*final_str;

	i = 0;
	len = ft_strlen(s);
	final_str = ft_calloc(len + 1, sizeof(char));
	if (!final_str)
		return (NULL);
	while (s[i])
	{
		final_str[i] = (*f)(i, s[i]);
		i++;
	}
	return (final_str);
}
