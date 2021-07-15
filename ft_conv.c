#include "ft_printf.h"
#include <stdio.h>

char	ft_itoh(unsigned long arg, int base, t_printf *env)
{
	char			str[20];
	int				size;
	unsigned int	nb;

	size = 19;
	str[size--] = '\0';
	if (arg == 0)
		str[size--] = '0';
	while (arg)
	{
		nb = arg % base;
		if (size > 9)
			str[size--] = nb + 'a' - 10;
		else
			str[size--] = nb + '0';
		arg /= base;
	}
	ft_putstr(str + size + 1, env);
}

void	ft_itoH(unsigned long arg, int base, t_printf *env)
{
	char			str[20];
	int				size;
	int				nb;

	size = 19;
	str[size--] = '\0';
	if (arg == 0)
		str[size--] = '0';
	while (arg)
	{
		nb = arg % base;
		if (nb > 9)
			str[size--] = nb + 'A' - 10;
		else
			str[size--] = nb + '0';
		arg /= base;
	}
	ft_putstr(str + size + 1, env);
}

void	ft_itou(unsigned int arg, t_printf *env)
{
	char					str[20];
	size_t					size;
	unsigned long			i;

	size = 19;
	arg = (unsigned int)(4294967295 + 1 + arg);
	str[size--] = '\0';
	if (arg == 0)
		str[size--] = '0';
	while (arg)
		{
			str[i--] = arg / 10;
			str[i--] = arg % 10;
		}
	ft_putnbr(str[i]);
}

void ft_conv(const char c, t_printf *env)
{
	if (c == 'c')
		ft_putchar(va_arg(env->args, int), 1, env);
	else if (c == 's')
		ft_putstr(va_arg(env->args, char *), 10, env);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(env->args, int), env);
	else if (c == 'x' || c == 'p')
		ft_itoh(va_arg(env->args, unsigned long int), 16, env);
	else if (c == 'u')
		ft_itou(va_arg(env->args, unsigned int), 10, env);
	else if (c == 'X')
		ft_itoH(va_arg(env->args, unsigned long int), 16, env);
}
