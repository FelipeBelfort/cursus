/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:53:11 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2022/12/06 21:45:08 by FelipeBelfo      ###   ########.fr       */
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

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (size && count > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, count * size);
	return (ptr);
}

void	*ft_memset(void *b, int c, size_t len)
{
	int		i;
	char	*ptr_p;

	i = 0;
	ptr_p = (char *)b;
	while (len--)
		ptr_p[i++] = c;
	return (b);
}
