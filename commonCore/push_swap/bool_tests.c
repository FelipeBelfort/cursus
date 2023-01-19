/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:12:35 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/01/17 20:15:46 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 * Checks if in the *CHAR passed in argument
 * contains only numbers (negatives and positives)
 * if that is the case it returns 0, but if the function
 * finds a non digit char it returns 1.
 * @return
 *  1 if is invalid
 * 	OR
 *  0 if is valid
 * 
*/
static int	is_invalidstr(char *str)
{
	int	i;

	i = -1;
	if (str[0] == '-' && str[1])
		i++;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
	}
	return (0);
}

/**
 * @brief
 * Checks if the array of arguments 
 * are all numbers.
 * 
 * @param char **argv (array of values) 
 * @return 1 of is valid OR 0 if there aren't
 *  only numbers 
*/
int	parse_stack(char **argv, int i)
{
	while (argv[i])
	{
		if (is_invalidstr(argv[i++]))
			return (0);
	}
	return (1);
}

/**
 * @brief
 * Checks if the number NB 
 * already exists in the list A
 * 
*/
int	is_dup(t_stack *a, int nb)
{
	while (a)
	{
		if (nb == a->nb)
			return (1);
		a = a->next;
	}
	return (0);
}

/**
 * @brief
 * Checks if the number N is greater than an INT 
 * 
 * 
*/
int	is_int(char *str, int n)
{
	if ((ft_strlen(str) > 11)
		|| (!n && ft_strncmp(str, "0", 2)))
		return (0);
	return (1);
}
