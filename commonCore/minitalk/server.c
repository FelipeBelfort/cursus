/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 23:50:41 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/03/17 14:10:46 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_message(t_stack *message)
{
	t_stack	*ptr;

	ptr = message;
	while (ptr)
	{
		write(1, &ptr->nb, 1);
		ptr = ptr->next;
	}
}

void	handle_sigusr(int sig, siginfo_t *info, void *ucontext)
{
	static int		bit = 0;
	static int		bit_count = 0;
	static t_stack	*message = NULL;

	(void) ucontext;
	if (sig == SIGUSR2)
	{
		bit = (bit << 1) | 1;
	}
	if (sig == SIGUSR1)
		bit <<= 1;
	bit_count++;
	if (bit_count == 8)
	{
		if (bit)
			stack_addback(&message, stack_new(bit));
		if (!bit)
		{
			print_message(message);
			free_stack(&message);
			kill(info->si_pid, SIGUSR2);
		}
		bit = 0;
		bit_count = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	ft_putstr_fd("PID = ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	// sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO | SA_NODEFER;
	sa.sa_sigaction = &handle_sigusr;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
