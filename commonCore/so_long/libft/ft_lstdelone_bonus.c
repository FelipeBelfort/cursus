/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 22:48:51 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/02/04 21:23:47 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief
 * Takes as a parameter a node and frees the memory of the node’s content 
 * using the function ’del’ given as a parameter and free the node.
 *  The memory of ’next’ must not be freed.
*/
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	t_list	*tmp;

	if (lst && del)
	{
		tmp = lst;
		lst = lst->next;
		(*del)(tmp->content);
		free(tmp);
	}
}
