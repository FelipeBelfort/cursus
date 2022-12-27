/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:23:37 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2022/12/27 04:13:20 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	size_t			len;
	struct s_list	*next;
}				t_list;

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strndup(const char *s1, size_t len);
size_t	ft_searcheol(char *str);
void	ft_lstfree(t_list **lst);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#endif