/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpozuelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:35:55 by jpozuelo          #+#    #+#             */
/*   Updated: 2022/03/30 21:06:53 by jpozuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	buff[12289];

void	show_message()
{
	print_msg("Server's PID is: \t");
	printr_nbr(getpid());
	print_msg(".\n");
}

void	bit_receiver(int signo, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	i = 0;
	static int	counter = 0;

	c |= (SIGUSR1 == signo);
	if (++i == 8)
	{
		buff[counter++] = c;
		if (c == 0)
		{
			print_msg(buff);
			kill(info->si_signo, SIGUSR2);
			clean(buff);
		}
		else
			kill(info->si_signo, SIGUSR1);
		c = 0;
		i = 0;
	}
	else 
		c <<= 1;
}

int main(int argc, char **argv)
{
	struct sigaction	listener;

	listener.sa_flags = SA_SIGINFO;
	listener.sa_sigaction = &bit_receiver;
	show_message();
	while(1)
		pause();
	exit();
}
