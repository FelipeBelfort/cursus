/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:23:33 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/02/04 19:13:16 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_searcheol(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\n')
			return (i + 1);
	}
	return (0);
}

void	ft_lstfree(t_gnl **lst)
{
	t_gnl	*ptr_next;
	t_gnl	*ptr_tmp;

	ptr_tmp = *lst;
	while (ptr_tmp)
	{
		ptr_next = ptr_tmp->next;
		if (ptr_tmp->content)
			free(ptr_tmp->content);
		free(ptr_tmp);
		ptr_tmp = ptr_next;
	}
	*lst = NULL;
}
