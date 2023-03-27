/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 22:01:23 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/03/23 13:02:26 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static t_long	*init_game(char *path)
{
	t_long	*game;
	int		error;

	game = ft_calloc(1, sizeof(t_long));
	if (!game)
		ft_error(NULL, 1);
	error = parse_map(game, path);
	if (error)
		ft_error(game, error);
	return (game);
}

static int	is_valid_file(char *namefile)
{
	char	*extension;

	extension = ft_strrchr(namefile, '.');
	if (!extension)
		return (0);
	if (ft_memcmp(extension, ".ber", 5))
		return (0);
	return (1);
}

static int	launch_game(t_long *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_error(game, 1);
	game->win = mlx_new_window(game->mlx, game->cols * IMG_SIZE,
			game->rows * IMG_SIZE, "so_long -> fbelfort");
	apply_textures(game);
	ft_putstr_fd("Welcome to so_long!!!\nMOVES : 0000", 1);
	game->p->img = game->text[IMG_P1];
	game->e->img = game->text[IMG_E1];
	display_maze(game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_key_hook(game->win, key_press, game);
	mlx_loop_hook(game->mlx, endloop, game);
	mlx_loop(game->mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	t_long	*game;

	if (argc == 2)
	{
		if (!is_valid_file(argv[1]))
			ft_error(NULL, 2);
		game = init_game(argv[1]);
		launch_game(game);
		free_tlong(game);
	}
	else
		ft_putendl_fd("Error -> Invalid number of arguments.", 2);
	return (0);
}
