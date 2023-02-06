/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 22:55:05 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/02/04 21:28:33 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief
 * Iterates the list ’lst’ and applies the function ’f’
 *  on the content of each node. 
 * Creates a new list resulting of the successive 
 * applications of the function ’f’. 
 * The ’del’ function is used to delete the content
 *  of a node if needed.
 * @return
 * The new list.
NULL if the allocation fails.
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*mapped_lst;
	t_list	*ptr;

	if (!lst || !f || !del)
		return (NULL);
	mapped_lst = ft_lstnew(f(lst->content));
	if (!mapped_lst)
		ft_lstclear(&mapped_lst, del);
	lst = lst->next;
	while (lst)
	{
		ptr = ft_lstnew(f(lst->content));
		ft_lstadd_back(&mapped_lst, ptr);
		if (!ptr->content)
			ft_lstclear(&ptr, del);
		lst = lst->next;
	}
	return (mapped_lst);
}
