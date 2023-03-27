/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:39:27 by fbelfort          #+#    #+#             */
/*   Updated: 2023/03/23 17:40:14 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/**
 * @brief
 * Prints the number of moves in the terminal
 * if there are no more 'C's and the player is in the exit's position
 * it will finish the game.
*/
static void	print_mv(t_long	*game)
{
	if (game->endofgame)
		return ;
	if (game->mv_count > 0 && game->mv_count < 10)
		ft_printf("\b%d", game->mv_count);
	if (game->mv_count >= 10 && game->mv_count <= 99)
		ft_printf("\b\b%d", game->mv_count);
	if (game->mv_count >= 100)
		ft_printf("\b\b\b%d", game->mv_count);
	if (game->mv_count >= 1000)
		ft_printf("\b\b\b\b%d", game->mv_count);
	if (game->count_c == 0 && game->p->x == game->e->x
		&& game->p->y == game->e->y)
		win_endgame(game);
}

/**
 * @brief
 * It will put the image in the window based on the character of
 * the given position.
*/
static void	ft_put_img(t_long *game, size_t x, size_t y)
{
	int		(*putimg)();
	void	*mlx;
	void	*win;

	win = game->win;
	mlx = game->mlx;
	putimg = mlx_put_image_to_window;
	if (x == game->p->x && y == game->p->y)
		putimg(mlx, game->win, game->p->img, x * IMG_SIZE, y * IMG_SIZE);
	else
	{
		if ((x != game->p->x || y != game->p->y)
			&& (game->map[y][x] == '0' || game->map[y][x] == 'b'))
			putimg(mlx, win, game->text[IMG_0], x * IMG_SIZE, y * IMG_SIZE);
		if ((x != game->p->x || y != game->p->y) && game->map[y][x] == '1')
			putimg(mlx, win, game->text[IMG_1], x * IMG_SIZE, y * IMG_SIZE);
		if ((x != game->p->x || y != game->p->y) && game->map[y][x] == 'E')
			putimg(mlx, win, game->e->img, x * IMG_SIZE, y * IMG_SIZE);
		if ((x != game->p->x || y != game->p->y) && game->map[y][x] == 'C')
			putimg(mlx, win, game->text[IMG_C], x * IMG_SIZE, y * IMG_SIZE);
	}
}

/**
 * @brief
 * It will iterates over the map to put the image in the window
 * showing the game's display
*/
void	display_maze(t_long *game)
{
	size_t	x;
	size_t	y;

	y = -1;
	while (++y < game->rows)
	{
		x = -1;
		while (++x < game->cols)
		{
			ft_put_img(game, x, y);
		}
	}
	print_mv(game);
}

/**
 * @brief
 * It takes the xpm files, creates the images and puts them in the
 * t_long->text with the matching code.
 *
*/
void	apply_textures(t_long *g)
{
	void	*(*xpm_to_img)();

	xpm_to_img = mlx_xpm_file_to_image;
	g->text[IMG_0] = xpm_to_img(g->mlx, "./imgs/grass.xpm",
			&g->w_txt[IMG_0], &g->h_txt[IMG_0]);
	g->text[IMG_1] = xpm_to_img(g->mlx, "./imgs/stone.xpm",
			&g->w_txt[IMG_1], &g->h_txt[IMG_1]);
	g->text[IMG_E1] = xpm_to_img(g->mlx, "./imgs/closed_grave.xpm",
			&g->w_txt[IMG_E1], &g->h_txt[IMG_E1]);
	g->text[IMG_E2] = xpm_to_img(g->mlx, "./imgs/opened_grave.xpm",
			&g->w_txt[IMG_E2], &g->h_txt[IMG_E2]);
	g->text[IMG_P1] = xpm_to_img(g->mlx, "./imgs/zombie_right.xpm",
			&g->w_txt[IMG_P1], &g->h_txt[IMG_P1]);
	g->text[IMG_P2] = xpm_to_img(g->mlx, "./imgs/zombie_left.xpm",
			&g->w_txt[IMG_P2], &g->h_txt[IMG_P2]);
	g->text[IMG_C] = xpm_to_img(g->mlx, "./imgs/brain.xpm",
			&g->w_txt[IMG_C], &g->h_txt[IMG_C]);
}