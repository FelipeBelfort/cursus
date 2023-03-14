/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:39:27 by fbelfort          #+#    #+#             */
/*   Updated: 2023/03/14 13:19:17 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	display_maze(t_long *game, void *win)
{
	size_t	x;
	size_t	y;
	// size_t	img;
	size_t	block_x;
	size_t	block_y;
	size_t	block_size = 64;

	// if (game->count_c == 0)
	// 	img = IMG_E2;
	// else
	// 	img = IMG_E1;
	y = -1;
	while (++y < game->rows)
	{
		x = -1;
		while (++x < game->cols)
		{
			block_x = x * block_size;
			block_y = y * block_size;
			if (x == game->p->x && y == game->p->y)
				mlx_put_image_to_window(game->mlx, win, game->p->img, block_x, block_y);
			else
			{
				if (game->map[y][x] == '0' || game->map[y][x] == 'b')
					mlx_put_image_to_window(game->mlx, win, game->text[IMG_0], block_x, block_y);
				if (game->map[y][x] == '1')
					mlx_put_image_to_window(game->mlx, win, game->text[IMG_1], block_x, block_y);
				if (game->map[y][x] == 'E')
					mlx_put_image_to_window(game->mlx, win, game->e->img, block_x, block_y);
				if (game->map[y][x] == 'C')
					mlx_put_image_to_window(game->mlx, win, game->text[IMG_C], block_x, block_y);
			}
		}
	}
}

// void	free_tlong(t_long *game)
// {

// }

int	close_window(void *param)
{
	(void) param;
	exit(0);
}

int	key_press(int key, void *param)
{
	t_long	*game;

	game = (t_long *) param;
	if (key == K_ESC)
		close_window(game);
	if (key == K_UP || key == K_W)
	{
		if (game->map[game->p->y - 1][game->p->x] != '1')
		{
			game->p->y--;
			if (game->map[game->p->y][game->p->x] == 'C')
			{
				game->map[game->p->y][game->p->x] = '0';
				game->count_c--;
			}
		}
	}
	if (key == K_DOWN || key == K_S)
	{
		if (game->map[game->p->y + 1][game->p->x] != '1')
		{
			game->p->y++;
			if (game->map[game->p->y][game->p->x] == 'C')
			{
				game->map[game->p->y][game->p->x] = '0';
				game->count_c--;
			}
		}
	}
	if (key == K_LEFT || key == K_A)
	{
		game->p->img = game->text[IMG_P2];
		if (game->map[game->p->y][game->p->x - 1] != '1')
		{
			game->p->x--;
			if (game->map[game->p->y][game->p->x] == 'C')
			{
				game->map[game->p->y][game->p->x] = '0';
				game->count_c--;
			}
		}
	}
	if (key == K_RIGHT || key == K_D)
	{
		game->p->img = game->text[IMG_P1];
		if (game->map[game->p->y][game->p->x + 1] != '1')
		{
			game->p->x++;
			if (game->map[game->p->y][game->p->x] == 'C')
			{
				game->map[game->p->y][game->p->x] = '0';
				game->count_c--;
			}
		}
	}
	printf("count_c ==> %d\n", game->count_c);
	if (game->count_c == 0)
		game->e->img = game->text[IMG_E2];
	mlx_clear_window(game->mlx, game->win);
	display_maze(game, game->win);
	return (0);
}

int	key_press_test(int key, void *param)
{
	(void) param;
	printf("key code ==> %d\n", key);
	return (0);
}

int	launch_game(t_long *game)
{
	game->mlx = mlx_init();
	// game->img = mlx_new_image(game->mlx, game->cols * 64, game->rows * 64);
	// game->addr = mlx_get_data_addr(game->img, &(game->bpp), &(game->line), &(game->edian));
	game->win = mlx_new_window(game->mlx, game->cols * 64, game->rows * 64, "so_long -> fbelfort");




	game->text[IMG_0] = mlx_xpm_file_to_image(game->mlx, "./imgs/grass.xpm",
			&game->widthtext[IMG_0], &game->heighttext[IMG_0]);
	game->ptr_text[IMG_0] = mlx_get_data_addr(game->text[IMG_0],
			&(game->bpp_text[IMG_0]), &(game->sline_text[IMG_0]), &(game->ed_text[IMG_0]));
	game->text[IMG_1] = mlx_xpm_file_to_image(game->mlx, "./imgs/stone.xpm",
			&game->widthtext[IMG_1], &game->heighttext[IMG_1]);
	game->ptr_text[IMG_1] = mlx_get_data_addr(game->text[IMG_1],
			&(game->bpp_text[IMG_1]), &(game->sline_text[IMG_1]), &(game->ed_text[IMG_1]));
	game->text[IMG_E1] = mlx_xpm_file_to_image(game->mlx, "./imgs/opened_grave.xpm",
			&game->widthtext[IMG_E1], &game->heighttext[IMG_E1]);
	game->ptr_text[IMG_E1] = mlx_get_data_addr(game->text[IMG_E1],
			&(game->bpp_text[IMG_E1]), &(game->sline_text[IMG_E1]), &(game->ed_text[IMG_E1]));
	game->text[IMG_E2] = mlx_xpm_file_to_image(game->mlx, "./imgs/closed_grave.xpm",
			&game->widthtext[IMG_E2], &game->heighttext[IMG_E2]);
	game->ptr_text[IMG_E2] = mlx_get_data_addr(game->text[IMG_E2],
			&(game->bpp_text[IMG_E2]), &(game->sline_text[IMG_E2]), &(game->ed_text[IMG_E2]));
	game->text[IMG_P1] = mlx_xpm_file_to_image(game->mlx, "./imgs/zombie_right.xpm",
			&game->widthtext[IMG_P1], &game->heighttext[IMG_P1]);
	game->ptr_text[IMG_P1] = mlx_get_data_addr(game->text[IMG_P1],
			&(game->bpp_text[IMG_P1]), &(game->sline_text[IMG_P1]), &(game->ed_text[IMG_P1]));
	game->text[IMG_P2] = mlx_xpm_file_to_image(game->mlx, "./imgs/zombie_left.xpm",
			&game->widthtext[IMG_P2], &game->heighttext[IMG_P2]);
	game->ptr_text[IMG_P2] = mlx_get_data_addr(game->text[IMG_P2],
			&(game->bpp_text[IMG_P2]), &(game->sline_text[IMG_P2]), &(game->ed_text[IMG_P2]));
	game->text[IMG_C] = mlx_xpm_file_to_image(game->mlx, "./imgs/brain.xpm",
			&game->widthtext[IMG_C], &game->heighttext[IMG_C]);
	game->ptr_text[IMG_C] = mlx_get_data_addr(game->text[IMG_C],
			&(game->bpp_text[IMG_C]), &(game->sline_text[IMG_C]), &(game->ed_text[IMG_C]));
	game->p->img = game->text[IMG_P1];
	game->e->img = game->text[IMG_E1];

	display_maze(game, game->win);

	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_key_hook(game->win, key_press, game);
	mlx_loop(game->mlx);
	return (0);
}
