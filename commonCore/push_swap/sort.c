/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:56:01 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/01/23 14:31:20 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 * algorithm to sort from 3 numbers.
 * 
 * Based on the position of the greater number 
 * it will sort the stack in 1 or 2 operations.
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
 * 
 * It sends the fewer ones in order from stack A to stack B
 * untill have 3 numbers on stack A then it calls sort_3().
 * If B is not empty the numbers will be pushed back to A
*/
void	sort_selection(t_pushswap *bin)
{
	int		size;
	void	*cmd;

	size = bin->lstsize;
	while (size > 3)
	{
		bin->min_a = stack_min(bin->a);
		cmd = rra;
		if (stack_get_i(bin->a, bin->min_a) <= (size-- / 2))
			cmd = ra;
		while (stack_get_i(bin->a, bin->min_a) != 0)
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

	bin->min_a = stack_min(bin->a);
	if (stack_get_i(bin->a, bin->min_a) <= (stack_size(bin->a) / 2))
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
	if (stack_get_i(bin->a, bin->max_a) <= (size / 2))
		cmd = ra;
	while (stack_get_i(bin->a, bin->max_a))
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
 * It will sort the list based on radix algorithm.
 * Because we only have 2 stacks it is done using 
 * the bits.
 * It will always do the same amount of operations
 * based on the number of bits of the greater number.
*/
void	sort_radix(t_pushswap *bin)
{
	int		i;
	int		bit_max;
	void	*cmd;

	bit_max = 0;
	i = -1;
	while ((bin->max >> bit_max) != 0)
		bit_max++;
	while (bit_max-- > 0)
	{
		++i;
		while (bin->a->ordered == i)
		{
			cmd = ra;
			bin->a->ordered++;
			if (((bin->a->nb >> i) & 1) == 0)
				cmd = pb;
			do_op(bin, cmd);
		}
		while (bin->b)
			do_op(bin, pa);
	}
}
