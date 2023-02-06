/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:14:28 by fbelfort          #+#    #+#             */
/*   Updated: 2023/02/03 18:10:32 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 * Does sa and sb at the same time
 * It's not with the others because I don't use it
 * It's here just in case the checker takes that command
*/
static void	ss(t_pushswap *bin)
{
	swipe(&bin->a);
	swipe(&bin->b);
}

/**
 * @brief
 * One function to rule them all!
 * 
 *  It sends the BIN to the given function whitout printing 
 * the operation's name. 
*/
static void	do_op_checker(t_pushswap *bin, char *(*op)(t_pushswap *))
{
	if (!bin || !op)
		return ;
	op(bin);
}

/**
 * @brief
 * It checks if the given operation is a valid one,
 * if that's the case it will return the right function
 * to be used, otherwise it returns NULL.
 * @param char *op the line read from the terminal
 * @param size_t len the length of the line *op
 * @return
 * The matching function or NULL if the line is invalid.
*/
static void	*do_checkerop(char *op, size_t len)
{
	if (!op)
		return (NULL);
	if (!ft_memcmp(op, RRA, len))
		return (rra);
	else if (!ft_memcmp(op, RRB, len))
		return (rrb);
	else if (!ft_memcmp(op, RRR, len))
		return (rrr);
	else if (!ft_memcmp(op, RA, len))
		return (ra);
	else if (!ft_memcmp(op, RB, len))
		return (rb);
	else if (!ft_memcmp(op, RR, len))
		return (rr);
	else if (!ft_memcmp(op, SA, len))
		return (sa);
	else if (!ft_memcmp(op, SB, len))
		return (sb);
	else if (!ft_memcmp(op, SS, len))
		return (ss);
	else if (!ft_memcmp(op, PA, len))
		return (pa);
	else if (!ft_memcmp(op, PB, len))
		return (pb);
	return (NULL);
}

/**
 * @brief
 * This function will read the command line 
 * to get the lines, then it will verify and do the 
 * command untill there is no more lines to read.
 * If the line has invalid characters it will 
 * call FT_ERROR() 
*/
static void	check_lst(t_pushswap *bin)
{
	char	*line;
	void	*cmd;
	size_t	len;

	line = NULL;
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		len = ft_strlen(line);
		cmd = do_checkerop(line, len);
		if (!cmd)
		{
			free(line);
			ft_error(bin);
		}
		do_op_checker(bin, cmd);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	if (line != NULL)
		free(line);
}

int	main(int argc, char **argv)
{
	t_pushswap	*bin;

	if (argc > 1)
	{
		bin = stack_init(argv, argc);
		if (!bin || !bin->a)
			ft_error(bin);
		check_lst(bin);
		if (is_sorted(bin->a) && !stack_size(bin->b))
			ft_putendl_fd("OK", 1);
		else
			ft_putendl_fd("KO", 1);
		free_container(bin);
	}
	return (0);
}
