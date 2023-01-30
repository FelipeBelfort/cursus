/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:23:37 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/01/30 15:32:55 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_gnl
{
	void			*content;
	size_t			len;
	struct s_gnl	*next;
}				t_gnl;

char	*get_next_line(int fd);
size_t	ft_gnlstrlen(const char *s);
void	*ft_gnlmemcpy(void *dst, const void *src, size_t n);
char	*ft_gnlstrndup(const char *s1, size_t len);
size_t	ft_searcheol(char *str);
void	ft_lstfree(t_gnl **lst);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

#endif