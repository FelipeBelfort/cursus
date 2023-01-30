/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:27:17 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/01/30 19:12:38 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 * It does the parsing to decide what function to call
 * to sort the list.
 * 
*/
static void	push_swap(t_pushswap *bin)
{
	fill_container(bin);
	if (bin->lstsize == 1 || is_sorted(bin->a))
		return ;
	else if (bin->lstsize <= 5)
		sort_few(bin);
	else if (is_ordered(bin->a))
		sort_ordered(bin);
	else if (is_inverted(bin->a))
		sort_inverted(bin);
	else
		sort_selectcost(bin);
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
		free_container(bin);
	}
	return (0);
}
