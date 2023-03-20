/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 23:50:38 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/03/19 22:58:44 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_sig;

void	handle_send(int sig)
{
	if (sig == SIGUSR1)
		g_sig = sig;
	if (sig == SIGUSR2)
	{
		ft_putendl_fd("Message sent.", 1);
		exit(0);
	}
}

void	handle_bad_pid(int stopped)
{
	static int	time = 0;

	if (!stopped)
	{
		time = 0;
		return ;
	}
	usleep(50);
	time += 50;
	if (time >= 500000)
	{
		ft_putendl_fd("Error: Could not reach the server, check the PID.", 2);
		exit(1);
	}
}

void	send_bit(int pid, int c)
{
	int	bit;
	int	curr;

	bit = 7;
	curr = (c >> bit--) & 1;
	if (!curr)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	ft_printf("%d", curr);
	while (bit >= 0)
	{
		if (g_sig == SIGUSR1)
		{
			handle_bad_pid(0);
			g_sig = 0;
			curr = (c >> bit) & 1;
			if (!curr)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			ft_printf("%d", curr);
			bit--;
		}
		else
			handle_bad_pid(1);
	}
}

void	send_message(int pid, char *message)
{
	int	i;

	i = -1;
	while (message[++i])
	{
		send_bit(pid, message[i]);
		ft_printf("%c", message[i]);
	}
	send_bit(pid, 0);
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa;

	if (argv[1])
		pid = ft_atoi(argv[1]);
	if (argv[1] && pid <= 0)
		ft_putendl_fd("Error: Invalid PID", 2);
	if (argc != 3)
		ft_putendl_fd("Error: Expected ./client <PID> <message>", 2);
	else
	{
		sa.sa_handler = handle_send;
		sa.sa_flags = SA_NODEFER | SA_RESTART;
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		send_message(pid, argv[2]);
		while(1)
			handle_bad_pid(1);
	}
	return (0);
}
