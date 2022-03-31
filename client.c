/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpozuelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:30:33 by jpozuelo          #+#    #+#             */
/*   Updated: 2022/03/31 21:12:16 by jpozuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	show_message(int pid, int flag)
{
	if (flag !=  2)
		exit();
	if ()
}

int	bit_sender(char c, int i, int pid)
{
	if (c & (1 << i--))
		kill(SIGUSR1, pid);
	else
		kill(SIGUSR2, pid);
	pause();
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
