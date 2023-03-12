/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:39:27 by fbelfort          #+#    #+#             */
/*   Updated: 2023/03/12 19:59:37 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			printf("oi\n");
		x = -1;
		while (++x < game->cols)
		{
			block_x = x * block_size;
			block_y = y * block_size;
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, win, game->text[0], block_x, block_y);
			if (game->map[y][x] == '0' || game->map[y][x] == 'b')
				mlx_put_image_to_window(game->mlx, win, game->text[1], block_x, block_y);
		}

			printf("ok  ==> x = %zu  | y = %zu\n", x, y);
	}

}


int	launch_game(t_long *game)
{
	game->mlx = mlx_init();
	game->img = mlx_new_image(game->mlx, game->cols * 64, game->rows * 64);
	game->addr = mlx_get_data_addr(game->img, &(game->bpp), &(game->line), &(game->edian));
	game->win = mlx_new_window(game->mlx, game->cols * 64, game->rows * 64, "so_long");




	game->text[0] = mlx_xpm_file_to_image(game->mlx, "./imgs/bottom-64.xpm",
			&game->widthtext[0], &game->heighttext[0]);
	game->ptr_text[0] = mlx_get_data_addr(game->text[0],
			&(game->bpp_text[0]), &(game->sline_text[0]), &(game->ed_text[0]));
	game->text[1] = mlx_xpm_file_to_image(game->mlx, "./imgs/dalle-64t.xpm",
			&game->widthtext[1], &game->heighttext[1]);
	game->ptr_text[1] = mlx_get_data_addr(game->text[1],
			&(game->bpp_text[1]), &(game->sline_text[1]), &(game->ed_text[1]));
	// game->text[3] = mlx_xpm_file_to_image(game->mlx, "./imgs/player.xpm",
	// 		&game->widthtext[3], &game->heighttext[3]);
	// game->ptr_text[3] = mlx_get_data_addr(game->text[3],
	// 		&(game->bpp_text[3]), &(game->sline_text[3]), &(game->ed_text[3]));
	// game->text[2] = mlx_xpm_file_to_image(game->mlx, "./imgs/invader.xpm",
	// 		&game->widthtext[2], &game->heighttext[2]);
	// game->ptr_text[2] = mlx_get_data_addr(game->text[2],
	// 		&(game->bpp_text[2]), &(game->sline_text[2]), &(game->ed_text[2]));
	// game->text[4] = mlx_xpm_file_to_image(game->mlx, "./imgs/exit.xpm",
	// 		&game->widthtext[4], &game->heighttext[4]);
	// game->ptr_text[4] = mlx_get_data_addr(game->text[4],
	// 		&(game->bpp_text[4]), &(game->sline_text[4]), &(game->ed_text[4]));

	display_maze(game, game->win);
	// t_item	*ptr = game->c;
	// while (ptr)
	// {
	// 	mlx_put_image_to_window(game->mlx, game->win, game->text[2], ptr->x, ptr->y);
	// 	ptr = ptr->next;
	// }
	// mlx_put_image_to_window(game->mlx, game->win, game->text[3], game->p->x, game->p->y);


	// mlx_hook(sl->win, 2, 1L, ft_key_hit, sl);
	// mlx_hook(sl->win, 15, 1L << 16, visible, sl);
	// mlx_hook(sl->win, CLOSERED, 1L << 17, closebyredbutton, sl);
	// mlx_loop_hook(sl->mlx, key_loop, sl);
	mlx_loop(game->mlx);
	return (0);
}
