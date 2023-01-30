/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:23:33 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/01/30 15:33:27 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_gnlstrlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_gnlmemcpy(void *dst, const void *src, size_t n)
{
	char	*str_src;
	char	*str_dst;
	size_t	i;

	i = 0;
	str_src = (char *) src;
	str_dst = (char *) dst;
	if (n == 0 || dst == src)
		return (str_dst);
	while (i < n)
	{
		str_dst[i] = str_src[i];
		i++;
	}
	return (str_dst);
}

char	*ft_gnlstrndup(const char *s1, size_t len)
{
	char	*src_copy;

	src_copy = malloc((len + 1) * sizeof(char));
	if (!src_copy)
		return (NULL);
	ft_gnlmemcpy(src_copy, s1, len);
	src_copy[len] = '\0';
	return (src_copy);
}

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
