/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endgame.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 22:32:15 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/03/20 12:53:01 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
		ft_putstr_fd("Failed memory allocation", 2);
	if (code == 2)
		ft_putstr_fd("Invalid file. Attended a .ber", 2);
	if (code == 3)
		ft_putstr_fd("It needs to have at least 3 rows or columns", 2);
	if (code == 4)
		ft_putstr_fd("Wrong number of player, exit or colectible", 2);
	if (code >= 5 && code <= 8)
		ft_putstr_fd("The map is not valid", 2);
	if (code == 9)
		ft_putstr_fd("The map file seems broken", 2);
	ft_putchar_fd('\n', 2);
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
	ft_putendl_fd("\nUnexpected end of the game.", 1);
	game->endofgame = 1;
	return (0);
}

/**
 * @brief
 * It prints a congratulations message,
 * frees the game and end the program.
 *
*/
void	win_endgame(t_long *game)
{
	ft_printf("\n\nCongratulations!\n");
	ft_printf("\nYou finished with %d moves!\n", game->mv_count);
	game->endofgame = 1;
}

int	endloop(void *param)
{
	t_long	*game;

	game = (t_long *)param;
	if (game->endofgame)
		mlx_loop_end(game->mlx);
	return (0);
}
