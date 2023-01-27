/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:14:28 by fbelfort          #+#    #+#             */
/*   Updated: 2023/01/27 18:39:12 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line/get_next_line.h"

int	is_validop(char *op)
{
	size_t	len;

	len = ft_strlen(op);
	if (!ft_memcmp(op, RRA, len) || !ft_memcmp(op, RRB, len)
		|| !ft_memcmp(op, RRR, len))
		return (4);
	if (!ft_memcmp(op, RA, len) || !ft_memcmp(op, RB, len)
		|| !ft_memcmp(op, RR, len))
		return (3);
	if (!ft_memcmp(op, SA, len) || !ft_memcmp(op, SB, len)
		|| !ft_memcmp(op, SS, len))
		return (2);
	if (!ft_memcmp(op, PA, len) || !ft_memcmp(op, PB, len))
		return (1);
	return (0);
}

void	fill_lst(t_pushswap *bin)
{
	char	*line;
	t_list	*node;

	line = get_next_line(STDIN_FILENO);
	if (!is_validop(line))
		free(line);
	while (line)
	{
		node = ft_lstnew(line);
		if (!node)
		{
			ft_lstclear(&node, free);
			ft_error(bin);
		}
		ft_lstadd_back(&node, node);
		line = get_next_line(STDIN_FILENO);
		if (!is_validop(line))
		{
			free(line);
			ft_error(bin);
		}
	}
	bin->res = node;
}

void	do_checkerop(t_pushswap *bin, char *res, int op)
{
	if (op == 4 && (res[2] == 'a' || res[2] == 'r'))
		rra(bin);
	if (op == 4 && (res[2] == 'b' || res[2] == 'r'))
		rrb(bin);
	if (op == 3 && (res[1] == 'a' || res[1] == 'r'))
		ra(bin);
	if (op == 3 && (res[1] == 'b' || res[1] == 'r'))
		rb(bin);
	if (op == 2 && (res[1] == 'a' || res[1] == 's'))
		sa(bin);
	if (op == 2 && (res[1] == 'b' || res[1] == 's'))
		sb(bin);
	if (op == 1 && res[1] == 'a')
		pa(bin);
	if (op == 1 && res[1] == 'b')
		pb(bin);
}

int	check_res(t_pushswap *bin)
{
	t_list	*res;
	int		op;

	res = bin->res;
	while (res)
	{
		op = is_validop(res->content);
		do_checkerop(bin, res->content, op);
		res = res->next;
	}
	if (is_sorted(bin->a) && !bin->b)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_pushswap	*bin;

	if (argc > 1)
	{
		bin = stack_init(argv, argc);
		if (!bin || !bin->a)
			ft_error(bin);
		if (is_sorted(bin->a))
			return (0);
		fill_lst(bin);
		if (!bin->res)
			ft_error(bin);
		if (check_res(bin))
			ft_putendl_fd("OK", 1);
		else
			ft_putendl_fd("KO", 1);
		free_container(bin);
	}
	return (0);
}
