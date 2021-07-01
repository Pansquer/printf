#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_printf
{
	int zero;
	int minus;
	int width;
	int precision;
	int bufferpos;
	int nombretotal;
	va_list	args;
}					t_printf;

int ft_printf(const char *format, ...);
int ft_parse_flags (const char *format, t_printf *env);
void ft_parse_format(const char *format, t_printf *env);
void ft_putchar (char c, int size);
int ft_is_type(const char str);
int ft_is_flags(const char c, t_printf *env);
int ft_is_digit_width(const char c, t_printf *env);
void ft_reset_flags(t_printf *env);
void ft_conv (const char c, t_printf *env);
int ft_is_digit_preci(const char c, t_printf *env);

#endif