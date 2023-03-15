/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:48:50 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/03/15 16:07:05 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

/**
 * @brief
 * It will fill the data about the
 * items 'C', 'P' and 'E' in the t_long based on the map.
*/
void	fill_game(t_long *game)
{
	game->c = pick_items(game->map, 'C');
	game->p = pick_items(game->map, 'P');
	game->e = pick_items(game->map, 'E');
	game->count_c = item_count(game->c);
	game->count_p = item_count(game->p);
	game->count_e = item_count(game->e);
}

/**
 * @brief
 * It takes the given list, creates the char** map
 * and puts it in the t_long->map, then calls fill_game()
 * @param t_long* game
 * @param t_list* map the list previously created with the map lines
 * @return
 * 0 if it goes well
 * or 1 in case of Failed memory allocation
*/
int	create_maptab(t_long *game, t_list *map)
{
	char	**maptab;
	t_list	*ptr;
	int		i;

	ptr = map;
	game->rows = ft_lstsize(map);
	maptab = ft_calloc(game->rows + 1, sizeof(char *));
	if (!maptab)
		return (1);
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
	return (0);
}
