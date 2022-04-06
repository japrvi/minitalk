/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpozuelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:35:55 by jpozuelo          #+#    #+#             */
/*   Updated: 2022/04/06 19:30:01 by jpozuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <sys/errno.h>
#include <string.h>

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
		if (caracter == '\0')
		{
			print_msg(buff);
			pos = 0;
			kill(pid, SIGUSR2);
			return ;
		}
		caracter = 0;
		counter = 0;
	}
	else
	{
		caracter <<= 1;
		kill(pid, SIGUSR1);
	}
}

void	listen(int signo, siginfo_t *info, __attribute((unused)) void *context)
{
	static char	buff[12289];
	int errno;
	
	bit_receiver(signo, info->si_pid, buff);
	//printf("Recibido %d\n", info->si_pid);
	//printf("h%s", buff);
	//printf("%d\n", kill(info->si_pid, SIGUSR1));
	//printf("%s\n", strerror(errno));
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
