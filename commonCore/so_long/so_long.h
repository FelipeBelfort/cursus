/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 21:48:17 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/03/11 15:23:28 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "minilibx-linux/mlx.h"

typedef struct s_item
{
	int				x;
	int				y;
	struct s_item	*next;
	//image?
}	t_item;

typedef struct s_long
{
	int		count_p;
	int		count_e;
	int		count_c;
	size_t	rows;
	size_t	cols;
	char	**map;
	t_item	*p;
	t_item	*e;
	t_item	*c;
	void	*mlx;
	void	*win;
}	t_long;

void	ft_error(void);
int		parse_map(t_long *game, char *path);

#endif
