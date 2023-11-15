/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseghier <lseghier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 21:41:14 by lseghier          #+#    #+#             */
/*   Updated: 2023/11/13 19:18:59 by lseghier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	g_a;

void	char_to_bin(int pid, char c)
{
	int	bit;

	bit = 7;
	while (bit > -1)
	{
		g_a = 0;
		if ((c >> bit) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit--;
		while (g_a == 0)
			pause();
	}
}

void	send_char(int pid, char *str)
{
	size_t	i;

	i = 0;
	while (i <= ft_strlen(str))
		char_to_bin(pid, str[i++]);
}

void	signal_handler_client(int signal, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (signal == SIGUSR1)
		g_a = 1;
}

int	main(int ac, char **av)
{
	struct sigaction	act;

	act.sa_sigaction = signal_handler_client;
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	sigaction(SIGUSR1, &act, NULL);
	if (ac == 3)
		send_char(ft_atoi(av[1]), av[2]);
	return (0);
}
