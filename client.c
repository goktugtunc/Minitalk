#include "minitalk.h"
#include <stdio.h>

int	ft_atoi(char *a)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (a[i])
	{
		c = (a[i] - 48) + (c * 10);
		i++;
	}
	return (c);
}

//void	send_bites(int pid, char *message)
//{
//	int		i;
//	int		c;
//	char	d;

//	i = 0;
//	c = 7;
//	while (message[i])
//	{
//		d = message[i];
//		while (c != -1)
//		{
//			if ((d << c) & 128)
//			{
//				kill(pid, SIGUSR1);
//				write(1, "1", 1);
//			}
//			else
//			{
//				kill(pid, SIGUSR2);
//				write(1, "0", 1);
//			}
//			c--;
//			usleep(100);
//		}
//		i++;
//	}
//}

void	send_bit(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		usleep(500);
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i])
			send_bit(pid, argv[2][i++]);
	}
	else
	{
		if (argc < 3)
			write(1, "The hungry bear won't play.", 27);
		else
			write(1, "Feed the crow and let it eat.", 29);
	}
}
