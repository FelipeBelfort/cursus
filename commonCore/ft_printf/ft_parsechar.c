/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsechar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:46:42 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2022/12/12 12:34:11 by fbelfort         ###   ########.fr       */
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

static void	ft_putunbr_base_c(unsigned long int nb, char *base, int fd, int *c)
{
	unsigned long int	base_len;

	base_len = ft_strlen(base);
	if (nb >= base_len)
	{
		ft_putnbr_base_c(nb / base_len, base, fd, c);
		ft_putnbr_base_c(nb % base_len, base, fd, c);
	}
	else
	{
		*c += write(fd, &base[nb], 1);
	}
}

static int	ft_format_nbr(va_list valist, char c, int fd)
{
	unsigned int	tmp;
	int				count_nbr;

	count_nbr = 0;
	if (c == 'u')
	{
		tmp = va_arg(valist, unsigned int);
		ft_putunbr_base_c(tmp, DECIMAL, fd, &count_nbr);
	}
	if (c == 'i' || c == 'd')
		ft_putnbr_base_c(va_arg(valist, int), DECIMAL, fd, &count_nbr);
	return (count_nbr);
}

int	ft_parsechar(char c, va_list valist, int fd)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar_fd(va_arg(valist, int), fd);
	else if (c == 's')
		count += ft_format_str(valist, fd);
	else if (c == 'p')
	{
		count = ft_putstr_fd("0x", fd);
		ft_putunbr_base_c(va_arg(valist, unsigned long int), LHEXA, fd, &count);
	}
	else if (c == 'u' || c == 'i' || c == 'd')
		count += ft_format_nbr(valist, c, fd);
	else if (c == 'x')
		ft_putnbr_base_c(va_arg(valist, unsigned int), LHEXA, fd, &count);
	else if (c == 'X')
		ft_putnbr_base_c(va_arg(valist, unsigned int), UHEXA, fd, &count);
	else
		count += ft_putchar_fd(c, fd);
	return (count);
}
