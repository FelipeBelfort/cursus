/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:23:33 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/03/15 19:22:15 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_searcheol(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
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
