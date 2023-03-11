/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:12:30 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/02/04 19:19:22 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"

int		ft_printf(const char *str, ...);
int		ft_parsechar(char c, va_list valist, int fd);

# define DECIMAL "0123456789"
# define LHEXA "0123456789abcdef"
# define UHEXA "0123456789ABCDEF"

#endif