/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:33:51 by fbelfort          #+#    #+#             */
/*   Updated: 2022/12/06 17:54:21 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		fd;
	int		counter;
	va_list	valist;

	i = -1;
	fd = 1;
	counter = write(fd, 0, 0);
	if (counter != 0)
		return (-1);
	va_start(valist, str);
	while (str[++i])
	{
		if (str[i] != '%')
			counter += ft_putchar_fd(str[i], fd);
		else
		{
			if (str[++i])
				counter += ft_parsechar(str[i], valist, fd);
			else
				return (-1);
		}
	}
	va_end(valist);
	return (counter);
}
