/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:30:16 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/01/26 18:57:31 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 * Analyses the chosen number on B and the target position on A
 * to decide if it will rotate up or down for each stack.
 * It will return a pointer to the right function to be used
 * @return
 * rr, rrr, ra(if it's ra and rrb) or rra(if it's rra and rb)
*/
static void	*rot_up_downa(t_pushswap *bin)
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
static void	*rot_up_downb(t_pushswap *bin)
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
