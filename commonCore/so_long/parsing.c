/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:45:18 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/02/26 20:33:49 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_onlybrick(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n')
	{
		if (line[i++] != '1')
			return (0);
	}
	return (1);
}

int	is_forbidden(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (!ft_strchr("10EPC", line[i]))
			return (1);
	}
	return (0);
}

int	is_closed(char *line)
{
	int	len;

	line = ft_strlen(line);
	if (line[0] != '1' || line[len - 2] != '1')
		return (0);
	return (1);
}

int	count_item(char *line, int item)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (line[++i])
	{
		if (line[i] == item)
			count++;
	}
	return (count);
}

/**
 *  [0][0] - [0][1] - [0][2] - [0][3] - [0][4]
 *  [1][0] - [1][1] - [1][2] - [1][3] - [1][4]
 *  [2][0] - [2][1] - [2][2] - [2][3] - [2][4]
 *  [3][0] - [3][1] - [3][2] - [3][3] - [3][4]
 *  [4][0] - [4][1] - [4][2] - [4][3] - [4][4]
*/
void	flood_map(char **map, int x, int y)
{
	if (map[y][x] != '1')
	{
		map[y][x] = '0';
		flood_map(map, y + 1, x);
		flood_map(map, y, x + 1);
		flood_map(map, y - 1, x);
		flood_map(map, y, x - 1);
	}
}

char	**create_maptab(t_long *game, t_list *map)
{
	char	**maptab;
	t_list	*ptr;
	int		i;

	i = 0;
	ptr = map;
	maptab = ft_calloc(game->rows + 1, sizeof(char *));
	if (!maptab)
		return (NULL);
	while (ptr)
	{
		maptab[i++] = ft_strdup(ptr->content);
		ptr = ptr->next;
	}
	ft_lstclear(&map, free);
	return (maptab);
}

int	check_map(t_long *game, t_list *map)
{
	int		len;
	int		i;
	t_list	*ptr;

	i = 0;
	ptr = map;
	game->cols = ft_strlen(ptr->content);
	if (game->cols < 4)
		ft_error();
	while (ptr->next)
	{
		if (ft_strlen(ptr->content) != game->cols || !is_closed(ptr->content)
			|| is_forbidden(ptr->content)
			|| (i == 0 && !is_onlybrick(ptr->content)))
			ft_error();
		game->count_p += count_item(ptr->content, 'P');
		game->count_e += count_item(ptr->content, 'E');
		game->count_c += count_item(ptr->content, 'C');
		i++;
		ptr = ptr->next;
	}
	if (!is_onlybrick(ptr->content))
		ft_error();
	if (i < 3)
		ft_error();
	if (game->count_p != 1 || game->count_e != 1)
		ft_error();
	if (game->count_c < 1)
		ft_error();
	game->map = create_maptab(game, map);
}

void	parse_map(t_long *game, char *path)
{
	int		len;
	int		fd;
	t_list	*map;
	t_list	*node;
	char	*line;

	len = ft_strlen(path);
	if (ft_memcmp(&path[len - 5], ".ber", 4))
		ft_error();
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error();
	line = get_next_line(fd);
	while (line)
	{
		node = ft_lstnew(line);
		if (!node)
			ft_error();
		ft_lstadd_back(&map, node);
		line = get_next_line(fd);
	}
	close(fd);
	check_map(game, map);
}
