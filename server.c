/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpozuelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:35:55 by jpozuelo          #+#    #+#             */
/*   Updated: 2022/04/01 21:24:11 by jpozuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	show_message()
{
	print_msg("Server's PID is: \t");
	print_nbr(getpid());
	print_msg(".\n");
}

void	bit_receiver(int signo, pid_t pid, char *buff)
{
	static char caracter;
	static char counter;
	static int	pos;

	caracter |= (signo == SIGUSR1);
	if (++counter == 8)
	{
		buff[pos++] = caracter;
		if (caracter == 0)
		{
			kill(pid, SIGUSR2);
			buff[pos - 1] = '\n';
			print_msg(buff);
			clean(buff);
			pos = 0;
		}
		caracter = 0;
		counter = 0;
	}
	else
		caracter <<= 1;
}

void	listen(int signo, siginfo_t *info, void *context)
{
	static char	buff[12289];

	(ucontext_t *) context;
	bit_receiver(signo, info->si_pid, buff);
	kill(SIGUSR1, info->si_pid);
}

int main()
{
	struct sigaction	listener;

	listener.sa_flags = SA_SIGINFO;
	listener.sa_sigaction = listen;
	show_message();
	sigaction(SIGUSR1, &listener, 0);
	sigaction(SIGUSR2, &listener, 0);
	while(1)
		pause();
}
