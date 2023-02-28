/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 22:01:23 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/02/28 22:04:04 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_long	*init_game(char *path)
{
	t_long	*game;

	game->count_c = 0;
	game->count_e = 0;
	game->count_p = 0;
	game->c = NULL;
	game->e = NULL;
	game->p = NULL;
	game->map = NULL;
	parse_map(game, path);
	return (game);
}

int	main(int argc, char **argv)
{
	t_long	*game;

	if (argc == 2)
	{
		game = init_game(argv[1]);
	}
}
