/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 03:03:39 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/01/30 15:32:55 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_lstaddnew(t_gnl **lst, char *content, size_t len)
{
	t_gnl	*node;
	t_gnl	*ptr;

	node = malloc(sizeof(t_gnl));
	if (!node)
		return ;
	node->content = ft_gnlstrndup(content, len);
	if (!node->content)
	{
		free(node);
		return ;
	}
	node->len = len;
	node->next = NULL;
	if (*lst == NULL)
		*lst = node;
	else
	{
		ptr = *lst;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = node;
	}
}

static char	*ft_makeline(t_gnl **rfile, size_t len)
{
	char	*line;
	t_gnl	*ptr;
	size_t	i;

	i = 0;
	ptr = *rfile;
	if (!ptr)
		return (NULL);
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
	{
		ft_lstfree(rfile);
		return (NULL);
	}
	while (ptr)
	{
		ft_gnlmemcpy(&line[i], ptr->content, ptr->len);
		i += ptr->len;
		ptr = ptr->next;
	}
	line[len] = 0;
	ft_lstfree(rfile);
	return (line);
}

static char	*ft_search_nl(int fd, t_gnl **rfile, int buf_c)
{
	char			buf[BUFFER_SIZE + 1];
	char			*line;
	int				tmp_c;
	int				ceol;

	line = NULL;
	buf[BUFFER_SIZE] = 0;
	while (!line)
	{
		tmp_c = read(fd, buf, BUFFER_SIZE);
		ceol = ft_searcheol(buf);
		buf_c += tmp_c;
		if (!tmp_c)
			return (ft_makeline(rfile, buf_c));
		if (!ceol)
			ft_lstaddnew(rfile, buf, tmp_c);
		else
		{
			ft_lstaddnew(rfile, buf, ceol);
			line = ft_makeline(rfile, buf_c - (tmp_c - ceol));
			if (ceol < tmp_c)
				ft_lstaddnew(rfile, &buf[ceol], tmp_c - ceol);
		}
	}
	return (line);
}

char	*ft_get_nl_in_line(t_gnl **rfile, size_t len)
{
	char	*line;
	char	*line2;
	size_t	ceol;

	ceol = ft_searcheol((*rfile)->content);
	if (!ceol)
		return (NULL);
	else if (ceol == len)
		return (ft_makeline(rfile, len));
	else
	{
		line = ft_gnlstrndup((*rfile)->content, ceol);
		line2 = (*rfile)->content;
		(*rfile)->content = NULL;
		ft_lstfree(rfile);
		ft_lstaddnew(rfile, &line2[ceol], len - ceol);
		free(line2);
		return (line);
	}
}

char	*get_next_line(int fd)
{
	static t_gnl	*rfile = NULL;
	char			*line;
	int				buf_c;

	line = NULL;
	if (BUFFER_SIZE < 1 || read(fd, line, 0) != 0)
	{
		ft_lstfree(&rfile);
		return (NULL);
	}
	buf_c = 0;
	if (rfile)
	{
		buf_c = ft_gnlstrlen(rfile->content);
		line = ft_get_nl_in_line(&rfile, buf_c);
	}
	if (!line)
		line = ft_search_nl(fd, &rfile, buf_c);
	return (line);
}
