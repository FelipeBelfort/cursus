/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 22:48:51 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2022/11/30 11:49:36 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void
*))
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
