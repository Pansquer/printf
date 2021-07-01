#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	t_printf env;
	
	ft_reset_flags(&env);
	va_start(env.args, format);
	ft_parse_format(format, &env);
	va_end(env.args);
	return(env.nombretotal);
}
void ft_putchar (char c, int size)
{
	write (1, &c, size);
}

void ft_parse_format(const char *format, t_printf *env)
{
	int i;

	i = 0;

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
				ft_putchar('%', 1);
			else
			{
				env->bufferpos = i;
				i = ft_parse_flags(format, env);
			}

		}
		else 
			ft_putchar(format[i], 1);
		i++;
	}
	env->nombretotal += i;
}

int ft_parse_flags (const char *format, t_printf *env)
{
	int i;

	i = env->bufferpos;
	while (ft_is_type(format[i])  != 1)
	{
		while (ft_is_flags(format[i], env) == 1)
			i++;
		while (ft_is_digit_width(format[i], env) == 1)
		{
			env->width = env->width * 10 + format[i] - '0';
			i++;
			printf("tiens ta largueur : %d\n", env->width);
		}
		if (format[i] == '.')
		{
			i++;
			while (ft_is_digit_preci(format[i], env) == 1)
			{
				env->precision = env->precision * 10 + format[i] - '0';
				i++;
			}
			printf("tiens ta precision : %d\n", env->precision);
		}	
	}
	
	ft_conv (format[i], env);
	i++;
	ft_reset_flags(env);
	return (i);
}

int ft_is_type(const char str)
{
	if ((str == 'd') || (str == 'c') || (str == 'x') || (str == 'X') || (str == 'p') || (str == 'u') ||(str == 'i') ||(str == 'u'))
		return 1;
	return 0;
}

int ft_is_flags(const char c, t_printf *env)
{
	if (c == '-')
	{
		env->minus = 1;
		printf("j'ai trouver un - \n");
		return 1;
	}
	else if (c == '0')
	{
		env->zero = 1;
		printf("j'ai trouver un 0 \n");
		return 1;
	}
	else 
		return 0;

}

int ft_is_digit_width(const char c, t_printf *env)
{
	if (c >= '0' &&  c <= '9')
		return 1;
	else if (c == '-')
	{
		env->minus = 1;
		printf ("j'ai trouver un - \n");
		return 1;
	}
	else
		return 0;
}

int ft_is_digit_preci(const char c, t_printf *env)
{
	if (c >= '0' &&  c <= '9')
		return 1;
	else if (c == '-')
	{
		env->minus = 1;
		printf("j'ai trouver un - \n");
		return 1;
	}
	else
		return 0;
}

void ft_conv (const char c, t_printf *env)
{
	if (c == 'c')
		printf("tas un type c \n");
	else if (c == 'd')
		printf("t'as un type d \n");
	else 
		printf("tes une merde \n");
}

void ft_reset_flags(t_printf *env)
{
	env->minus = 0;
	env->width = 0;
	env->precision = 0;
	env->zero = 0;
}

int main (void)
{
	ft_printf(" test une largueur %-0-10d\n test precision  %010.-5d\n test dazdadada");
	return 0;
}