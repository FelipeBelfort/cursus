/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 20:05:41 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/03/15 01:29:06 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

/**
 * frees the bidimensional table.
*/
void	free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
	tab = NULL;
}

/**
 * Frees all the items in the list.
 * It will not free the char pointer
 * because it should just point to another string.
*/
void	free_item(t_item *item)
{
	t_item	*ptr;

	while (item)
	{
		ptr = item->next;
		free(item);
		item = ptr;
	}
}

/**
 * Frees all the strings of the table but
 * not the table itself because it was no allocated.
*/
void	free_imgtext(char **ptr)
{
	int	i;

	i = -1;
	while (ptr[++i])
		free(ptr[i]);
}

/**
 * @brief
 * Verifies all the elements of the structure to
 * free if it exists then free the structure.
*/
void	free_tlong(t_long *game)
{
	if (!game)
		return ;
	if (game->p)
		free_item(game->p);
	if (game->e)
		free_item(game->e);
	if (game->c)
		free_item(game->c);
	if (game->map)
		free_tab(game->map);
	if (game->ptr_txt[0])
		free_imgtext(game->ptr_txt);
	if (game->text[0])
		free_imgtext((char **)game->text);
	if (game->win)
	{
		mlx_clear_window(game->mlx, game->win);
		mlx_destroy_window(game->mlx, game->win);
	}
	if (game->mlx)
		free(game->mlx);
	free(game);
}
