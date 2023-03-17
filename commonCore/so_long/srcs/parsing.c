/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:45:18 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/03/16 23:30:10 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/**
 * @brief
 * To be used to verify if exists
 * a valid path between the player,
 * all the colectibles and the exit.
 * It will flood the map with 'b's from the player's position.
 * @param char** map
 * @param int y position y of the player in the map
 * @param int x position x of the player in the map
*/
static void	flood_map(char **map, int y, int x)
{
	if (map[y][x] && map[y][x] != '1' && map[y][x] != 'b')
	{
		map[y][x] = 'b';
		flood_map(map, y + 1, x);
		flood_map(map, y, x + 1);
		flood_map(map, y - 1, x);
		flood_map(map, y, x - 1);
	}
}

/**
 *  @brief
 * Iterates over all the lines of the t_long->map
 * and verifies each line and character
 * to assume if it is a valid map.
 *  @param t_long* game
 *  @return
 * 0 in case of success
 * or the error code.
*/
static int	check_map(t_long *game)
{
	size_t	i;

	i = 0;
	if (game->rows < 3 || game->cols < 3)
		return (3);
	if (game->count_c < 1 || game->count_p != 1 || game->count_e != 1)
		return (4);
	while (game->map[++i] && i < game->rows - 1)
	{
		if (ft_strlen(game->map[i]) != game->cols)
			return (5);
		if (is_forbidden(game->map[i]))
			return (6);
		if (!is_closed(game->map[i]))
			return (7);
	}
	if (!is_onlybrick(game->map[0]) || !is_onlybrick(game->map[game->rows - 1]))
		return (7);
	flood_map(game->map, game->p->y, game->p->x);
	if (!is_empty(game->map))
		return (8);
	put_itemsback(game);
	return (0);
}

/**
 * @brief
 * It reads in the given fd and returns
 * a linked list with the lines of the file.
 * In case of error it will free the list and end the program.
 * @param t_long* used just in case of error, to free all
 * @param int fd the file descriptor to be read
 * @return
 * A pointer to the linked list
*/
static t_list	*get_map_lines(t_long *game, int fd)
{
	t_list	*map;
	t_list	*node;
	char	*line;

	map = NULL;
	line = get_next_line(fd);
	while (line)
	{
		node = ft_lstnew(line);
		if (!node)
		{
			ft_lstclear(&map, free);
			ft_error(game, 1);
		}
		line = ft_strchr(line, '\n');
		if (line)
			line[0] = 0;
		ft_lstadd_back(&map, node);
		line = get_next_line(fd);
	}
	return (map);
}

/**
 * @brief
 * It will do the parsing of the map to verify if it's a valid map
 * @param t_long* game
 * @param char* path of the file to be read
 * @return
 * 0 in case of success
 * or the error code.
*/
int	parse_map(t_long *game, char *path)
{
	int		fd;
	int		code;
	t_list	*map;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error(game, 9);
	map = get_map_lines(game, fd);
	close(fd);
	code = create_maptab(game, map);
	ft_lstclear(&map, free);
	if (!code)
		code = check_map(game);
	return (code);
}
