/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:12:35 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/02/03 18:10:21 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 * Checks if the number N is greater than an INT 
 * It compares the original string with the INT and it also checks the length of the string
 * @param char *str the original string before the conversion to INT
 * @param int N the int converted from the string
 * @return
 * 1 in it's an INT
 *	0 if it's not
 * 
*/
int	is_int(char *str, int n)
{
	int	i;

	i = 0;
	while (str[i] == '0' || str[i] == '-')
		i++;
	if ((ft_strlen(&str[i]) > 11)
		|| (!n && ft_strncmp(str, "0", 2)))
		return (0);
	return (1);
}

/**
 * @brief
 * Checks if the stack is sorted in ascending
 * order and returns 1 only if the last is the greater one
 * @return 
 * 1 == true OR 0 == false
*/
int	is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->nb > stack->next->nb)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/**
 * @brief
 * Checks if the stack is ordered even if not sorted
 * example: 4 5 6 7 8 9 0 1 2 3
 * @return 
 * 1 == true OR 0 == false
*/
int	is_ordered(t_stack *s)
{
	int	i;
	int	prev;

	i = -1;
	if (!s || !s->next)
		return (1);
	prev = stack_last(s)->nb;
	while (s)
	{
		if (s->nb < prev)
			i++;
		prev = s->nb;
		s = s->next;
	}
	if (i)
		return (0);
	return (1);
}

/**
 * @brief
 * Checks if the stack is inverted even if not sorted
 * example: 
 * 4 5 6 7 8 9 0 1 2 3 
 * OR 
 * 9 8 7 6 5 4 3 2 1 0
 * @return 
 * 1 == true OR 0 == false
*/
int	is_inverted(t_stack *s)
{
	int	i;
	int	prev;

	i = 0;
	prev = stack_last(s)->nb;
	while (s)
	{
		if (s->nb > prev)
			i++;
		prev = s->nb;
		s = s->next;
	}
	if (i > 1)
		return (0);
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
