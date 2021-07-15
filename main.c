#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

int ft_printf(const char *format, ...)
{
	t_printf env;
	
	ft_init_flags(&env);
	va_start(env.args, format);
	ft_parse_format(format, &env);
	va_end(env.args);
	return(env.nombretotal);
}

void ft_init_struct(t_printf *env)
{
	env->nombretotal = 0;
}

void ft_parse_format(const char *format, t_printf *env)
{
	int i;

	i = 0;
	while(format[i])
	{
		if (format[i] == '%')
			i++;
		if (format[i] == 'c' || 's' || 'p' || 'd' || 'i' || 'u' || 'x' || 'X')
			ft_conv(format[i] arg->env);
		else
			ft_putchar(format[i] arg->env);
	}
}

int main(void)
{


