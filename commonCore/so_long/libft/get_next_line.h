/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:23:37 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/02/04 19:13:16 by FelipeBelfo      ###   ########.fr       */
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
size_t	ft_searcheol(char *str);
void	ft_lstfree(t_gnl **lst);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#endif