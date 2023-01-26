/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:34:00 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/01/24 19:37:43 by fbelfort         ###   ########.fr       */
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
