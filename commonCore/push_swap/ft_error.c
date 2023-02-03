/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:34:00 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/02/03 16:15:12 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 * frees the container, writes un error message
 * and terminates the program.
*/
void	ft_error(t_pushswap *bin)
{
	free_container(bin);
	ft_putendl_fd("Error", 1);
	exit(0);
}
