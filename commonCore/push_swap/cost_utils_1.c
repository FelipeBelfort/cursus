/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:30:16 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/01/30 13:38:56 by fbelfort         ###   ########.fr       */
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
 * It compares the number of operations to be done in the two stacks 
 * to decide which is the best group of operations to do
 * @param t_stack *from the stack where is the number
 * @param t_stack *to the stack where to push the number
 * @return void* the pointer to the function to be used ->  
 * RRR or RR
 *  or RA(if RA and RRB) or RRA(if RRA and RB)
 * 
*/
static void	*pick_cmd(t_stack *from, t_stack *to)
{
	int	len_from;
	int	len_to;
	int	rra_from;
	int	rrb_to;

	len_from = from->next->next->nb;
	len_to = to->next->next->nb;
	rra_from = from->next->nb;
	rrb_to = to->next->nb;
	if ((len_from >= len_to && from->nb <= rra_from
			&& (from->nb >= to->nb || (to->nb - from->nb) < rrb_to))
		|| (len_from <= len_to && to->nb < rrb_to
			&& (to->nb > from->nb || (from->nb - to->nb) < rra_from)))
		return (rr);
	if ((len_from >= len_to && from->nb >= rra_from
			&& (rra_from >= rrb_to || (rrb_to - rra_from) < to->nb))
		|| (len_from <= len_to && to->nb > rrb_to
			&& (rrb_to > rra_from || (rra_from - rrb_to) < from->nb)))
		return (rrr);
	else if (from->nb <= rra_from || to->nb >= rrb_to)
		return (rra);
	else
		return (ra);
}

/**
 * @brief
 * Analyses the chosen number and the target position
 * to decide if it will rotate up or down for each stack.
 * It will return a pointer to the right function to be used
 * It knows if it's to do a PB or a PA based on the DIRECTION
 * @param t_pushswap *container
 * @param int DIRECTION 1 for a PB and 0 for a PA
 * @return
 * rr, rrr, ra(if it's ra and rrb) or rra(if it's rra and rb)
*/
static void	*rot_up_down(t_pushswap *bin, int direction)
{
	t_stack	*from;
	t_stack	*to;
	void	*cmd;

	from = bin->b;
	to = bin->a;
	cmd = NULL;
	if (direction)
	{
		from = bin->a;
		to = bin->b;
	}
	from = set_costs(bin->nb, from);
	to = set_costs(bin->target, to);
	cmd = pick_cmd(from, to);
	free_stack(from);
	free_stack(to);
	if (direction && cmd == ra)
		cmd = rra;
	else if (direction && cmd == rra)
		cmd = ra;
	return (cmd);
}

/**
//  * @brief
//  * It will make the necessaries moves before to push
//  * then it will PA or PB based on the DIRECTION 
// */
void	push_to(t_pushswap *bin, int direction)
{
	void	*cmda;
	void	*cmdb;

	fetch_topush(bin, direction);
	cmda = rot_up_down(bin, direction);
	if (cmda == ra || cmda == rrr)
		cmdb = rrb;
	if (cmda == rra || cmda == rr)
		cmdb = rb;
	while (bin->a && bin->b && bin->a->nb != bin->nb
		&& bin->b->nb != bin->target && bin->b->nb != bin->nb
		&& bin->a->nb != bin->target)
		do_op(bin, cmda);
	if (cmda == rr)
		cmda = ra;
	if (cmda == rrr)
		cmda = rra;
	while (bin->a && bin->a->nb != bin->nb && bin->a->nb != bin->target)
		do_op(bin, cmda);
	while (bin->b && bin->b->nb != bin->target && bin->b->nb != bin->nb)
		do_op(bin, cmdb);
	if (direction)
		do_op(bin, pb);
	else
		do_op(bin, pa);
}
