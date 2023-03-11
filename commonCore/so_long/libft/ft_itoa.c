/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:01:32 by fbelfort          #+#    #+#             */
/*   Updated: 2023/02/04 21:06:57 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_size(int n)
{
	size_t	len;
	int		nb;

	len = 1;
	nb = n;
	if (n <= 0)
		len++;
	while (nb != 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

/**
 * @brief
 * Allocates (with malloc(3)) and returns a string 
 * representing the integer received as an argument. 
 * Negative numbers must be handled.
 * @param n: the integer to convert.
 * @return 
 * The string representing the integer. NULL if the allocation fails.
*/
char	*ft_itoa(int n)
{
	long long int	nb;
	size_t			len;
	char			*str;

	nb = n;
	len = ft_count_size(n);
	str = ft_calloc(len--, sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		nb *= -1;
		str[0] = '-';
	}
	if (nb == 0)
		str[0] = '0';
	while (nb > 0)
	{
		str[--len] = nb % 10 + '0';
		nb /= 10;
	}
	return (str);
}
