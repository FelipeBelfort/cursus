/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:49:02 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/01/23 14:31:20 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 * Shift down all elements of stack A by 1.
 * The last element becomes the first one.
 * In case of succes it increments the list of operations
 * otherwise nothing is written.
*/
void	rra(t_pushswap *bin)
{
	t_list	*lst;

	if (rev_rotate(&bin->a))
	{
		lst = ft_lstnew(RRA);
		ft_lstadd_back(&bin->res_tmp, lst);
	}
}

/**
 * @brief
 * Shift down all elements of stack B by 1.
 * The last element becomes the first one.
 * In case of succes it increments the list of operations
 * otherwise nothing is written.
*/
void	rrb(t_pushswap *bin)
{
	t_list	*lst;

	if (rev_rotate(&bin->b))
	{
		lst = ft_lstnew(RRB);
		ft_lstadd_back(&bin->res_tmp, lst);
	}
}

/**
 * @brief
 *  rra and rrb at the same time
*/
void	rrr(t_pushswap *bin)
{
	t_list	*lst;
	int		rra;
	int		rrb;

	rra = rotate(&bin->a);
	rrb = rotate(&bin->b);
	if (rra && rrb)
		lst = ft_lstnew(RRR);
	else if (rra)
		lst = ft_lstnew(RRA);
	else if (rrb)
		lst = ft_lstnew(RRB);
	if (lst)
		ft_lstadd_back(&bin->res_tmp, lst);
}

/**
 * @brief
 * Take the first element at the top of A
 * and put it at the top of B. 
 * Do nothing if A is empty.
 * In case of succes it increments the list of operations
 * otherwise nothing is written.
*/
void	pb(t_pushswap *bin)
{
	t_list	*lst;

	if (push(&bin->a, &bin->b))
	{
		lst = ft_lstnew(PB);
		ft_lstadd_back(&bin->res_tmp, lst);
	}
}

/**
 * @brief
 * Take the first element at the top of B
 * and put it at the top of A. 
 * Do nothing if B is empty.
 * In case of succes it increments the list of operations
 * otherwise nothing is written.
*/
void	pa(t_pushswap *bin)
{
	t_list	*lst;

	if (push(&bin->b, &bin->a))
	{
		lst = ft_lstnew(PA);
		ft_lstadd_back(&bin->res_tmp, lst);
	}
}
