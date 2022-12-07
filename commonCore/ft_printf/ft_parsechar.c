/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsechar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:46:42 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2022/12/07 00:46:55 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format_str(va_list valist, int fd)
{
	char	*ptr;
	int		count;

	ptr = va_arg(valist, char *);
	if (!ptr)
		count = ft_putstr_fd("(null)", fd);
	else
		count = ft_putstr_fd((char *) ptr, fd);
	return (count);
}

static void	ft_putnbr_base_c(long long int nb, char *base, int fd, int *count)
{
	unsigned long int	n;
	unsigned long int	base_len;

	base_len = ft_strlen(base);
	n = nb;
	if (nb < 0)
	{
		*count += ft_putchar_fd('-', fd);
		n = nb * -1;
	}
	if (n >= base_len)
	{
		ft_putnbr_base_c(n / base_len, base, fd, count);
		ft_putnbr_base_c(n % base_len, base, fd, count);
	}
	else
	{
		*count += ft_putchar_fd(base[n], fd);
	}
}

static char	*ft_uitoa(unsigned long long int nb)
{
	unsigned long int	n;
	unsigned long int	n_tmp;
	size_t				len;
	char				*str_tmp;

	n = nb;
	len = 1;
	if (n > LONG_MAX)
		n = 0;
	while (nb >= 10)
	{
		nb /= 10;
		len++;
	}
	str_tmp = ft_calloc(len + 1, sizeof(char));
	if (n == 0)
		str_tmp[0] = '0';
	while (n > 0)
	{
		n_tmp = n % 10;
		str_tmp[--len] = DECIMAL[n_tmp];
		n /= 10;
	}
	return (str_tmp);
}

static int	ft_format_nbr(va_list valist, char c, int fd)
{
	unsigned long int	tmp;
	int					count;
	char				*str;

	count = 0;
	if (c == 'u')
	{
		tmp = va_arg(valist, unsigned long long int);
		str = ft_uitoa(tmp);
		count += ft_putstr_fd(str, fd);
		free(str);
	}
	if (c == 'i' || c == 'd')
		ft_putnbr_base_c(va_arg(valist, int), DECIMAL, fd, &count);
	return (count);
}

int	ft_parsechar(char c, va_list valist, int fd)
{
	int					count;

	count = 0;
	if (c == '%')
		count += ft_putchar_fd('%', fd);
	if (c == 'c')
		count += ft_putchar_fd(va_arg(valist, int), fd);
	if (c == 's')
		count += ft_format_str(valist, fd);
	if (c == 'p')
		count += ft_format_ptr(valist, fd);
	if (c == 'u' || c == 'i' || c == 'd')
		count += ft_format_nbr(valist, c, fd);
	if (c == 'x')
		ft_putnbr_base_c(va_arg(valist, unsigned int), LHEXA, fd, &count);
	if (c == 'X')
		ft_putnbr_base_c(va_arg(valist, unsigned int), UHEXA, fd, &count);
	return (count);
}
