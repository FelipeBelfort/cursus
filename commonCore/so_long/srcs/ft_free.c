/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 20:05:41 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/03/16 23:30:30 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
 * @brief
 * Verifies all the elements of the structure to
 * free if it exists then free the structure.
*/
void	free_tlong(t_long *game)
{
	int	i;

	i = 0;
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
	while (game->text[i])
		mlx_destroy_image(game->mlx, game->text[i++]);
	if (game->win)
	{
		mlx_clear_window(game->mlx, game->win);
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
	}
	if (game->mlx)
		free(game->mlx);
	free(game);
}
