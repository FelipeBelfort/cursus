/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:33:51 by fbelfort          #+#    #+#             */
/*   Updated: 2022/12/12 13:01:35 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_fstr(const char *str, va_list valist, int fd)
{
	int		i;
	int		counter;

	i = -1;
	counter = 0;
	while (str[++i])
	{
		if (str[i] != '%')
			counter += ft_putchar_fd(str[i], fd);
		else
		{
			if (str[++i])
			{
				while (str[i] == ' ')
					i++;
				counter += ft_parsechar(str[i], valist, fd);
			}
		}
	}
	return (counter);
}

int	ft_printf(const char *str, ...)
{
	int		fd;
	int		counter;
	va_list	valist;

	fd = 1;
	counter = write(fd, 0, 0);
	if (counter != 0)
		return (-1);
	va_start(valist, str);
	counter = ft_fstr(str, valist, fd);
	va_end(valist);
	return (counter);
}
