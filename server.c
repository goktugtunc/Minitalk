#include "minitalk.h"
#include <stdio.h>

void	ft_putnbr(int c)
{
	if (c < 0)
		write(1, "-", 1);
	if (c > 9)
		ft_putnbr(c / 10);
	write(1, &"0123456789"[c % 10], 1);
}

void	ft_putstr(char *title)
{
	int	i;

	i = 0;
	while (title[i])
	{
		write(1, &title[i], 1);
		i++;
	}
}

void	handler(int sig)
{
	static int	bite = 7;
	static char	c = 0;

	if (sig == SIGUSR1)
		c = (c << 1) | 1;
	else
		c = (c << 1) | 0;
	if (bite == 0)         
		write(1, &c, 1);
	bite--;
	if (bite == -1)
	{
		bite = 7;
		c = 0;
	}
}

int	main(void)
{
	ft_putstr("Server Started!\nPID ->");
	ft_putnbr(getpid());
	ft_putstr("\n");
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
	return (0);
}
