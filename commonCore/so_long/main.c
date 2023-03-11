/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 22:01:23 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/03/11 15:35:32 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	main(int argc, char **argv)
{
	t_long	*game;

	if (argc == 2)
	{
		if (!is_valid_file(argv[1]))
			ft_error();
		game = init_game(argv[1]);
		game->mlx = mlx_init();
		game->win = mlx_new_window(game->mlx, 1280, 720, "so_long");
		mlx_loop(game->mlx);
	}
}
