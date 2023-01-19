/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:27:17 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/01/19 16:45:31 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/**
 * @brief
 * Iterates over the array of *CHAR
 * to transform them in INT 
 * then add to a linked list.
 * Also verifies if it's an INT 
 * and if the numbers 
 * are not duplicated.
*/
void	lst_init(t_pushswap *bin, char **argv, int i)
{
	t_stack	*a;
	t_stack	*tmp;
	int		nb;

	a = NULL;
	while (argv[i])
	{
		nb = ft_atoi(argv[i]);
		if (!is_int(argv[i], nb) || is_dup(a, nb))
		{
			if (a)
				free_stack(a);
			return ;
		}
		tmp = stack_new(nb);
		stack_addback(&a, tmp);
		i++;
	}
	bin->a = a;
}

/**
 * @brief
 * Does the parsing of the elements
 * passed in main().
 * If it finds an error it returns NULL,
 * otherwise it returns a T_PUSHSWAP where
 * T_PUSHSWAP->a points to the linked list.
 *  
*/
t_pushswap	*stack_init(char **argv, int argc)
{
	t_pushswap	*bin;
	int			ok;
	int			i;
	char		**tab;

	i = 1;
	tab = argv;
	if (argc == 2 && ft_strchr(argv[i], ' '))
		tab = ft_split(argv[i--], ' ');
	ok = parse_stack(tab, i);
	bin = malloc(sizeof(t_pushswap));
	if (!bin)
		ok = 0;
	if (!ok)
	{
		if (!i)
			free_tab(tab);
		return (NULL);
	}
	lst_init(bin, tab, i);
	if (!i)
		free_tab(tab);
	return (bin);
}

/**
 * @brief
 * Counts how many elements are in the stack
 * @return size of the stack
*/
int	stack_size(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

/**
 * @brief
 * Finds the greater number of the stack
 * @return
 * the greater number
*/
int	stack_max(t_stack *stack)
{
	int	max;

	max = stack->nb;
	stack = stack->next;
	while (stack)
	{
		if (stack->nb > max)
			max = stack->nb;
		stack = stack->next;
	}
	return (max);
}

/**
 * @brief
 * Finds the smallest number of the stack
 * @return
 * the smallest number
*/
int	stack_min(t_stack *stack)
{
	int	min;

	min = stack->nb;
	stack = stack->next;
	while (stack)
	{
		if (stack->nb < min)
			min = stack->nb;
		stack = stack->next;
	}
	return (min);
}

/**
 * @brief
 * Searchs the node with the correspondent NB in the stack
 * @return
 * the index of the node requested OR -1 if not exists.
*/
int	stack_get_i(t_stack *stack, int nb)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (nb == stack->nb)
			return (i);
		i++;
		stack = stack->next;
	}
	return (-1);
}

/**
 * @brief
 * It will fill the container with the informations 
 * from the stack A inside.
*/
void	fill_container(t_pushswap *bin)
{
	int		i;
	t_stack	*ptr;

	i = 0;
	bin->lstsize = stack_size(bin->a);
	bin->max = stack_max(bin->a);
	bin->min = stack_min(bin->a);
	bin->max_a = bin->max;
	bin->min_a = bin->min;
	ptr = bin->a;
	while (ptr)
	{
		ptr->index = i;
		i++;
		ptr = ptr->next;
	}
}

/**
 * @brief
 * Checks if the stack is sorted in ascending
 * order and returns 1 only if the last is the greater one
 * @return 
 * 1 == true OR 0 == false
*/
int	is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->nb > stack->next->nb)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/**
 * @brief
 * Checks if the stack is ordered even if not sorted
 * example: 4 5 6 7 8 9 0 1 2 3
 * @return 
 * 1 == true OR 0 == false
*/
int	is_ordered(t_stack *s)
{
	int	i;

	i = 0;
	while (s->next)
	{
		if (s->nb > s->next->nb)
			i++;
		s = s->next;
	}
	if (i > 1)
		return (0);
	return (1);
}

/**
 * @brief
 * Checks if the stack is ordered, but backwards.
 * It's not sorted sensitive.
 * example: 9 8 7 6 5 4 3  and  5 4 3 9 8 7 6
 * @return
 * 1 == inversed OR 0 == not inversed
*/
int	is_inversed(t_stack *s)
{
	int	i;

	i = 0;
	while (s->next)
	{
		if (s->nb < s->next->nb)
			i++;
		s = s->next;
	}
	if (i > 1)
		return (0);
	return (1);
}

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

/**
 * @brief
 * One function to rule them all!
 * 
 *  It sends the BIN to the given function. 
*/
void	do_op(t_pushswap *bin, void (*op)(t_pushswap *))
{
	op(bin);
}

/**
 * @brief
 * Checks the list of operations 
 * and free the longest list if that exists
*/
void	check_res(t_pushswap *bin)
{
	if (!bin->res)
	{
		bin->res = bin->res_tmp;
		bin->res_tmp = NULL;
	}
	else
	{
		if (ft_lstsize(bin->res) < ft_lstsize(bin->res_tmp))
			ft_lstclear(&bin->res_tmp, free);
		else
		{
			ft_lstclear(&bin->res, free);
			check_res(bin);
		}
	}
}


/**
 * @brief
 * algorithm to sort from 3 to 5 numbers.
 * It sends the fewer ones from stack A to stack B
 * untill have 3 numbers on stack A then it sorts A
 * based on the position of the greater number.
 * If B is not empty the numbers will be pushed back to A
*/
void	sort_few(t_pushswap *bin)
{
	int	max;

	while (stack_size(bin->a) > 3)
	{
		while (stack_get_i(bin->a, bin->min_a) > 0)
		{
			if (stack_get_i(bin->a, bin->min_a) < (stack_size(bin->a) / 2))
				do_op(bin, ra);
			else
				do_op(bin, rra);
			bin->min_a = stack_min(bin->a);
		}
		do_op(bin, pb);
	}
	max = stack_get_i(bin->a, bin->max);
	if (max == 2)
		do_op(bin, sa);
	else if (max == 1)
		do_op(bin, rra);
	else if (max == 0)
		do_op(bin, ra);
	if (!is_sorted(bin->a))
		do_op(bin, sa);
	while (bin->b)
		do_op(bin, pa);
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
	else if (bin->lstsize <= 5)
		sort_few(bin);
	else if (is_ordered(bin->a))
		ft_putendl_fd("todo with ordered", 1);
	else if (is_inversed(bin->a))
		ft_putendl_fd("todo with inversed", 1);
	else
		ft_putendl_fd("push swap", 1);
}

void	ft_error(t_pushswap *bin)
{
	(void)	bin;
	ft_putendl_fd("erro", 1);
	exit(1);
}

/**
 * @brief
 * It writes the list of operations followed by a '\n'
 * in the command line
*/
void	print_res(t_pushswap *bin)
{
	check_res(bin);
	while (bin->res)
	{
		ft_putendl_fd(bin->res->content, 1);
		bin->res = bin->res->next;
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
		print_res(bin);
		free_container(bin);
	}
	return (0);
}
