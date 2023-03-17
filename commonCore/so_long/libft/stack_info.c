/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:19:03 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/03/16 20:19:57 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

// /**
//  * Takes a linked list of T_STACK and free all nodes.
// */
// void	free_stack(t_stack **stack)
// {
// 	t_stack	*ptr;

// 	while (stack)
// 	{
// 		ptr = stack->next;
// 		free(stack);
// 		stack = ptr;
// 	}
// }

/**
 * Takes a linked list of T_STACK and free all nodes.
*/
void	free_stack(t_stack **stack)
{
	t_stack	*ptr;

	while (*stack)
	{
		ptr = (*stack)->next;
		free(*stack);
		(*stack) = ptr;
	}
	stack = NULL;
}
