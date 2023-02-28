/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:56:01 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/02/03 16:47:11 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 * algorithm to sort 3 numbers. (But also works with 2)
 * 
 * Based on the position of the greater number 
 * it will sort the stack in 1 or 2 operations,
 * based on the position of the greater element.
 * There are always (n! - 1) possibilities of order 
 * for a given n, so it is easy to find the solution
 * for the 5 possibilities for 3 numbers. 
*/
void	sort_3(t_pushswap *bin)
{
	int		max_i;
	int		max;

	max = stack_max(bin->a);
	max_i = stack_get_i(bin->a, max);
	if (max_i == 1)
		do_op(bin, rra);
	else if (max_i == 0)
		do_op(bin, ra);
	if (!is_sorted(bin->a))
		do_op(bin, sa);
}

/**
 * @brief
 * To sort 4 or 5 elements.
 * It will look for the smaller one and PB
 *  untill there are 3 elements.
 * Then it uses sort_3() and PA while there is an element 
 *  on stack b.
*/
void	sort_few(t_pushswap *bin)
{
	int		min;
	void	*cmd;

	while (stack_size(bin->a) > 3)
	{
		min = stack_min(bin->a);
		cmd = ra;
		if (stack_get_i(bin->a, min) > stack_size(bin->a) / 2)
			cmd = rra;
		while (bin->a->nb != min)
			do_op(bin, cmd);
		do_op(bin, pb);
	}
	sort_3(bin);
	while (bin->b)
		do_op(bin, pa);
}

/**
 * @brief
 * sort the stack if it's already ordered and it needs 
 * only to be rotated.
*/
void	sort_ordered(t_pushswap *bin)
{
	void	*cmd;
	int		min_a;

	min_a = stack_min(bin->a);
	if (stack_get_i(bin->a, min_a) <= (stack_size(bin->a) / 2))
		cmd = ra;
	else
		cmd = rra;
	while (!is_sorted(bin->a))
		do_op(bin, cmd);
}

/**
 * @brief
 * sort the stack if it's inverted.
 * If it needs it will rotate the stack until the greater one
 * be on the top, then it PB all the list and PA and RA each
 * element.
*/
void	sort_inverted(t_pushswap *bin)
{
	void	*cmd;
	int		size;

	size = bin->lstsize;
	cmd = rra;
	if (stack_get_i(bin->a, bin->max) <= (size / 2))
		cmd = ra;
	while (stack_get_i(bin->a, bin->max))
		do_op(bin, cmd);
	while (size-- > 3)
		do_op(bin, pb);
	sort_3(bin);
	while (bin->b)
	{
		do_op(bin, pa);
		do_op(bin, ra);
	}
}

/**
 * @brief
 * First of all if the stack has more then 200 elements
 * it will send the smaller half from A to B.
 * Then it will do a selection sort based on the number of
 * moves to put the element in the right place.
 * It keeps doing it untill the stack is ordered(even if it's not sorted)
 * or it reaches a size of 3 elements, if that's the case 
 * it calls the sort_3() then it does the same to push back to A
 * finaly it calls sort_ordered()
*/
void	sort_selectcost(t_pushswap *bin)
{
	if (bin->lstsize > 200)
		filter_bigstack(bin);
	else
		do_op(bin, pb);
	while (bin->a->next->next->next && !is_ordered(bin->a))
		push_to(bin, TO_B);
	if (!is_ordered(bin->a))
		sort_3(bin);
	while (bin->b)
		push_to(bin, TO_A);
	sort_ordered(bin);
}
