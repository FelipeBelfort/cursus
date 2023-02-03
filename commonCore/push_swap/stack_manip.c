/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manip.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:21:17 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/02/03 16:26:36 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 * It returns the last node of the given stack
 * @param t_stack *stack
 * @return the last node of the stack
*/
t_stack	*stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

/**
 * @brief
 * Adds the new node at the end of the stack
 * @param t_stack **stack
 * @param t_stack *new node
 * 
*/
void	stack_addback(t_stack **stack, t_stack *new)
{
	t_stack	*ptr;

	if (*stack)
	{
		ptr = stack_last(*stack);
		ptr->next = new;
	}
	else
		*stack = new;
}

/**
 * @brief
 * Initiates a T_STACK node
 * and sets NODE->nb = NB /
 * NODE->next = NULL
 * 
 * @return t_stack *NODE 
*/
t_stack	*stack_new(int nb)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->nb = nb;
	node->next = NULL;
	return (node);
}

/**
 * @brief
 * It will search for the Node in the Stack and pull it out
 * and then it will reset the links between
 * the previous and next nodes in the list.
 * @param t_stack **stack where to search
 * @param t_stack *node to look for
 * @return
 * It returns the given node. 
*/
t_stack	*stack_getnode(t_stack **stack, t_stack *node)
{
	t_stack	*ptr;

	ptr = *stack;
	if (!stack || !node)
		return (NULL);
	if (*stack == node)
		*stack = node->next;
	else
	{
		while (ptr->next != node)
			ptr = ptr->next;
		ptr->next = node->next;
	}
	return (node);
}

/**
 * @brief
 * It will push the new element in the front of the stack.
 * @param t_stack **stack to update
 * @param t_stack *new element to add
*/
void	stack_addfirst(t_stack **stack, t_stack *new)
{
	if (!stack || !new)
		return ;
	new->next = *stack;
	*stack = new;
}
