/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:12:35 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/01/25 16:57:30 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	i = 0;
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
	if (i > 1)
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
