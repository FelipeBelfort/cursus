/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:08:52 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/01/30 15:42:53 by fbelfort         ###   ########.fr       */
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
	if (ft_strlen(str) < 1)
		return (1);
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
static int	parse_stack(char **argv, int i)
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
 * Iterates over the array of *CHAR
 * to transform them in INT 
 * then add to a linked list.
 * Also verifies if it's an INT 
 * and if the numbers 
 * are not duplicated.
*/
static void	lst_init(t_pushswap *bin, char **argv, int i)
{
	t_stack	*a;
	t_stack	*tmp;
	int		nb;

	a = NULL;
	while (argv[i])
	{
		nb = ft_atoi(argv[i]);
		if (!is_int(argv[i], nb) || is_dup(a, nb))
		{
			if (!i)
				free_tab(argv);
			ft_error(bin);
		}
		tmp = stack_new(nb);
		if (!tmp)
		{
			if (!i)
				free_tab(argv);
			ft_error(bin);
		}
		stack_addback(&a, tmp);
		i++;
	}
	bin->a = a;
}

/**
 * @brief
 * Initiates a t_pushswap, puts all the pointers to NULL then returns it.
 * 
*/
static t_pushswap	*bin_creator(void)
{
	t_pushswap	*bin;

	bin = malloc(sizeof(t_pushswap));
	if (!bin)
		return (NULL);
	bin->a = NULL;
	bin->b = NULL;
	bin->res = NULL;
	return (bin);
}

/**
 * @brief
 * Does the parsing of the elements
 * passed in main().
 * If it finds an error it returns NULL,
 * otherwise it returns a T_PUSHSWAP where
 * T_PUSHSWAP->a points to the linked list.
 *  
*/
t_pushswap	*stack_init(char **argv, int argc)
{
	t_pushswap	*bin;
	int			ok;
	int			i;
	char		**tab;

	i = 1;
	tab = argv;
	if (argc == 2 && ft_strchr(argv[i], ' '))
		tab = ft_split(argv[i--], ' ');
	ok = parse_stack(tab, i);
	bin = bin_creator();
	if (!bin)
		ok = 0;
	if (!ok)
	{
		if (!i)
			free_tab(tab);
		return (bin);
	}
	lst_init(bin, tab, i);
	if (!i)
		free_tab(tab);
	return (bin);
}
