/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:49:02 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/02/03 16:15:38 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 * Shift down all elements of stack A by 1.
 * The last element becomes the first one.
 * In case of succes it returns RRA else it returns NULL.
*/
char	*rra(t_pushswap *bin)
{
	if (rev_rotate(&bin->a))
		return (RRA);
	return (NULL);
}

/**
 * @brief
 * Shift down all elements of stack B by 1.
 * The last element becomes the first one.
 * In case of succes it returns RRB else it returns NULL.
*/
char	*rrb(t_pushswap *bin)
{
	if (rev_rotate(&bin->b))
		return (RRB);
	return (NULL);
}

/**
 * @brief
 *  rra and rrb at the same time
 * In case of succes it returns RRR 
 * if only RRA or only RRB are succeded it returns RRA or RRB
 *  else it returns NULL.
*/
char	*rrr(t_pushswap *bin)
{
	int		rra;
	int		rrb;

	rra = rev_rotate(&bin->a);
	rrb = rev_rotate(&bin->b);
	if (rra && rrb)
		return (RRR);
	else if (rra)
		return (RRA);
	else if (rrb)
		return (RRB);
	return (NULL);
}

/**
 * @brief
 * Take the first element at the top of A
 * and put it at the top of B. 
 * Do nothing if A is empty.
 * In case of succes it returns PB else it returns NULL.
*/
char	*pb(t_pushswap *bin)
{
	if (push(&bin->a, &bin->b))
		return (PB);
	return (NULL);
}

/**
 * @brief
 * Take the first element at the top of B
 * and put it at the top of A. 
 * Do nothing if B is empty.
 * In case of succes it returns PA else it returns NULL.
*/
char	*pa(t_pushswap *bin)
{
	if (push(&bin->b, &bin->a))
		return (PA);
	return (NULL);
}
