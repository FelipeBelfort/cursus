/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:53:05 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/01/23 14:31:20 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 * split a list in two.
*/
static void	split_list(t_stack *stack, t_stack **a, t_stack **b)
{
	t_stack	*end;
	t_stack	*mid;

	mid = stack;
	end = stack->next;
	while (end)
	{
		end = end->next;
		if (end)
		{
			mid = mid->next;
			end = end->next;
		}
	}
	*a = stack;
	*b = mid->next;
	mid->next = NULL;
}

/**
 * @brief
 * Merges two list into one sorting them in the process.
 * @return a pointer to the new sorted list
*/
static t_stack	*lst_merge(t_stack *a, t_stack *b)
{
	t_stack	*result;

	result = NULL;
	if (!a)
		return (b);
	if (!b)
		return (a);
	if (a->index <= b->index)
	{
		result = a;
		result->next = lst_merge(a->next, b);
	}
	else
	{
		result = b;
		result->next = lst_merge(a, b->next);
	}
	return (result);
}

/**
 * @brief
 * Sort a list by spliting and merging the lists.
*/
static void	lst_mergesort(t_stack **stack)
{
	t_stack	*ptr;
	t_stack	*a;
	t_stack	*b;

	ptr = *stack;
	if (!ptr || !ptr->next)
		return ;
	split_list(ptr, &a, &b);
	lst_mergesort(&a);
	lst_mergesort(&b);
	*stack = lst_merge(a, b);
}

/**
 * @brief
 * resets the list to the original order 
 * but replacing the numbers by positive integers
*/
void	reset_stack(t_pushswap *bin)
{
	t_stack	*ptr;
	int		i;

	i = 0;
	ptr = bin->a;
	while (ptr)
	{
		ptr->nb = i++;
		ptr = ptr->next;
	}
	bin->max = stack_max(bin->a);
	bin->min = 0;
	bin->max_a = bin->max;
	bin->min_a = bin->min;
	lst_mergesort(&bin->a);
}
