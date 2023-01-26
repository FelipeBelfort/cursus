/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:19:03 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/01/26 18:48:12 by fbelfort         ###   ########.fr       */
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
 * It will fill the container with the informations 
 * from the stack A inside.
*/
void	fill_container(t_pushswap *bin)
{
	int		i;

	if (!bin->a)
		return ;
	i = 0;
	bin->lstsize = stack_size(bin->a);
	bin->max = stack_max(bin->a);
	bin->min = stack_min(bin->a);
	bin->max_a = bin->max;
	bin->min_a = bin->min;
}
