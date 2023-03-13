/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:45:18 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/03/13 20:05:02 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	is_onlybrick(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] != '1')
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

	len = ft_strlen(line);
	if (line[0] != '1' || line[len - 1] != '1')
		return (0);
	return (1);
}

int	is_empty(char **map)
{
	int	x;
	int	y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (ft_strchr("EPC", map[y][x]))
				return (0);
		}
	}
	return (1);
}

/**
 *  [0][0] - [0][1] - [0][2] - [0][3] - [0][4]
 *  [1][0] - [1][1] - [1][2] - [1][3] - [1][4]
 *  [2][0] - [2][1] - [2][2] - [2][3] - [2][4]
 *  [3][0] - [3][1] - [3][2] - [3][3] - [3][4]
 *  [4][0] - [4][1] - [4][2] - [4][3] - [4][4]
*/
void	flood_map(char **map, int y, int x)
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

t_item	*item_newnode(int y, int x)
{
	t_item	*ptr;

	ptr = ft_calloc(1, sizeof(t_item));
	if (!ptr)
		return (NULL);
	ptr->x = x;
	ptr->y = y;
	ptr->next = NULL;
	return (ptr);
}

void	item_addback(t_item **list, t_item *node)
{
	t_item	*ptr;

	ptr = NULL;
	if (!list || !node)
		return ;
	if (!*list)
		*list = node;
	else
	{
		ptr = *list;
		while (ptr && ptr->next)
			ptr = ptr->next;
		ptr->next = node;
	}
}

int	item_count(t_item *items)
{
	int	i;

	i = 0;
	while (items)
	{
		i++;
		items = items->next;
	}
	return (i);
}

void	put_itemsback(t_long *game)
{
	t_item	*ptr;

	ptr = game->c;
	// game->map[game->p->y][game->p->x] = 'P';
	game->map[game->e->y][game->e->x] = 'E';
	while (ptr)
	{
		game->map[game->c->y][game->c->x] = 'C';
		ptr = ptr->next;
	}
}

t_item	*pick_items(char **map, int c)
{
	int		y;
	int		x;
	t_item	*item;
	t_item	*list;

	y = -1;
	item = NULL;
	list = NULL;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == c)
			{
				item = item_newnode(y, x);
				item_addback(&list, item);
			}
		}
	}
	return (list);
}

void	fill_game(t_long *game)
{
	game->c = pick_items(game->map, 'C');
	game->p = pick_items(game->map, 'P');
	game->e = pick_items(game->map, 'E');
	game->count_c = item_count(game->c);
	game->count_p = item_count(game->p);
	game->count_e = item_count(game->e);
}

int	check_map(t_long *game)
{
	size_t	i;

	i = 0;
	if (!is_onlybrick(game->map[0]) || !is_onlybrick(game->map[game->rows - 1]))
		ft_error();
	if (game->rows < 3 || game->cols < 3)
		ft_error();
	if (game->count_c < 1 || game->count_p != 1 || game->count_e != 1)
		ft_error();
	while (game->map[++i] && i < game->rows - 1)
	{
		if (ft_strlen(game->map[i]) != game->cols)
			ft_error();
		if (is_forbidden(game->map[i]))
			ft_error();
		if (!is_closed(game->map[i]))
			ft_error();
	}
	flood_map(game->map, game->p->y, game->p->x);
	if (!is_empty(game->map))
		ft_error();
	put_itemsback(game);
	return (0);
}

void	create_maptab(t_long *game, t_list *map)
{
	char	**maptab;
	t_list	*ptr;
	int		i;

	ptr = map;
	game->rows = ft_lstsize(map);
	maptab = ft_calloc(game->rows + 1, sizeof(char *));
	if (!maptab)
		return ;
	i = 0;
	ptr = map;
	while (ptr)
	{
		maptab[i++] = ft_strdup(ptr->content);
		ptr = ptr->next;
	}
	maptab[i] = NULL;
	game->cols = ft_strlen(maptab[0]);
	game->map = maptab;
	fill_game(game);
}

int	parse_map(t_long *game, char *path)
{
	int		fd;
	t_list	*map;
	t_list	*node;
	char	*line;

	map = NULL;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error();
	line = get_next_line(fd);
	while (line)
	{
		node = ft_lstnew(line);
		if (!node)
			ft_error();
		line = ft_strchr(line, '\n');
		line[0] = 0;
		ft_lstadd_back(&map, node);
		line = get_next_line(fd);
	}
	close(fd);
	create_maptab(game, map);
	ft_lstclear(&map, free);
	check_map(game);
	return (0);
}
