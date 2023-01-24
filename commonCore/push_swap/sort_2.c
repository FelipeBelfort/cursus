/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:30:16 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/01/23 19:23:17 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	seek_prev(int n, t_stack *s)
{
	int	prev;

	if (n < stack_min(s) || !s)
		return (stack_max(s));
	prev = -1;
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
int	get_cost(int n, t_stack *s)
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
int	get_opcost(t_pushswap *bin, int n, int direction)
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
 * Checks every element of the stack
 * and set the attribute "ordered" to 1 
 * if it's bigger than the previous one.
 * Otherwise it'll set to 0. 
*/
void	set_ordered(t_stack *stack)
{
	int	prev;
	int	max;

	prev = stack_last(stack)->nb;
	max = stack_max(stack);
	while (stack)
	{
		stack->ordered = 0;
		if (stack->nb > prev || prev == max)
			stack->ordered = 1;
		prev = stack->nb;
		stack = stack->next;
	}
}

/**
 * @brief
 * It will fetch the better element to be pushed
 * and set the value in the T_PUSHSWAP::NB.
 * The decision is based on the number of moves.
 * @param t_pushswap
 * @param int 1 for a PB and 0 for a PA
 *
*/
void	fetch_topush(t_pushswap *bin, int direction)
{
	int		cost_tmp;
	int		cost;
	int		min;
	t_stack	*s;

	s = bin->b;
	min = __INT_MAX__;
	if (direction)
	{
		s = bin->a;
		min = stack_min(s) + 20;
	}
	cost = __INT_MAX__;
	bin->nb = 0;
	while (s)
	{
		// if (!s->ordered)
		if (s->nb <= min)
		{
			cost_tmp = get_opcost(bin, s->nb, direction);
			if (cost == cost_tmp && s->nb < bin->nb)
				bin->nb = s->nb;
			if (cost > cost_tmp)
			{
				bin->nb = s->nb;
				cost = cost_tmp;
			}
		}
		s = s->next;
	}
}

/**
 * @brief
 * Analyses the chosen number on B and the target position on A
 * to decide if it will rotate up or down for each stack.
 * It will return a pointer to the right function to be used
 * @return
 * rr, rrr, ra(if it's ra and rrb) or rra(if it's rra and rb)
*/
void	*rot_up_downa(t_pushswap *bin)
{
	int	nb_i;
	int	target_i;
	int	way_a;
	int	way_b;

	way_a = 0;
	way_b = 0;
	nb_i = stack_get_i(bin->b, bin->nb);
	target_i = stack_get_i(bin->a, bin->target);
	if (nb_i <= stack_size(bin->b) / 2)
		way_b = 1;
	if (target_i <= stack_size(bin->a) / 2)
		way_a = 1;
	if (way_a && way_a == way_b)
		return (rr);
	if (!way_a && way_a == way_b)
		return (rrr);
	if (way_a)
		return (ra);
	if (!way_a)
		return (rra);
	return (NULL);
}

/**
 * @brief
 * Analyses the chosen number on A and the target position on B
 * to decide if it will rotate up or down for each stack.
 * It will return a pointer to the right function to be used
 * @return
 * rr, rrr, ra(if it's ra and rrb) or rra(if it's rra and rb)
*/
void	*rot_up_downb(t_pushswap *bin)
{
	int	nb_i;
	int	target_i;
	int	way_a;
	int	way_b;

	way_a = 0;
	way_b = 0;
	nb_i = stack_get_i(bin->a, bin->nb);
	target_i = stack_get_i(bin->b, bin->target);
	if (nb_i <= stack_size(bin->a) / 2)
		way_a = 1;
	if (target_i <= stack_size(bin->b) / 2)
		way_b = 1;
	if (way_a && way_a == way_b)
		return (rr);
	if (!way_a && way_a == way_b)
		return (rrr);
	if (way_a)
		return (ra);
	if (!way_a)
		return (rra);
	return (NULL);
}

/**
 * @brief
 * It will make the necessaries moves before to push
 * then it will PA 
*/
void	push_toa(t_pushswap *bin)
{
	void	*cmda;
	void	*cmdb;

	fetch_topush(bin, TO_A);
	bin->target = seek_next(bin->nb, bin->a);
	cmda = rot_up_downa(bin);
	if (cmda == ra || cmda == rrr)
		cmdb = rrb;
	if (cmda == rra || cmda == rr)
		cmdb = rb;
	while (bin->b->nb != bin->nb && bin->a->nb != bin->target
		&& bin->b && bin->a)
		do_op(bin, cmda);
	if (cmda == rr)
		cmda = ra;
	if (cmda == rrr)
		cmda = rra;
	while (bin->b->nb != bin->nb && bin->b)
		do_op(bin, cmdb);
	while (bin->a->nb != bin->target && bin->a)
		do_op(bin, cmda);
	do_op(bin, pa);
}

/**
 * @brief
 * It will make the necessaries moves before to push
 * then it will PB 
*/
void	push_tob(t_pushswap *bin)
{
	void	*cmda;
	void	*cmdb;

	fetch_topush(bin, TO_B);
	bin->target = seek_prev(bin->nb, bin->b);
	cmda = rot_up_downb(bin);
	if (cmda == ra || cmda == rrr)
		cmdb = rrb;
	if (cmda == rra || cmda == rr)
		cmdb = rb;
	while (bin->a->nb != bin->nb && bin->b->nb != bin->target
		&& bin->a && bin->b)
		do_op(bin, cmda);
	if (cmda == rr)
		cmda = ra;
	if (cmda == rrr)
		cmda = rra;
	while (bin->a->nb != bin->nb && bin->a)
		do_op(bin, cmda);
	while (bin->b->nb != bin->target && bin->b)
		do_op(bin, cmdb);
	do_op(bin, pb);
}

/**
 * @brief
 * It will do a selection sort based on the number of
 * moves to put the element in the right place.
 * It keeps doing it untill the stack is ordered(even if it's not sorted)
 * or it reaches a size of 3 elements, if that's the case 
 * it calls the sort_3() then it does the same to push back to A
 * finaly it calls sort_ordered()
*/
void	sort_selectcost(t_pushswap *bin)
{
	do_op(bin, pb);
	do_op(bin, pb);
	// set_ordered(bin->a);
	while (stack_size(bin->a) > 3 && !is_ordered(bin->a))
		push_tob(bin);
	if (!is_ordered(bin->a))
		sort_3(bin);
	while (bin->b)
		push_toa(bin);
	sort_ordered(bin);
}
