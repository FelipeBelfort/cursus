/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 23:50:41 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/03/20 18:00:47 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_sigusr(int sig, siginfo_t *info, void *ucontext)
{
	static size_t	bit = 0;
	static int		bit_count = 0;

	(void) ucontext;
	if (sig == SIGUSR2)
		bit = (bit << 1) | 1;
	if (sig == SIGUSR1)
		bit <<= 1;
	if (++bit_count == 8)
	{
		bit_count = 0;
		if (bit)
			write(1, &bit, 1);
		bit = 0;
		kill(info->si_pid, SIGUSR2);
	}
	else
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
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_sigusr;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
