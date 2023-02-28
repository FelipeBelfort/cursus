/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 21:48:17 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/02/23 22:57:40 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "../libft/libft.h"

typedef struct s_item
{
	int		x;
	int		y;
	t_item	*next;
	//image?
}	t_item;

typedef struct s_long
{
	int		count_p;
	int		count_e;
	int		count_c;
	int		rows;
	int		cols;
	char	**map;
	t_item	*p;
	t_item	*e;
	t_item	*c;
}	t_long;

void	ft_error(void);

#endif
