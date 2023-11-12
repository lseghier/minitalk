/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseghier <lseghier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 21:39:22 by lseghier          #+#    #+#             */
/*   Updated: 2023/11/12 18:17:25 by lseghier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include "minitalk.h"

/* Serveur */

void	stock_msg(char c);
void	signal_handler_serv(int signal, siginfo_t *info, void *context);

/* Client */

void	char_to_bin(int pid, char c);
void	send_char(int pid, char *str);
void	signal_handler_client(int signal, siginfo_t *info, void *context);

/* Utils */

int		ft_atoi(const char *str);
size_t	ft_strlen(char *s);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strjoin(char *s1, char c);

#endif
