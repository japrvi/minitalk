/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpozuelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:14:02 by jpozuelo          #+#    #+#             */
/*   Updated: 2022/04/21 17:08:47 by jpozuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

void	print_msg(char *msg);
void	print_nbr(unsigned int nbr);
void	clean(char *buff);
int		atou(char *str);

#endif
