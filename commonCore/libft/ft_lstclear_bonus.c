/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 22:51:07 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2022/11/30 12:11:15 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void
*))
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
