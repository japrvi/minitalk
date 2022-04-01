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

static void	show_message(int pid, int flag)
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


void	bit_sender(char c, int i, int pid)
{

}

static void	listener(int signo, siginfo_t *info, void *context)
{
	static char	caracter;

}

int main(int argc, char **argv)
{
	pid_t			pid;
	char			*str;
	static int		i;

	pid = (pid_t) atou(argv[1]);
	str = argv[2];
	while (*str)
	{
		bit_sender(*str, &i, pid);
		str++;
	}
}
