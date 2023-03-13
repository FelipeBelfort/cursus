/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 21:48:17 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/03/13 21:00:17 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include "libft.h"
# include "mlx.h"

typedef struct s_item
{
	size_t			x;
	size_t			y;
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

	void	*img;
	char	*addr;
	int		bpp;
	int		line;
	int		edian;

	int		bpp_text[5];
	int		sline_text[5];
	int		ed_text[5];
	int		heighttext[5];
	int		widthtext[5];
	char	*ptr_text[5];
	void	*text[5];

	void	*mlx;
	void	*win;
}	t_long;

void	ft_error(void);
int		parse_map(t_long *game, char *path);

# ifndef K_ESC
#  define K_ESC 53
#  define K_UP 65362
#  define K_DOWN 65364
#  define K_LEFT 65361
#  define K_RIGHT 65363
#  define K_W 119
#  define K_S 115
#  define K_A 97
#  define K_D 100
# endif

#endif
