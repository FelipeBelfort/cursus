/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:23:33 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/03/16 22:29:24 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char	*ft_makeline(t_gnl **rfile, size_t len)
{
	char	*line;
	t_gnl	*ptr;
	size_t	i;

	i = 0;
	ptr = *rfile;
	if (!ptr)
		return (NULL);
	line = ft_calloc(sizeof(char), (len + 1));
	if (!line)
	{
		ft_lstfree(rfile);
		return (NULL);
	}
	while (ptr)
	{
		ft_memcpy(&line[i], ptr->content, ptr->len);
		i += ptr->len;
		ptr = ptr->next;
	}
	line[len] = 0;
	ft_lstfree(rfile);
	return (line);
}
