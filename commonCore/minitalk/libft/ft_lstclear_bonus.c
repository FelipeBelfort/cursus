/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 22:51:07 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/02/04 21:24:46 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief
 * Deletes and frees the given node and every successor of that node,
 *  using the function ’del’ and free(3).
 * Finally, the pointer to the list must be set to NULL.
*/
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;

	while (*lst && del)
	{
		ptr = (*lst)->next;
		(*del)((*lst)->content);
		free((*lst));
		*lst = ptr;
	}
	*lst = NULL;
}
