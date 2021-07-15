#include "ft_printf.h"
#include <stdio.h>

static int	ft_size(unsigned int n)
{
	int	size;

	size = 1;
	while (n > 9)
	{
		n = n / 16;
		size++;
	}
	return (size);
}

void ft_putchar(char c, int size, t_printf *env)
{
	write (1, &c, size);
	env->nombretotal += 1;
}

void	ft_putstr(char *s, int fd)
{
	int		i;

	i = 0;
	if (s)
		while (s[i])
			write(fd, &s[i++], 1);
}

void	ft_putnbr(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr("-2147483648", fd);
	else
	{
		if (n < 0)
		{
			ft_putchar('-', fd);
			n = n * -1;
		}
		if (n > 9)
		{
			ft_putnbr(n / 10, fd);
		}
		ft_putchar((n % 10) + '0', fd);
	}
}
