/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 03:03:39 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2022/12/16 13:49:44 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_lstaddnew(t_list *lst, char *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return ;
	node->content = content;
	node->next = NULL;
	if (!lst)
	{
		lst = node;
		return ;
	}
	while (lst->next)
		lst = lst->next;
	lst->next = node;
}

static void	ft_lstfree(t_list *lst)
{
	t_list	*ptr;

	while (lst)
	{
		ptr = lst->next;
		free(lst->content);
		free(lst);
		lst = ptr;
	}
}

static char	*ft_makeline(t_list *rfile, size_t len)
{
	size_t	i;
	size_t	rfile_len;
	char	*line;
	t_list	*ptr;

	i = 0;
	ptr = rfile;
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	while (i < len && ptr)
	{
		rfile_len = ft_strlen(ptr->content);
		ft_memcpy(&line[i], ptr->content, rfile_len);
		i += rfile_len;
		ptr = ptr->next;
	}
	ft_lstfree(rfile);
	line[len - 1] = 0;
	return (line);
}

static char	*ft_search_line(int fd, t_list *rfile, char *buf, int buf_c)
{
	char	*line;
	int		ceol;
	int		c;

	line = NULL;
	while (!line)
	{
		c += read(fd, buf, BUFFER_SIZE);
		ceol = ft_strchr(buf, '\n');
		if (ceol || !buf || !c)
		{
			if (!rfile && ceol == c - 1)
				return (buf);
			else if ((!buf || !c) && rfile)
				line = ft_makeline(rfile, buf_c + c);
			else if (!rfile)
				return (NULL);
			else
			{
				ft_lstaddnew(rfile, ft_substr(buf, 0, ceol));
				line = ft_makeline(rfile, buf_c - (BUFFER_SIZE - ceol));
				buf_c = BUFFER_SIZE - ceol;
				ft_lstaddnew(rfile, ft_substr(buf, ceol, buf_c));
			}
		}
		ft_lstaddnew(rfile, buf);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static t_list	*rfile = NULL;
	char			*line;
	char			*buf;
	int				buf_c;

	line = NULL;
	if (read(fd, "", 0) != 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	buf[BUFFER_SIZE] = 0;
	buf_c = 0;
	line = ft_search_line(fd, rfile, buf, buf_c);
	free(buf);
	return (line);
}
