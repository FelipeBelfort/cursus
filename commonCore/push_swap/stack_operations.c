/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 23:33:14 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/01/30 17:37:50 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
int	swipe(t_stack **stack)
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
 * Gets the first element of Stack FROM
 * and push it in the top of Stack TO
 * 
 * It will check if the Stack FROM exists before the operation
 * @param t_stack **from
 * @param t_stack **to
 * @return 
 * 1 if the operation succeeds 
 * OR 
 * 0 if it fails
*/
int	push(t_stack **from, t_stack **to)
{
	t_stack	*ptr;

	if (!(*from))
		return (0);
	ptr = *from;
	*from = ptr->next;
	stack_addfirst(to, ptr);
	return (1);
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
int	rotate(t_stack **stack)
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
int	rev_rotate(t_stack **stack)
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

/**
 * @brief
 * One function to rule them all!
 * 
 *  It sends the BIN to the given function and prints 
 * the operation's name in case of succes 
*/
void	do_op(t_pushswap *bin, char *(*op)(t_pushswap *))
{
	char	*operation;

	if (!bin || !op)
		return ;
	operation = op(bin);
	if (operation)
		ft_putstr_fd(operation, 1);
}
