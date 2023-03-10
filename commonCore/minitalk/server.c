/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 23:50:41 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/03/06 02:09:35 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/**
 * @brief
 * Initiates a T_STACK node
 * and sets NODE->nb = NB /
 * NODE->next = NULL
 *
 * @return t_stack *NODE
*/
t_stack	*stack_new(int nb)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->nb = nb;
	node->next = NULL;
	return (node);
}

/**
 * @brief
 * Adds the new node at the end of the stack
 * @param t_stack **stack
 * @param t_stack *new node
 *
*/
void	stack_addback(t_stack **stack, t_stack *new)
{
	t_stack	*ptr;

	ptr = *stack;
	if (ptr)
	{
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new;
	}
	else
		*stack = new;
}

/**
 * Takes a linked list of T_STACK and free all nodes.
*/
void	free_stack(t_stack **stack)
{
	t_stack	*ptr;

	while (*stack)
	{
		ptr = (*stack)->next;
		free(*stack);
		(*stack) = ptr;
	}
	// free(stack);
	stack = NULL;
}

void	print_message(t_stack *message)
{
	t_stack	*ptr;

	ptr = message;
	while (ptr)
	{
		ft_putchar_fd(ptr->nb, 1);
		ptr = ptr->next;
	}
	// free_stack(&message);
}

void	handle_sigusr(int sig)
{
	static int		bit = 0;
	static int		bit_count = 0;
	static t_stack	*c = NULL;

	// (void)context;
	// (void)info;
	if (sig == SIGUSR2)
	{
		bit = (bit << 1) | 1;
	}
	if (sig == SIGUSR1)
		bit <<= 1;
	bit_count++;
	if (bit_count == 8)
	{
		ft_putnbr_fd(bit, 1);
		ft_putstr_fd(" --> ", 1);
		ft_putchar_fd(bit, 1);
		ft_putchar_fd('\n', 1);
		if (bit)
			stack_addback(&c, stack_new(bit));
		if (!bit)
		{
			print_message(c);
			free_stack(&c);
		}
		bit = 0;
		bit_count = 0;
	}
	// if (sig == SIGUSR1)
	// 	ft_putchar_fd('0', 1);
	// if (sig == SIGUSR2)
	// 	ft_putchar_fd('1', 1);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	ft_putstr_fd("PID = ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_handler = &handle_sigusr;
	// sa.__sigaction_u.__sa_sigaction = handle_sigusr;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
