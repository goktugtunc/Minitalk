/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 11:32:45 by gotunc            #+#    #+#             */
/*   Updated: 2023/08/19 11:33:59 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *s)
{
	int	i;
	int	total;

	i = 0;
	while (s[i])
	{
		total = (s[i] - 48) + (total * 10);
		i++;
	}
	return (total);
}

void	ft_sendbit(int pid, char *a)
{
	int		i;
	int		j;
	char	print_char;

	j = 0;
	while (a[j])
	{
		i = 7;
		print_char = a[j];
		while (i != -1)
		{
			if ((print_char >> i) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			i--;
			usleep(100);
		}
		j++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		ft_sendbit(ft_atoi(av[1]), av[2]);
	}
	else
		write(1, "ARGUMENT ERROR!", 16);
	return (0);
}
