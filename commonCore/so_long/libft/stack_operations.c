/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 23:33:14 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/03/16 19:50:45 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief
 * Swipes the first and second elements of
 * the given stack.
 * It will check if they exist before the operation
 * @param t_stack **stack
 * @return
 * 1 if the operation succeeds
 * OR
 * 0 if it fails
*/
int	stack_swipe(t_stack **stack)
{
	t_stack	*ptr;

	if (*stack && (*stack)->next)
	{
		ptr = stack_getnode(stack, (*stack)->next);
		stack_addfirst(stack, ptr);
		return (1);
	}
	return (0);
}

/**
 * @brief
 * Gets the first element of
 * the given stack and put it the end of the Stack.
 * That way it will rotate the stack and shift up all the elements by 1.
 * It will check if at least 2 elements exist before the operation
 * @param t_stack **stack
 * @return
 * 1 if the operation succeeds
 * OR
 * 0 if it fails
*/
int	stack_rotate(t_stack **stack)
{
	t_stack	*ptr;
	t_stack	*ptr_void;

	ptr_void = NULL;
	if (*stack && (*stack)->next)
	{
		ptr = *stack;
		*stack = (*stack)->next;
		stack_addback(stack, ptr);
		ptr->next = ptr_void;
		return (1);
	}
	return (0);
}

/**
 * @brief
 * Gets the last element of
 * the given stack and put it the front of the Stack.
 * That way it will rotate the stack and shift down all the elements by 1.
 * It will check if at least 2 elements exist before the operation
 * @param t_stack **stack
 * @return
 * 1 if the operation succeeds
 * OR
 * 0 if it fails
*/
int	stack_rev_rotate(t_stack **stack)
{
	t_stack	*last;

	if (*stack && (*stack)->next)
	{
		last = stack_getnode(stack, stack_last(*stack));
		stack_addfirst(stack, last);
		return (1);
	}
	return (0);
}
