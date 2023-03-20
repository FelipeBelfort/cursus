/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 23:46:40 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/03/20 12:51:44 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/**
 * @brief
 * Verifies if the line has only '1'
 * to be used in the first and in the last line.
*/
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

/**
 * @brief
 * Verifies if there are any forbidden
 * characters in the line.
 * Only '1', '0', 'E', 'P' and 'C' are allowed.
*/
int	is_forbidden(char *line, int limit)
{
	int	i;

	i = -1;
	while (line[++i] && i < limit)
	{
		if (!ft_strchr("10EPC", line[i]))
			return (1);
	}
	return (0);
}

/**
 * @brief
 * Verifies if the first and last character
 * of the line are '1' to assure that the map is closed.
 * To be used in all lines of the map.
*/
int	is_closed(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (line[0] != '1' || line[len - 1] != '1')
		return (0);
	return (1);
}

/**
 * @brief
 * Verifies if the map is empty,
 * if it finds a 'E', 'P' or 'C' in the map it returns 0.
 * Else it returns 1.
*/
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
