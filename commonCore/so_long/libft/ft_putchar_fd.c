/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:02:25 by fbelfort          #+#    #+#             */
/*   Updated: 2023/02/04 21:15:50 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief
 * Outputs the character ’c’ to the given file descriptor.
 * @return
 * 1 if it works or -1 if there is a problem with the file descriptor
*/
int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}
