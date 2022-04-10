/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpozuelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 19:13:41 by jpozuelo          #+#    #+#             */
/*   Updated: 2022/04/10 19:01:23 by jpozuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_msg(char *msg)
{
	size_t	len;

	len = 0;
	while (msg[len])
		len++;
	write(1, msg, len);
}

void	print_nbr(unsigned int nbr)
{
	char	c;

	if (nbr > 9)
	{
		print_nbr(nbr / 10);
		print_nbr(nbr % 10);
	}
	else
	{
		c = nbr + '0';
		write(1, &c, 1);
	}
}

void	clean(char *buff)
{
	size_t	i;

	i = 0;
	while (buff[i])
	{
		buff[i] = 0;
		i++;
	}
}

int	atou(char *str)
{
	size_t			i;
	int				res;

	i = 0;
	res = 0;
	while  (str[i])
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}
