/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endgame.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 22:32:15 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/03/15 19:04:53 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

/**
 * @brief
 * In case of an error it will print the error message,
 * free all and exit the program.
 * If t_long = NULL it will not be freed
 * and if the char* = NULL it will print
 * only the message from errno.
 * @param t_long* a pointer to the structure to be freed
 * @param char* the message to be writen
*/
void	ft_error(t_long *game, int code)
{
	ft_putstr_fd("Error -> ", 2);
	if (code == 1)
		perror("Failed memory allocation");
	if (code == 2)
		perror("Invalid file. Attended a .ber");
	if (code == 3)
		perror("It needs to have at least 3 rows or columns");
	if (code == 4)
		perror("Wrong number of player, exit or colectible");
	if (code == 5)
		perror("The map is not rectangular");
	if (code == 6)
		perror("There are unknown characters in the map");
	if (code == 7)
		perror("The map need to be closed by walls");
	if (code == 8)
		perror("There is no valid path in the map");
	if (code == 9)
		perror("The map file seems broken");
	else
		perror(NULL);
	if (game)
		free_tlong(game);
	exit(EXIT_FAILURE);
}

/**
 * @brief
 * Frees the t_long, print a message and end the program.
*/
int	close_window(void *param)
{
	t_long	*game;

	game = (t_long *)param;
	// free_tlong(param);
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	ft_putendl_fd("\nUnexpected end of the game.", 1);
	exit(EXIT_SUCCESS);
}

/**
 * @brief
 * It prints a congratulations message,
 * frees the game and end the program.
 *
*/
void	win_endgame(t_long *game)
{
	ft_printf("\nCongratulations! You finished with %d moves!\n", game->mv_count);
	// free_tlong(game);
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	exit(EXIT_SUCCESS);
}
