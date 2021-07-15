#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_printf
{
	int nombretotal;
	va_list	args;
}					t_printf;

int ft_printf(const char *format, ...);
void ft_parse_format(const char *format, t_printf *env);
void ft_putchar (char c, int size, t_printf *env);
void ft_conv (const char c, t_printf *env);
void ft_itoH(unsigned long arg, int base, t_printf *env);
void ft_itoh(unsigned long arg, int base, t_printf *env);
static int ft_size(unsigned int n);
void ft_putnbr(int n, int fd);
void ft_putstr(char *s, int fd);
void ft_itou(unsigned int arg, t_printf *env);
void ft_init_struct(t_printf *env);

#endif
