/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 00:05:43 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/03/15 17:55:37 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

t_item	*item_newnode(int y, int x)
{
	t_item	*ptr;

	ptr = ft_calloc(1, sizeof(t_item));
	if (!ptr)
		return (NULL);
	ptr->x = x;
	ptr->y = y;
	ptr->img = NULL;
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
	if (!items)
		return (i);
	while (items)
	{
		i++;
		items = items->next;
	}
	return (i);
}

/**
 * @brief
 * After flood the map it will put the items
 * back in the map in their original places, except for the 'P'.
*/
void	put_itemsback(t_long *game)
{
	t_item	*ptr;

	ptr = game->c;
	game->map[game->e->y][game->e->x] = 'E';
	while (ptr)
	{
		game->map[ptr->y][ptr->x] = 'C';
		ptr = ptr->next;
	}
}

/**
 * @brief
 * Iterates over the map to look for the
 * given char, if it finds it will create
 * a t_item and put in a list.
 * @param char** map
 * @param int c -> the char to be searched
 * @return
 * A list with the items found, otherwise it returns NULL.
*/
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
