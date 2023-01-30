/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:05:45 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/01/30 15:42:52 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Takes a linked list of T_STACK and free all nodes.
*/
void	free_stack(t_stack *stack)
{
	t_stack	*ptr;

	while (stack)
	{
		ptr = stack->next;
		free(stack);
		stack = ptr;
	}
}

/**
 * @brief
 * The function checks if the container T_PUSHSWAP
 * has stacks or lists,
 * if that's the case it will free them
 * and then free the container it-self.
*/
void	free_container(t_pushswap *stacks)
{
	if (stacks->a)
		free_stack(stacks->a);
	if (stacks->b)
		free_stack(stacks->b);
	if (stacks->res)
		ft_lstclear(&stacks->res, free);
	free(stacks);
}

/**
 * @brief
 * Takes a array of arrays 
 * and iterates over it to free all the arrays inside
 * then free the array
*/
void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	tab = NULL;
}
