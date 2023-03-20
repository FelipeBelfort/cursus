/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 23:50:41 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/03/19 22:49:29 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_message(t_stack *message)
{
	t_stack	*ptr;
	// char	*line;
	// int		len;
	// int		i;

	// i = 0;
	// ft_printf("\n mensagem ==>\n");
	// len = stack_size(message);
	// line = ft_calloc(len + 1, sizeof(char));
	ptr = message;
	while (ptr)
	{
		write(1, &ptr->nb, 1);
		// line[i++] = ptr->nb;
		ptr = ptr->next;
	}
	// ft_putstr_fd(line, 1);
}

void	handle_sigusr(int sig, siginfo_t *info, void *ucontext)
{
	static size_t	bit = 0;
	static int		bit_count = 0;
	// static int		pid = 0;
	static t_stack	*message = NULL;

	(void) ucontext;
	// if (!pid)
	// 	pid = info->si_pid;
	// if (pid && pid != info->si_pid)
	// 	return ;
	bit |= (sig == SIGUSR2);
	// ft_printf("%d", bit & 1);
		// bit = (bit << 1) | 1;
	// if (sig == SIGUSR1)
	// 	bit <<= 1;
	// bit_count++;
	if (++bit_count == 8)
	{
		// write(1, &bit, 1);
		bit_count = 0;
		if (bit)
			stack_addback(&message, stack_new(bit));
		if (!bit)
		{
			print_message(message);
			free_stack(&message);
			// pid = 0;
			kill(info->si_pid, SIGUSR2);
		}
		bit = 0;
	}
	// else
	bit <<= 1;
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
	// sa.sa_flags = SA_SIGINFO;
	sa.sa_flags = SA_SIGINFO | SA_NODEFER | SA_RESTART;
	sa.sa_sigaction = handle_sigusr;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
