#include <stdio.h>
#include "libftprintf.h"

int main (void)
{
    char a = 'b';
	char s[] = "base";

    ft_printf (" 10c =%10c", a);
    ft_printf("\n");
    ft_printf ("-10c =%-10c", a);
    ft_printf("\n");

    
    ft_printf (" 10s =%10s", s);
    ft_printf("\n");
    ft_printf ("-10s =%-10s", s);
    ft_printf("\n");

	ft_printf (" 010s=%010s", s);
    ft_printf("\n");
    ft_printf ("-010s=%-010s", s);
    ft_printf("\n");

	ft_printf ("  *  =%*s", 10, s);
    ft_printf("\n");
    ft_printf (" -*  =%*s", -10, s);
    ft_printf("\n");

	ft_printf("hello, %s.", "gavin");
}
