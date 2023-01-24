/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:27:17 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/01/23 19:23:17 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>



// /**
//  * @brief
//  * 
// */
// void	*check_unord(t_stack *s)
// {
// 	int		up;
// 	int		down;
// 	int		mid;
// 	void	*cmd;

// 	cmd = ra;
// 	up = 0;
// 	down = 0;
// 	mid = stack_size(s) / 2;
// 	while (s)
// 	{
// 		if (!s->ordered)
// 		{
// 			if (s->index <= mid)
// 				up++;
// 			else
// 				down++;
// 		}
// 		s = s->next;
// 	}
// 	if (down > up)
// 		cmd = rra;
// 	return (cmd);
// }


// int	scan_pa(t_pushswap *bin)
// {
// 	int		last;
// 	t_stack	*a;
// 	t_stack	*b;

// 	a = bin->a;
// 	b = bin->b;
// 	last = stack_last(b)->nb;
// 	bin->max_a = stack_max(a);
// 	if (!a || stack_size(a) == 1 || (a->nb > b->nb
// 			&& (a->nb > last || last == bin->max_a)))
// 	{
// 		do_op(bin, pa);
// 		return (1);
// 	}
// 	else if (a->nb < b->nb && a->next->nb > b->nb)
// 	{
// 		do_op(bin, pa);
// 		do_op(bin, sa);
// 		return (1);
// 	}
// 	return (0);
// }

// void	find_placea(t_pushswap *bin)
// {
// 	int		i;
// 	int		prev;
// 	void	*cmd;
// 	t_stack	*a;

// 	i = 0;
// 	a = bin->a;
// 	prev = stack_last(a)->nb;
// 	bin->max_a = stack_max(a);
// 	cmd = rra;
// 	while (a)
// 	{
// 		++i;
// 		if (bin->b->nb < a->nb
// 			&& (bin->b->nb > prev || prev == bin->max_a))
// 		{
// 			if (i <= stack_size(bin->a) / 2)
// 				cmd = ra;
// 			break ;
// 		}
// 		prev = a->nb;
// 		a = a->next;
// 	}
// 	while (!scan_pa(bin))
// 		do_op(bin, cmd);
// }

// int	scan_pb(t_pushswap *bin)
// {
// 	int		last;
// 	t_stack	*a;
// 	t_stack	*b;

// 	a = bin->a;
// 	b = bin->b;
// 	last = stack_last(b)->nb;
// 	bin->min_b = stack_min(b);
// 	if (!b || stack_size(b) == 1 || (a->nb > b->nb
// 			&& (a->nb < last || last == bin->min_b)))
// 	{
// 		do_op(bin, pb);
// 		return (1);
// 	}
// 	else if (a->nb < b->nb && a->nb > b->next->nb)
// 	{
// 		do_op(bin, pb);
// 		do_op(bin, sb);
// 		return (1);
// 	}
// 	return (0);
// }

// void	find_placeb(t_pushswap *bin)
// {
// 	int		i;
// 	int		size;
// 	void	*cmd;
// 	t_stack	*b;

// 	i = 0;
// 	b = bin->b;
// 	size = stack_size(bin->b) / 2;
// 	cmd = rrb;
// 	while (b->next)
// 	{
// 		++i;
// 		if (bin->a->nb < b->nb && bin->a->nb > b->next->nb)
// 		{
// 			if (i <= size)
// 				cmd = rb;
// 			break ;
// 		}
// 		b = b->next;
// 	}
// 	while (!scan_pb(bin))
// 		do_op(bin, cmd);
// }

// void	pick_move(t_pushswap *bin)
// {
// 	t_stack	*nxt;
// 	t_stack	*prv;

// 	nxt = bin->a->next;
// 	prv = stack_last(bin->a);
// 	if (bin->a->ordered && !nxt->ordered)
// 	{
// 		if (bin->a->nb > nxt->nb && nxt->nb > prv->nb)
// 		{
// 			nxt->ordered = 1;
// 			do_op(bin, sa);
// 		}
// 	}
// 	else if (!bin->a->ordered)
// 		find_placeb(bin);
// }

// void	sort_selectord(t_pushswap *bin)
// {
// 	void	*way;

// 	set_ordered(bin->a);
// 	way = check_unord(bin->a);
// 	while (!is_ordered(bin->a))
// 	{
// 		pick_move(bin);
// 		if (bin->a->ordered)
// 			do_op(bin, way);
// 	}
// 	while (bin->b)
// 		find_placea(bin);
// 	if (is_ordered(bin->a))
// 		sort_ordered(bin);
// }



/**
 * @brief
 * Checks the list of operations 
 * and free the longest list if that exists
*/
void	check_res(t_pushswap *bin)
{
	if (!bin->res && !bin->res_tmp)
		return ;
	if (!bin->res)
	{
		bin->res = bin->res_tmp;
		bin->res_tmp = NULL;
	}
	else if (bin->res_tmp)
	{
		if (ft_lstsize(bin->res) <= ft_lstsize(bin->res_tmp))
			free_lst(bin->res_tmp);
		else
		{
			free_lst(bin->res);
			bin->res = bin->res_tmp;
			bin->res_tmp = NULL;
		}
	}
}

/**
 * @brief
 * If the stack has more than 3 elements,
 * is not ordered, nor inverted
 * it will pass through a selection sort,
 * and a radix sort.
 * Between each function 
 * the stack will be reset and the results are compared
 * to keep the smallest one.
*/
void	sort_complex(t_pushswap *bin)
{
	sort_selection(bin);
	if (is_sorted(bin->a) && stack_size(bin->a) == bin->lstsize)
		printf("\nOk -> \n");
	printf("\nselection -> %d\n", ft_lstsize(bin->res_tmp));
	reset_stack(bin);
	check_res(bin);
	sort_selectcost(bin);
	if (is_sorted(bin->a) && stack_size(bin->a) == bin->lstsize)
		printf("\nOk -> \n");
	printf("\nselectcost -> %d\n", ft_lstsize(bin->res_tmp));
	reset_stack(bin);
	check_res(bin);
	sort_radix(bin);
	if (is_sorted(bin->a) && stack_size(bin->a) == bin->lstsize)
		printf("\nOk -> \n");
	printf("\nradix -> %d\n", ft_lstsize(bin->res_tmp));
}

/**
 * @brief
 * It does the parsing to decide what function to call
 * to sort the list.
 * 
*/
void	push_swap(t_pushswap *bin)
{
	fill_container(bin);
	if (bin->lstsize == 1 || is_sorted(bin->a))
		return ;
	else if (bin->lstsize == 2)
		do_op(bin, sa);
	else if (bin->lstsize == 3)
		sort_3(bin);
	else if (is_ordered(bin->a))
		sort_ordered(bin);
	else if (is_inverted(bin->a))
		sort_inverted(bin);
	else
		sort_complex(bin);
}

/**
 * @brief
 * It writes the list of operations followed by a '\n'
 * in the command line
*/
void	print_res(t_pushswap *bin)
{
	t_list	*ptr;

	check_res(bin);
	ptr = bin->res;
	while (ptr)
	{
		ft_putendl_fd(ptr->content, 1);
		ptr = ptr->next;
	}
}

int	main(int argc, char **argv)
{
	t_pushswap	*bin;

	if (argc > 1)
	{
		bin = stack_init(argv, argc);
		if (!bin || !bin->a)
			ft_error(bin);
		push_swap(bin);
		// print_res(bin);
		free_container(bin);
	}
	return (0);
}
