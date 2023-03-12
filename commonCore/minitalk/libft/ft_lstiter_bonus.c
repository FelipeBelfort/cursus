/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 22:53:23 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/02/04 21:25:59 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief
 * Iterates the list ’lst’ and applies the function ’f’
 *  on the content of each node.

*/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst && f)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}
