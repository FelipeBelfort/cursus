/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 22:51:07 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/03/16 15:25:53 by fbelfort         ###   ########.fr       */
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
		if ((*lst)->content)
			(*del)((*lst)->content);
		free((*lst));
		*lst = ptr;
	}
	*lst = NULL;
}
