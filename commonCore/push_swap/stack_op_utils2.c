/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:49:02 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/01/26 18:48:12 by fbelfort         ###   ########.fr       */
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
		lst = ft_lstnew(ft_strdup("rra"));
		ft_lstadd_back(&bin->res, lst);
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
		lst = ft_lstnew(ft_strdup("rrb"));
		if (!lst)
			return ;
		ft_lstadd_back(&bin->res, lst);
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
	char	*txt;

	rra = rev_rotate(&bin->a);
	rrb = rev_rotate(&bin->b);
	lst = NULL;
	txt = NULL;
	if (rra && rrb)
		txt = ft_strdup("rrr");
	else if (rra)
		txt = ft_strdup("rra");
	else if (rrb)
		txt = ft_strdup("rrb");
	if (txt)
	{
		lst = ft_lstnew(txt);
		if (!lst)
			return ;
	}
	ft_lstadd_back(&bin->res, lst);
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
		lst = ft_lstnew(ft_strdup("pb"));
		if (!lst)
			return ;
		ft_lstadd_back(&bin->res, lst);
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
		lst = ft_lstnew(ft_strdup("pa"));
		if (!lst)
			return ;
		ft_lstadd_back(&bin->res, lst);
	}
}
