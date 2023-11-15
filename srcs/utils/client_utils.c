/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseghier <lseghier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 03:20:19 by lseghier          #+#    #+#             */
/*   Updated: 2023/11/13 19:19:45 by lseghier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_atoi(const char	*str)
{
	size_t		i;
	long long	j;
	int			sign;

	i = 0;
	j = 0;
	sign = 1;
	if (str[i] == ' ' || (str[i] <= 13 && str[i] >= 9))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (j * sign > 2147483647)
			return (-1);
		else if (j * sign < -2147483648)
			return (0);
		j = j * 10 + str[i] - '0';
		i++;
	}
	return (j * sign);
}
