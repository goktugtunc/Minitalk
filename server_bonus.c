/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 11:33:14 by gotunc            #+#    #+#             */
/*   Updated: 2023/08/19 11:33:16 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_putnbr(int a)
{
	if (a > 9)
		ft_putnbr(a / 10);
	write(1, &"0123456789"[a % 10], 1);
}

void	print_bit(int sig)
{
	static char	a = 0;
	static int	i = 0;

	if (sig == SIGUSR1)
		a = ((a << 1) | 1);
	else
		a = ((a << 1) | 0);
	if (i == 31)
		write(1, &a, 1);
	i++;
	if (i == 32)
		i = 0;
}

int	main(void)
{
	write(1, "GETPID ID : ", 12);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	signal(SIGUSR1, print_bit);
	signal(SIGUSR2, print_bit);
	while (1)
		continue ;
	return (0);
}
