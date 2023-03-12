/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:39:27 by fbelfort          #+#    #+#             */
/*   Updated: 2023/03/13 00:09:17 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	display_maze(t_long *game, void *win)
{
	size_t	x;
	size_t	y;
	size_t	block_x;
	size_t	block_y;
	size_t	block_size = 64;

	y = -1;
	while (++y < game->rows)
	{
		x = -1;
		while (++x < game->cols)
		{
			block_x = x * block_size;
			block_y = y * block_size;
			if (game->map[y][x] == '0' || game->map[y][x] == 'b')
				mlx_put_image_to_window(game->mlx, win, game->text[0], block_x, block_y);
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, win, game->text[1], block_x, block_y);
			if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, win, game->text[2], block_x, block_y);
			if (game->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, win, game->text[3], block_x, block_y);
			if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, win, game->text[4], block_x, block_y);
		}
	}
}


int	launch_game(t_long *game)
{
	game->mlx = mlx_init();
	game->img = mlx_new_image(game->mlx, game->cols * 64, game->rows * 64);
	game->addr = mlx_get_data_addr(game->img, &(game->bpp), &(game->line), &(game->edian));
	game->win = mlx_new_window(game->mlx, game->cols * 64, game->rows * 64, "so_long -> fbelfort");




	game->text[0] = mlx_xpm_file_to_image(game->mlx, "./imgs/grass.xpm",
			&game->widthtext[0], &game->heighttext[0]);
	game->ptr_text[0] = mlx_get_data_addr(game->text[0],
			&(game->bpp_text[0]), &(game->sline_text[0]), &(game->ed_text[0]));
	game->text[1] = mlx_xpm_file_to_image(game->mlx, "./imgs/stone.xpm",
			&game->widthtext[1], &game->heighttext[1]);
	game->ptr_text[1] = mlx_get_data_addr(game->text[1],
			&(game->bpp_text[1]), &(game->sline_text[1]), &(game->ed_text[1]));
	game->text[2] = mlx_xpm_file_to_image(game->mlx, "./imgs/opened_grave.xpm",
			&game->widthtext[2], &game->heighttext[2]);
	game->ptr_text[2] = mlx_get_data_addr(game->text[2],
			&(game->bpp_text[2]), &(game->sline_text[2]), &(game->ed_text[2]));
	game->text[3] = mlx_xpm_file_to_image(game->mlx, "./imgs/zombie_right.xpm",
			&game->widthtext[3], &game->heighttext[3]);
	game->ptr_text[3] = mlx_get_data_addr(game->text[3],
			&(game->bpp_text[3]), &(game->sline_text[3]), &(game->ed_text[3]));
	game->text[4] = mlx_xpm_file_to_image(game->mlx, "./imgs/brain.xpm",
			&game->widthtext[4], &game->heighttext[4]);
	game->ptr_text[4] = mlx_get_data_addr(game->text[4],
			&(game->bpp_text[4]), &(game->sline_text[4]), &(game->ed_text[4]));

	display_maze(game, game->win);

	mlx_loop(game->mlx);
	return (0);
}
