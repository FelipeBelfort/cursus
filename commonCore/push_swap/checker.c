/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:14:28 by fbelfort          #+#    #+#             */
/*   Updated: 2023/01/30 20:02:06 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line/get_next_line.h"


// int	is_validop(char *op)
// {
// 	size_t	len;

// 	len = ft_strlen(op);
// 	if (!ft_memcmp(op, RRA, len) || !ft_memcmp(op, RRB, len)
// 		|| !ft_memcmp(op, RRR, len))
// 		return (4);
// 	if (!ft_memcmp(op, RA, len) || !ft_memcmp(op, RB, len)
// 		|| !ft_memcmp(op, RR, len))
// 		return (3);
// 	if (!ft_memcmp(op, SA, len) || !ft_memcmp(op, SB, len)
// 		|| !ft_memcmp(op, SS, len))
// 		return (2);
// 	if (!ft_memcmp(op, PA, len) || !ft_memcmp(op, PB, len))
// 		return (1);
// 	return (0);
// }

// void	fill_lst(t_pushswap *bin)
// {
// 	char	*line;
// 	t_list	*node;

// 	node = NULL;
// 	line = get_next_line(STDIN_FILENO);
// 	if (!is_validop(line))
// 		free(line);
// 	while (line)
// 	{
// 		node = ft_lstnew(line);
// 		if (!node)
// 		{
// 			ft_lstclear(&node, free);
// 			ft_error(bin);
// 		}
// 		ft_lstadd_back(&node, node);
// 		line = get_next_line(STDIN_FILENO);
// 		if (!is_validop(line))
// 		{
// 			free(line);
// 			ft_error(bin);
// 		}
// 	}
// 	bin->res = node;
// }

// void	do_checkerop(t_pushswap *bin, char *res, int op)
// {
// 	if (op == 4 && (res[2] == 'a' || res[2] == 'r'))
// 		rra(bin);
// 	if (op == 4 && (res[2] == 'b' || res[2] == 'r'))
// 		rrb(bin);
// 	if (op == 3 && (res[1] == 'a' || res[1] == 'r'))
// 		ra(bin);
// 	if (op == 3 && (res[1] == 'b' || res[1] == 'r'))
// 		rb(bin);
// 	if (op == 2 && (res[1] == 'a' || res[1] == 's'))
// 		sa(bin);
// 	if (op == 2 && (res[1] == 'b' || res[1] == 's'))
// 		sb(bin);
// 	if (op == 1 && res[1] == 'a')
// 		pa(bin);
// 	if (op == 1 && res[1] == 'b')
// 		pb(bin);
// }

// int	check_res(t_pushswap *bin)
// {
// 	t_list	*res;
// 	int		op;

// 	res = bin->res;
// 	while (res)
// 	{
// 		op = is_validop(res->content);
// 		do_checkerop(bin, res->content, op);
// 		res = res->next;
// 	}
// 	if (is_sorted(bin->a) && !bin->b)
// 		return (1);
// 	return (0);
// }

// int	main(int argc, char **argv)
// {
// 	t_pushswap	*bin;

// 	if (argc > 1)
// 	{
// 		bin = stack_init(argv, argc);
// 		if (!bin || !bin->a)
// 			ft_error(bin);
// 		if (is_sorted(bin->a))
// 			return (0);
// 		fill_lst(bin);
// 		if (!bin->res)
// 			ft_error(bin);
// 		if (check_res(bin))
// 			ft_putendl_fd("OK", 1);
// 		else
// 			ft_putendl_fd("KO", 1);
// 		free_container(bin);
// 	}
// 	return (0);
// }

#include <stdio.h>
void	debug_checker(t_pushswap *bin)
{
	t_stack *bla;
	
	bla = bin->a;
		printf("\nDebug-->\n");
	while (bla)
	{
		printf("%d,  ", bla->nb);
		bla = bla->next;
	}
		printf("\nFimDebug-->\n");
}

/**
 * @brief
 *  ra and rb at the same time
 * In case of succes it returns RR 
 * if only RA or only RB are succeded it returns RA or RB
 *  else it returns NULL.
*/
char	*ss(t_pushswap *bin)
{
	int		sa;
	int		sb;

	sa = rotate(&bin->a);
	sb = rotate(&bin->b);
	if (sa && sb)
		return (SS);
	else if (sa)
		return (SA);
	else if (sb)
		return (SB);
	return (NULL);
}

/**
 * @brief
 * One function to rule them all!
 * 
 *  It sends the BIN to the given function whitout printing 
 * the operation's name. 
*/
void	do_op_checker(t_pushswap *bin, char *(*op)(t_pushswap *))
{
	if (!bin || !op)
		return ;
	op(bin);
}

// static int	is_validop(char *op)
// {
// 	size_t	len;

// 	if (!op)
// 		return (0);
// 	len = ft_strlen(op);
// 	if (!ft_memcmp(op, RRA, len) || !ft_memcmp(op, RRB, len)
// 		|| !ft_memcmp(op, RRR, len))
// 		return (4);
// 	if (!ft_memcmp(op, RA, len) || !ft_memcmp(op, RB, len)
// 		|| !ft_memcmp(op, RR, len))
// 		return (3);
// 	if (!ft_memcmp(op, SA, len) || !ft_memcmp(op, SB, len)
// 		|| !ft_memcmp(op, SS, len))
// 		return (2);
// 	if (!ft_memcmp(op, PA, len) || !ft_memcmp(op, PB, len))
// 		return (1);
// 	return (0);
// }

// static void	do_checkerop(t_pushswap *bin, char *line, int op)
// {
// 	if (op == 4 && line[2] == 'a')
// 		do_op(bin, rra);
// 	if (op == 4 && line[2] == 'b')
// 		do_op(bin, rrb);
// 	if (op == 4 && line[2] == 'r')
// 		do_op(bin, rrr);
// 	if (op == 3 && line[1] == 'a')
// 		do_op(bin, ra);
// 	if (op == 3 && line[1] == 'b')
// 		do_op(bin, rb);
// 	if (op == 3 && line[1] == 'r')
// 		do_op(bin, rr);
// 	if (op == 2 && line[1] == 'a')
// 		do_op(bin, sa);
// 	if (op == 2 && line[1] == 'b')
// 		do_op(bin, sb);
// 	if (op == 2 && line[1] == 's')
// 		do_op(bin, ss);
// 	if (op == 1 && line[1] == 'a')
// 		do_op(bin, pa);
// 	if (op == 1 && line[1] == 'b')
// 		do_op(bin, pa);
// }

static void	*do_checkerop(char *op)
{
	size_t	len;

	if (!op)
		return (0);
	len = ft_strlen(op);
	if (!ft_memcmp(op, RRA, len))
		return (rra);
	if (!ft_memcmp(op, RRB, len))
		return (rrb);
	if (!ft_memcmp(op, RRR, len))
		return (rrr);
	if (!ft_memcmp(op, RA, len))
		return (ra);
	if (!ft_memcmp(op, RB, len))
		return (rb);
	if (!ft_memcmp(op, RR, len))
		return (rr);
	if (!ft_memcmp(op, SA, len))
		return (sa);
	if (!ft_memcmp(op, SB, len))
		return (sb);
	if (!ft_memcmp(op, SS, len))
		return (ss);
	if (!ft_memcmp(op, PA, len))
		return (pa);
	if (!ft_memcmp(op, PB, len))
		return (pa);
	return (NULL);
}

static void	check_lst(t_pushswap *bin)
{
	char	*line;
	void	*cmd;
	// int		op;

	line = get_next_line(STDIN_FILENO);
	if (!line)
		return ;
	cmd = do_checkerop(line);
	if (!cmd)
	{
		free(line);
		ft_error(bin);
	}
	while (line)
	{
		// printf("%s", line);
		do_op(bin, cmd);
		free(line);
		line = get_next_line(STDIN_FILENO);
		if (!line)
			return ;
		cmd = do_checkerop(line);
		// op = is_validop(line);
		if (!cmd)
		{
			free(line);
			ft_error(bin);
		}
		// do_checkerop(bin, line, op);
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
		fill_container(bin);
		debug_checker(bin);
		check_lst(bin);
		debug_checker(bin);
		if (is_sorted(bin->a) && stack_size(bin->a) == bin->lstsize)
			ft_putendl_fd("OK", 1);
		else
			ft_putendl_fd("KO", 1);
		free_container(bin);
	}
	return (0);
}