/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 23:50:38 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/03/17 14:10:48 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_null(int pid)
{
	int	bit;

	bit = -1;
	while (++bit < 8)
	{
		kill(pid, SIGUSR1);
		usleep(90);
	}
}

void	send_bits(int pid, char *message)
{
	static int	i = 0;
	static int	bit = 8;
	int			curr;

	// i = -1;
	// while (message[++i])
	// {
	// 	bit = 8;
	// 	while (--bit >= 0)
	// 	{
	// 		curr = (message[i] >> bit) & 1;
	// 		if (!curr)
	// 			kill(pid, SIGUSR1);
	// 		else
	// 			kill(pid, SIGUSR2);
	// 		usleep(100);
	// 	}
	// }
	// send_null(pid);
	if(!message[i] || !message)
		send_bits(pid, "\0");
	curr = (message[i] >> bit) & 1;
	if (!curr)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	bit--;
	if (!bit)
	{
		bit = 8;
		i++;
	}
}

void	handle_send(in)

int	main(int argc, char **argv)
{
	int	pid;

	if (argv[1])
		pid = ft_atoi(argv[1]);
	if (argv[1] && pid < 1)
		ft_putendl_fd("Error: Invalid PID", 1);
	if (argc != 3 || (argc == 3 && pid <= 0))
		ft_putendl_fd("Error: Expected ./client <PID> <message>", 1);
	else
	{
		send_bits(pid, argv[2]);
		while (1)
			pause();
	}
	return (0);
}
