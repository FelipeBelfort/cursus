/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:53:11 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2022/12/08 13:52:38 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putchar_fd(char c, int fd)
{
	int	counter;

	counter = write(fd, &c, 1);
	return (counter);
}

int	ft_putstr_fd(char *s, int fd)
{
	size_t	len;
	int		counter;

	len = ft_strlen(s);
	counter = write(fd, s, len);
	return (counter);
}
