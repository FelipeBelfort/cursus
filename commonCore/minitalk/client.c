/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 23:50:38 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/03/11 23:48:01 by FelipeBelfo      ###   ########.fr       */
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
	int	i;
	int	curr;
	int	bit;

	i = -1;
	while (message[++i])
	{
		bit = 8;
		while (--bit >= 0)
		{
			curr = (message[i] >> bit) & 1;
			if (!curr)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(80);
		}
	}
	send_null(pid);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		ft_putendl_fd("Error: Expected ./client <PID> <message>", 1);
	else
		send_bits(ft_atoi(argv[1]), argv[2]);

	return (0);
}
