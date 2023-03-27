/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:07:02 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/03/20 13:01:31 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	mv_manager(t_long *game, size_t target_x, size_t target_y, int key)
{
	if (game->map[game->p->y + target_y][game->p->x + target_x] != '1')
	{
		game->p->x += target_x;
		game->p->y += target_y;
		game->mv_count++;
		if (game->map[game->p->y][game->p->x] == 'C')
		{
			game->map[game->p->y][game->p->x] = '0';
			game->count_c--;
		}
	}
	if (key == K_LEFT || key == K_A)
		game->p->img = game->text[IMG_P2];
	if (key == K_RIGHT || key == K_D)
		game->p->img = game->text[IMG_P1];
}

/**
 * @brief
 * It takes the pressed key as argument
 * ESC -> end the game
 * 'W', 'A', 'S', 'D' and the arrows are accepted and will
 * do the matching movement if the target is not a wall.
 * It will update the mv_count and the player's position
 * if that's the case it will also update the colectible's position.
 * At last it will reboot the image window.
*/
int	key_press(int key, void *param)
{
	t_long	*game;

	game = (t_long *) param;
	if (key == K_ESC)
		close_window(game);
	if (key == K_UP || key == K_W)
		mv_manager(game, 0, -1, key);
	if (key == K_DOWN || key == K_S)
		mv_manager(game, 0, 1, key);
	if (key == K_LEFT || key == K_A)
		mv_manager(game, -1, 0, key);
	if (key == K_RIGHT || key == K_D)
		mv_manager(game, 1, 0, key);
	if (game->count_c == 0)
		game->e->img = game->text[IMG_E2];
	display_maze(game);
	return (0);
}
