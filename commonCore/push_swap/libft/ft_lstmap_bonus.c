/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 22:55:05 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2022/12/02 16:51:17 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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