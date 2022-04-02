/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpozuelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:30:33 by jpozuelo          #+#    #+#             */
/*   Updated: 2022/04/01 21:24:14 by jpozuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	*msg;

static void	show_message(int flag)
{
	if (flag !=  2)
	{
		print_msg("Bad amount of arguments");
		exit(0);
	}
	else
	{
		print_msg("My PID is: \t");
		print_nbr(getpid());
		print_msg("\n");
	}
}


void	bit_sender(char c, char des, pid_t pid)
{
	if (c & (1 << des))
		kill(SIGUSR1, pid);
	else
		kill(SIGUSR2, pid);
	pause();
}

static void	listen(int signo, siginfo_t *info, void *context)
{
	static char	counter;
	static int	pos;

	if (signo == SIGUSR1)
	{
		if (info != NULL)
			bit_sender(msg[pos], counter, info->si_pid);
		else
			bit_sender(msg[pos], counter, *((pid_t *) context));
		if (++counter == 8)
		{
			pos++;
			counter = 0;
		}
	}
	else
		exit(0);
}

int main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	listener;

	listener.sa_flags = SA_SIGINFO;
	listener.sa_sigaction = listen;
	pid = (pid_t) atou(argv[1]);
	msg = argv[2];
	show_message(argc);
	sigaction(SIGUSR1, &listener, 0);
	sigaction(SIGUSR2, &listener, 0);
	listen(SIGUSR1, NULL, &pid);
}
