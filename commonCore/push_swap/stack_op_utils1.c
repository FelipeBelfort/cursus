/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_utils1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:46:17 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/01/23 13:48:30 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 * Swap the first 2 elements at the top of stack A.
 * Do nothing if there is only one or no elements
 * In case of succes it increments the list of operations
 * otherwise nothing is written.
*/
void	sa(t_pushswap *bin)
{
	t_list	*lst;

	if (swipe(&bin->a))
	{
		lst = ft_lstnew(SA);
		ft_lstadd_back(&bin->res_tmp, lst);
	}
}

/**
 * @brief
 * Swap the first 2 elements at the top of stack B.
 * Do nothing if there is only one or no elements
 * In case of succes it increments the list of operations
 * otherwise nothing is written.
*/
void	sb(t_pushswap *bin)
{
	t_list	*lst;

	if (swipe(&bin->b))
	{
		lst = ft_lstnew(SB);
		ft_lstadd_back(&bin->res_tmp, lst);
	}
}

/**
 * @brief
 * Shift up all elements of stack A by 1.
 * The first element becomes the last one.
 * In case of succes it increments the list of operations
 * otherwise nothing is written.
*/
void	ra(t_pushswap *bin)
{
	t_list	*lst;

	if (rotate(&bin->a))
	{
		lst = ft_lstnew(RA);
		ft_lstadd_back(&bin->res_tmp, lst);
	}
}

/**
 * @brief
 * Shift up all elements of stack B by 1.
 * The first element becomes the last one.
 * In case of succes it increments the list of operations
 * otherwise nothing is written.
*/
void	rb(t_pushswap *bin)
{
	t_list	*lst;

	if (rotate(&bin->b))
	{
		lst = ft_lstnew(RB);
		ft_lstadd_back(&bin->res_tmp, lst);
	}
}

/**
 * @brief
 *  ra and rb at the same time
*/
void	rr(t_pushswap *bin)
{
	t_list	*lst;
	int		ra;
	int		rb;

	ra = rotate(&bin->a);
	rb = rotate(&bin->b);
	if (ra && rb)
		lst = ft_lstnew(RR);
	else if (ra)
		lst = ft_lstnew(RA);
	else if (rb)
		lst = ft_lstnew(RB);
	if (lst)
		ft_lstadd_back(&bin->res_tmp, lst);
}
