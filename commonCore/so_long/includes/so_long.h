/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 21:48:17 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/03/15 16:56:32 by FelipeBelfo      ###   ########.fr       */
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
	char			*img;
}	t_item;

typedef struct s_long
{
	int		count_p;
	int		count_e;
	int		count_c;
	size_t	mv_count;
	size_t	rows;
	size_t	cols;
	char	**map;
	t_item	*p;
	t_item	*e;
	t_item	*c;

	int		bpp_txt[8];
	int		sline_txt[8];
	int		ed_txt[8];
	int		h_txt[8];
	int		w_txt[8];
	char	*ptr_txt[8];
	void	*text[8];

	void	*mlx;
	void	*win;
}	t_long;

/* boolean tests */

int		is_empty(char **map);
int		is_closed(char *line);
int		is_forbidden(char *line);
int		is_onlybrick(char *line);

/* items utils */

t_item	*pick_items(char **map, int c);
void	put_itemsback(t_long *game);
int		item_count(t_item *items);
void	item_addback(t_item **list, t_item *node);
t_item	*item_newnode(int y, int x);

/* key press management */

int		key_press(int key, void *param);

/* display */

void	display_maze(t_long *game);
void	apply_textures(t_long *g);

/* map parsing */

int		parse_map(t_long *game, char *path);
int		create_maptab(t_long *game, t_list *map);

/* end of game management */

void	ft_error(t_long *game, int code);
int		close_window(void *param);
void	win_endgame(t_long *game);

/* free */

void	free_tlong(t_long *game);

# define IMG_0 0
# define IMG_1 1
# define IMG_C 2
# define IMG_P1 3
# define IMG_P2 4
# define IMG_E1 5
# define IMG_E2 6
# define IMG_SIZE 64

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
