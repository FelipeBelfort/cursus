/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_utils1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:46:17 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/01/27 13:33:46 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 * Swap the first 2 elements at the top of stack A.
 * Do nothing if there is only one or no elements
 * In case of succes it returns SA else it returns NULL.
*/
char	*sa(t_pushswap *bin)
{
	if (swipe(&bin->a))
		return (SA);
	return (NULL);
}

/**
 * @brief
 * Swap the first 2 elements at the top of stack B.
 * Do nothing if there is only one or no elements
 * In case of succes it returns SB else it returns NULL.
*/
char	*sb(t_pushswap *bin)
{
	if (swipe(&bin->b))
		return (SB);
	return (NULL);
}

/**
 * @brief
 * Shift up all elements of stack A by 1.
 * The first element becomes the last one.
 * In case of succes it returns RA else it returns NULL.
*/
char	*ra(t_pushswap *bin)
{
	if (rotate(&bin->a))
		return (RA);
	return (NULL);
}

/**
 * @brief
 * Shift up all elements of stack B by 1.
 * The first element becomes the last one.
 * In case of succes it returns RB else it returns NULL.
*/
char	*rb(t_pushswap *bin)
{
	if (rotate(&bin->b))
		return (RB);
	return (NULL);
}

/**
 * @brief
 *  ra and rb at the same time
 * In case of succes it returns RR 
 * if only RA or only RB are succeded it returns RA or RB
 *  else it returns NULL.
*/
char	*rr(t_pushswap *bin)
{
	int		ra;
	int		rb;

	ra = rotate(&bin->a);
	rb = rotate(&bin->b);
	if (ra && rb)
		return (RR);
	else if (ra)
		return (RA);
	else if (rb)
		return (RB);
	return (NULL);
}
