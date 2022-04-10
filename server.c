/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpozuelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:35:55 by jpozuelo          #+#    #+#             */
/*   Updated: 2022/04/10 20:05:26 by jpozuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	show_message(void)
{
	print_msg("Server's PID is: \t");
	print_nbr(getpid());
	print_msg(".\n");
}

void	bit_receiver(int signo, pid_t pid, volatile char *buff)
{
	volatile static char	caracter;
	volatile static char	counter;
	volatile static int		pos;

	if (signo == SIGUSR1)
		caracter |= (1 << (7 - counter));
	counter++;
	if (counter == 8)
	{
		buff[pos] = caracter;
		counter = 0;
		caracter = 0;
		if (!buff[pos])
		{
			pos = 0;
			kill(pid, SIGUSR2);
			return ;
		}
		pos++;
	}
	kill(pid, SIGUSR1);
}

void	listen(int signo, siginfo_t *info, __attribute((unused)) void *context)
{
	volatile static char	buff[10000000];

	bit_receiver(signo, info->si_pid, buff);
}

int	main(void)
{
	struct sigaction	listener;

	listener.sa_flags = SA_SIGINFO;
	listener.sa_sigaction = listen;
	show_message();
	sigaction(SIGUSR1, &listener, 0);
	sigaction(SIGUSR2, &listener, 0);
	while (1)
		pause();
}
