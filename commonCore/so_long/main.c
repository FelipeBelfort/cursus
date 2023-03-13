/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 22:01:23 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/03/13 20:13:15 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

t_long	*init_game(char *path)
{
	t_long	*game;
	int		error;

	game = ft_calloc(1, sizeof(t_long));
	if (!game)
		ft_error();
	game->rows = 0;
	game->cols = 0;
	game->count_c = 0;
	game->count_e = 0;
	game->count_p = 0;
	game->c = NULL;
	game->e = NULL;
	game->p = NULL;
	game->map = NULL;
	error = parse_map(game, path);
	if (error)
		ft_error();
	return (game);
}

int	is_valid_file(char *namefile)
{
	char	*extension;

	extension = ft_strrchr(namefile, '.');
	if (!extension)
		return (0);
	if (ft_memcmp(extension, ".ber", 4))
		return (0);
	return (1);
}

int	launch_game(t_long *game);

int	main(int argc, char **argv)
{
	t_long	*game;

	if (argc == 2)
	{
		if (!is_valid_file(argv[1]))
			ft_error();
		game = init_game(argv[1]);
		launch_game(game);
	}
	ft_putendl_fd("Error", 2);
	return (0);
}
