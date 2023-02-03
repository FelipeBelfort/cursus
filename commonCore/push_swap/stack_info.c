/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:19:03 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/02/03 16:31:34 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 * Counts how many elements are in the stack
 * @return size of the stack
*/
int	stack_size(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

/**
 * @brief
 * Finds the greater number of the stack
 * @return
 * the greater number
*/
int	stack_max(t_stack *stack)
{
	int	max;

	if (!stack)
		return (0);
	max = stack->nb;
	stack = stack->next;
	while (stack)
	{
		if (stack->nb > max)
			max = stack->nb;
		stack = stack->next;
	}
	return (max);
}

/**
 * @brief
 * Finds the smallest number of the stack
 * @return
 * the smallest number
*/
int	stack_min(t_stack *stack)
{
	int	min;

	if (!stack)
		return (0);
	min = stack->nb;
	stack = stack->next;
	while (stack)
	{
		if (stack->nb < min)
			min = stack->nb;
		stack = stack->next;
	}
	return (min);
}

/**
 * @brief
 * Searchs the node with the correspondent NB in the stack
 * @return
 * the index of the node requested OR -1 if not exists.
*/
int	stack_get_i(t_stack *stack, int nb)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (nb == stack->nb)
			return (i);
		i++;
		stack = stack->next;
	}
	return (-1);
}

/**
 * @brief
 * It returns the average number of the stack.
 * It has to take the smallest number of the stack
 * and the half of the stack size.
 * So it looks HALF times what is the next number.
 * @param t_stack *s the stack where to search
 * @param int N the smallest number of the stack
 * @param int HALF the half of the stack size
 *  @return int the average number of the stack
*/
int	stack_avrg(t_stack *s, int n, int half)
{
	if (half-- > 0)
	{
		n = seek_next(n, s);
		n = stack_avrg(s, n, half);
	}
	return (n);
}
