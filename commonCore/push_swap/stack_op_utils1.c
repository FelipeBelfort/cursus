/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_utils1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:46:17 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/01/26 18:48:12 by fbelfort         ###   ########.fr       */
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
		lst = ft_lstnew(ft_strdup("sa"));
		if (!lst)
			return ;
		ft_lstadd_back(&bin->res, lst);
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
		lst = ft_lstnew(ft_strdup("sb"));
		if (!lst)
			return ;
		ft_lstadd_back(&bin->res, lst);
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
		lst = ft_lstnew(ft_strdup("ra"));
		if (!lst)
			return ;
		ft_lstadd_back(&bin->res, lst);
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
		lst = ft_lstnew(ft_strdup("rb"));
		if (!lst)
			return ;
		ft_lstadd_back(&bin->res, lst);
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
	char	*txt;

	ra = rotate(&bin->a);
	rb = rotate(&bin->b);
	lst = NULL;
	txt = NULL;
	if (ra && rb)
		txt = ft_strdup("rr");
	else if (ra)
		txt = ft_strdup("rr");
	else if (rb)
		txt = ft_strdup("rb");
	if (txt)
	{
		lst = ft_lstnew(txt);
		if (!lst)
			return ;
	}
	ft_lstadd_back(&bin->res, lst);
}
