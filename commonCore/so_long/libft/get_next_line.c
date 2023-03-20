/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 03:03:39 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/03/19 18:56:23 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lstaddnew(t_gnl **lst, char *content, size_t len)
{
	t_gnl	*node;
	t_gnl	*ptr;

	node = malloc(sizeof(t_gnl));
	if (!node)
		return ;
	node->content = ft_strndup(content, len);
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

static char	*get_read_info(int fd, int *tmp_c, int *ceol, int *buf_c)
{
	char	*buf;
	int		readchar;

	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (NULL);
	readchar = read(fd, buf, BUFFER_SIZE);
	*tmp_c = readchar;
	if (!readchar)
	{
		free(buf);
		return (NULL);
	}
	*ceol = ft_searcheol(buf);
	*buf_c += readchar;
	return (buf);
}

static char	*ft_search_nl(int fd, t_gnl **rfile, int buf_c)
{
	char	*buf;
	char	*line;
	int		tmp_c;
	int		ceol;

	line = NULL;
	while (!line)
	{
		buf = get_read_info(fd, &tmp_c, &ceol, &buf_c);
		if (!tmp_c)
			line = ft_makeline(rfile, buf_c);
		if (!buf)
			break ;
		if (!ceol)
			ft_lstaddnew(rfile, buf, tmp_c);
		else
		{
			ft_lstaddnew(rfile, buf, ceol);
			line = ft_makeline(rfile, buf_c - (tmp_c - ceol));
			if (ceol < tmp_c)
				ft_lstaddnew(rfile, &buf[ceol], tmp_c - ceol);
		}
		free(buf);
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
		line = ft_strndup((*rfile)->content, ceol);
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
		buf_c = ft_strlen(rfile->content);
		line = ft_get_nl_in_line(&rfile, buf_c);
	}
	if (!line)
		line = ft_search_nl(fd, &rfile, buf_c);
	return (line);
}
