/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseghier <lseghier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 04:17:19 by lseghier          #+#    #+#             */
/*   Updated: 2023/11/12 18:15:52 by lseghier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar_fd (str[i++], fd);
		ft_putchar_fd ('\n', 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long long	num;

	num = n;
	if (num < 0)
	{
		ft_putchar_fd ('-', fd);
		num *= -1;
	}
	if (num <= 9)
		ft_putchar_fd(num + '0', fd);
	else if (num > 9)
	{
		ft_putnbr_fd(num / 10, fd);
		ft_putchar_fd(num % 10 + '0', fd);
	}
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char c)
{
	char	*dest;
	int		i;

	i = 0;
	if (s1 == NULL)
	{
		s1 = (malloc(1));
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	dest = malloc(sizeof(char) * (ft_strlen(s1) + 2));
	if (!dest)
		return (free(s1), NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i++] = c;
	dest[i] = '\0';
	return (free(s1), dest);
}
