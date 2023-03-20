/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 23:50:38 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/03/20 18:11:51 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_sig;

void	handle_send(int sig)
{
	g_sig = sig;
}

void	handle_bad_pid(int stopped)
{
	static int	time = 0;

	if (!stopped)
		time = 0;
	usleep(50);
	time += 50;
	if (time >= 8000000)
	{
		ft_putendl_fd("Error: Connexion problem, check the PID.", 2);
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
	while (bit >= 0)
	{
		if (g_sig == SIGUSR1)
		{
			g_sig = 0;
			curr = (c >> bit) & 1;
			bit--;
			if (!curr)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			handle_bad_pid(0);
		}
		handle_bad_pid(1);
	}
}

void	send_message(int pid, char *message)
{
	int	i;
	int	len;
	int	bitend;

	len = ft_strlen(message);
	ft_printf("Sent %d bits.\n", len);
	bitend = 0;
	i = -1;
	while (message[++i])
	{
		if (i == 0 || g_sig == SIGUSR2)
		{
			bitend++;
			send_bit(pid, message[i]);
		}
		usleep(80);
	}
	send_bit(pid, 0);
	while (g_sig != SIGUSR2)
		pause();
	if (bitend == len)
		ft_printf("received %d bits.\n", bitend);
	else
		ft_putendl_fd("Message sent.", 1);
	exit(0);
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
	else if (pid > 0)
	{
		sa.sa_handler = handle_send;
		sa.sa_flags = SA_NODEFER | SA_RESTART;
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		send_message(pid, argv[2]);
		while (1)
			handle_bad_pid(1);
	}
	return (0);
}
