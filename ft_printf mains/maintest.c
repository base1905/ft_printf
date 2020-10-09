#include <stdio.h>
#include "libftprintf.h"

int main (void)
{
    printf("%% *.5i 42 == |% *.5i|\n", 4, 42);
    ft_printf("%% *.5i 42 == |% *.5i|\n", 4, 42);

int d=0;

printf("|%.d|\n", d);
ft_printf("|%.d|\n", d);

printf("%*.*i\n", 19, 14, -42);
ft_printf("%*.*i\n", 19, 14, -42);

printf("%*.*d\n", 4, 3, -12);
ft_printf("%*.*d\n", 4, 3, -12);

printf("%0*.*i\n", 2, 1, 8);
ft_printf("%0*.*i\n", 2, 1, 8);

char c = 'c';
printf("|%5%c|\n", c);
ft_printf("|%5%c|\n", c);

char s[] = "base";
printf("|%09s|\n", s);
ft_printf("|%09s|\n", s);
printf("|%-09s|\n", s);
ft_printf("|%-09s|\n", s);

printf("|%0*.*x|\n", 18, -15, 152352352);
ft_printf("|%0*.*x|\n", 18, -15, 152352352);

printf("|%c|\n", '\x00');
ft_printf("|%c|\n", '\x00');
}
