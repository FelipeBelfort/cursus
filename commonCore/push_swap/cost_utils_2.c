/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:30:16 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/01/26 19:33:10 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 * It searchs the number just before N
 * in the target stack.
 * @return the smaller number the closest from the N. 
 * If it doesn't exist it will return -1.
 *
*/
int	seek_prev(int n, t_stack *s)
{
	int	prev;

	prev = stack_min(s);
	if (n < prev || !s)
		return (stack_max(s));
	while (s)
	{
		if (s->nb < n)
		{
			if (s->nb > prev)
				prev = s->nb;
		}
		s = s->next;
	}
	return (prev);
}

/**
 * @brief
 * It searchs the number just after N
 * in the target stack.
 * @return the greater number the closest from the N. 
 * If it doesn't exist it will return -1.
 *
*/
int	seek_next(int n, t_stack *s)
{
	int	next;

	if (n > stack_max(s) || !s)
		return (stack_min(s));
	next = __INT_MAX__;
	while (s)
	{
		if (s->nb > n)
		{
			if (s->nb < next)
				next = s->nb;
		}
		s = s->next;
	}
	return (next);
}

/**
 * @brief
 * It gets the number of moves to take the element N
 * to the top of the stack.
 * @param int the number to check
 * @param t_stack the stack of the number
 * @return int - The cost of the operation
*/
static int	get_cost(int n, t_stack *s)
{
	int	size;
	int	index;

	size = stack_size(s);
	index = stack_get_i(s, n);
	if (index < 0)
		return (0);
	if (index <= size / 2)
		return (index);
	return (size - index + 1);
}

/**
 * @brief
 * It gets the cost of the operation to push the element N
 * into the other stack. It depends of the value of DIRECTION. 
 * It will return the number of moves it will take
 * to do the operation.
 * @param t_pushswap 
 * @param int to push
 * @param int 1 if PB or 0 if PA
 * @return
 * int - The cost to push the element N 
*/
static int	get_opcost(t_pushswap *bin, int n, int direction)
{
	int		cost;
	int		target;
	t_stack	*from;
	t_stack	*to;

	if (direction)
	{
		from = bin->a;
		to = bin->b;
		target = seek_prev(n, to);
	}
	else
	{
		from = bin->b;
		to = bin->a;
		target = seek_next(n, to);
	}
	cost = get_cost(n, from);
	if (!target)
		return (cost);
	cost += get_cost(target, to);
	return (cost);
}

/**
 * @brief
 * It will fetch the better element to be pushed
 * and set the value in the T_PUSHSWAP->NB.
 * The decision is based on the number of moves.
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
}
