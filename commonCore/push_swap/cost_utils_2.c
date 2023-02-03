/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:30:16 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/02/03 17:11:08 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 * It takes the N and returns the costs to put the element 
 * in the target position
 * @param int n the number to analyse
 * @param t_stack *s the stack where to search the N
 * @return t_stack *costs a list of 3 elements,
 * where the first is the amount of ra(b) needed
 * to be the first element of the stack
 * the second is the amount of rra(b) needed
 * to be the first element of the stack
 * the third is the size of the stack.
*/
t_stack	*set_costs(int n, t_stack *s)
{
	int		size;
	int		index;
	t_stack	*cost;

	cost = NULL;
	size = stack_size(s);
	index = stack_get_i(s, n);
	if (index < 0)
		return (NULL);
	stack_addback(&cost, stack_new(index));
	stack_addback(&cost, stack_new(size - index + 1));
	stack_addback(&cost, stack_new(size));
	return (cost);
}

/**
 * @brief
 * This function takes two stacks of costs and returns
 * the cost of the operation based on the amount of moves to be done
 * @param t_stack *greater the stack with the greater size
 * @param t_stack *fewer the stack with the smaller size
*/
static int	get_cost(t_stack *greater, t_stack *fewer)
{
	int	cost;

	if (!greater || !fewer)
		return (__INT_MAX__);
	if (greater->nb <= greater->next->nb)
	{
		if (greater->nb >= fewer->nb)
			cost = greater->nb;
		else if ((fewer->nb - greater->nb) <= fewer->next->nb)
			cost = greater->nb + (fewer->nb - greater->nb);
		else
			cost = greater->nb + fewer->next->nb;
	}
	else
	{
		if (greater->next->nb >= fewer->next->nb)
			cost = greater->next->nb;
		else if ((fewer->next->nb - greater->next->nb) <= fewer->nb)
			cost = greater->next->nb + (fewer->next->nb - greater->next->nb);
		else
			cost = greater->next->nb + fewer->nb;
	}
	return (cost);
}

/**
 *  * @brief
 * It gets the cost of the operation to push the element N
 * into the other stack. It depends of the value of DIRECTION. 
 * It will return the number of moves it will take
 * to do the operation.
 * @param t_pushswap *bin the container with the stacks 
 * @param int N to push
 * @param int 1 if PB or 0 if PA
 * @return
 * int - The cost to push the element N 
*/
static int	get_opcost(t_pushswap *bin, int n, int direction)
{
	int		target;
	t_stack	*from;
	t_stack	*to;
	int		(*seek)(int n, t_stack *to);

	from = bin->b;
	to = bin->a;
	seek = seek_next;
	if (direction)
	{
		from = bin->a;
		to = bin->b;
		seek = seek_prev;
	}
	target = seek(n, to);
	from = set_costs(n, from);
	to = set_costs(target, to);
	if (from->next->next->nb >= to->next->next->nb)
		target = get_cost(from, to);
	else
		target = get_cost(to, from);
	free_stack(from);
	free_stack(to);
	return (target);
}

/**
 * @brief
 * It will fetch the better element to be pushed
 * and set the value in the T_PUSHSWAP->NB.
 * The decision is based on the number of moves
 * needed to push the element at the right place.
 * Then it will set also the T_PUSHSWAP->TARGET
 * @param t_pushswap
 * @param int 1 for a PB and 0 for a PA
 *
*/
void	fetch_topush(t_pushswap *bin, int direction)
{
	int		cost_tmp;
	int		cost;
	t_stack	*s;

	s = bin->b;
	if (direction)
		s = bin->a;
	cost = __INT_MAX__;
	bin->nb = 0;
	while (s)
	{
		cost_tmp = get_opcost(bin, s->nb, direction);
		if (cost == cost_tmp && s->nb < bin->nb)
			bin->nb = s->nb;
		if (cost > cost_tmp)
		{
			bin->nb = s->nb;
			cost = cost_tmp;
		}
		s = s->next;
	}
	if (direction)
		bin->target = seek_prev(bin->nb, bin->b);
	else
		bin->target = seek_next(bin->nb, bin->a);
}
