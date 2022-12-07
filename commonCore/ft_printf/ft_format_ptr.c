/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:57:40 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2022/12/07 00:08:23 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_count_size(uintptr_t n)
{
	size_t		len;
	uintptr_t	nb;

	len = 1;
	nb = n;
	while (nb >= 16)
	{
		nb /= 16;
		len++;
	}
	return (len);
}

static char	*ft_itoa_ptr(void *nb)
{
	uintptr_t	n;
	uintptr_t	n_tmp;
	size_t		len;
	char		*str_tmp;

	n = (uintptr_t) nb;
	len = ft_count_size(n);
	str_tmp = ft_calloc(len + 1, sizeof(char));
	if (n == 0)
		str_tmp[0] = '0';
	while (n > 0)
	{
		n_tmp = n % 16;
		str_tmp[--len] = LHEXA[n_tmp];
		n /= 16;
	}
	return (str_tmp);
}

int	ft_format_ptr(va_list valist, int fd)
{
	void	*ptr;
	int		count;
	char	*str;

	ptr = va_arg(valist, void *);
	count = ft_putstr_fd("0x", fd);
	str = ft_itoa_ptr(ptr);
	count += ft_putstr_fd(str, fd);
	free(str);
	return (count);
}
