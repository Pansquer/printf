#include "ft_printf.h"

int main (void)
{
    int a, b;
    char c = 'A';
    char *str = NULL;
    char *pointer = "5468474";
    unsigned int unsign = 6584351;
    int digit = 654431;
    unsigned int up = 354444;
    unsigned int down = 354444;

    a = ft_printf("voici mon type c : %c\n", c);
    b = printf("voici mon type c : %c\n", c);
    printf("f : %d , v ; %d\n", a, b);

    a = ft_printf("voici mon type s : %s\n", str);
    b = printf("voici mon type s : %s\n", str);
    printf("f : %d , v ; %d\n", a, b);

    a = ft_printf("voici mon type u : %u\n", unsign);
    b = printf("voici mon type u : %u\n", unsign);
    printf("f : %d , v ; %d\n", a, b);

    a = ft_printf("voici mon type d : %d\n", digit);
    b = printf("voici mon type d : %d\n", digit);
    printf("f : %d , v ; %d\n", a, b);

    a = ft_printf("voici mon type p : %p\n", pointer);
    b = printf("voici mon type p : %p\n", pointer);
    printf("f : %d , v ; %d\n", a, b);

    a = ft_printf("voici mon type x : %x\n", down);
    b = printf("voici mon type x : %x\n", down);
    printf("f : %d , v ; %d\n", a, b);

    a = ft_printf("%X\n", up);
    b = printf("%X\n", up);
    printf("f : %d\n , v ; %d\n", a, b);
}

