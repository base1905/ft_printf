#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>
#include <float.h>
#include <math.h>

int main()
{
    int d;
    long int ld;

    d = -0;
    ld = -0;
    
    printf("***************************************\n");
	printf ("\t\tINT TEST\n");
	printf("***************************************\n\n");
    
    ft_printf("ft_printf:\t[]\t[%d]\n", d);
	printf("printf:\t\t[]\t[%d]\n", d);
    /*ft_printf("ft_printf:\t[+]\t[%+d]\n", d);
	printf("printf:\t\t[+]\t[%+d]\n", d);
    ft_printf("ft_printf:\t[+]\t[%+d]\n", -d);
	printf("printf:\t\t[+]\t[%+d]\n", -d);*/
    ft_printf("ft_printf:\t[25]\t[%25d]\n", d);
	printf("printf:\t\t[25]\t[%25d]\n", d);
    ft_printf("ft_printf:\t[-25]\t[%-25d]\n", d);
	printf("printf:\t\t[-25]\t[%-25d]\n", d);
    /*ft_printf("ft_printf:\t[+25]\t[%+25d]\n", d);
	printf("printf:\t\t[+25]\t[%+25d]\n", d);
    ft_printf("ft_printf:\t[+-25]\t[%+-25d]\n", d);
	printf("printf:\t\t[+-25]\t[%+-25d]\n", d);
    ft_printf("ft_printf:\t[+025]\t[%+025d]\n", d);
	printf("printf:\t\t[+025]\t[%+025d]\n", d);*/
    ft_printf("ft_printf:\t[025]\t[%025d]\n", -d);
	printf("printf:\t\t[025]\t[%025d]\n", -d);
    ft_printf("ft_printf:\t[025]\t[%025d]\n", d);
	printf("printf:\t\t[025]\t[%025d]\n", d);
    ft_printf("ft_printf:\t[1]\t[%1d]\n", d);
	printf("printf:\t\t[1]\t[%1d]\n", d);
    ft_printf("ft_printf:\t[0]\t[%0d]\n", d);
	printf("printf:\t\t[0]\t[%0d]\n", d);
    ft_printf("ft_printf:\t[-3]\t[%-3d]\n", d);
	printf("printf:\t\t[-3]\t[%-3d]\n", d);
    /*ft_printf("ft_printf:\t[-+3]\t[%-+3d]\n", d);
	printf("printf:\t\t[-+3]\t[%-+3d]\n", d);
    ft_printf("ft_printf:\t[-+4]\t[%-+4d]\n", d);
	printf("printf:\t\t[-+4]\t[%-+4d]\n", d);
    ft_printf("ft_printf:\t[+4]\t[%+4d]\n", d);
	printf("printf:\t\t[+4]\t[%+4d]\n", d);*/
    ft_printf("ft_printf:\t[.42]\t[%.42d]\n", d);
	printf("printf:\t\t[.42]\t[%.42d]\n", d);
    /*ft_printf("ft_printf:\t[+.42]\t[%+.42d]\n", d);
	printf("printf:\t\t[+.42]\t[%+.42d]\n", d);*/
    ft_printf("ft_printf:\t[.1]\t[%.1d]\n", d);
	printf("printf:\t\t[.1]\t[%.1d]\n", d);
    ft_printf("ft_printf:\t[.0]\t[%.0d]\n", d);
	printf("printf:\t\t[.0]\t[%.0d]\n", d);
    ft_printf("ft_printf:\t[.]\t[%.d]\n", d);
	printf("printf:\t\t[.]\t[%.d]\n", d);
    ft_printf("ft_printf:\t[0.0]\t[%0.0d]\n", d);
	printf("printf:\t\t[0.0]\t[%0.0d]\n", d);
 //    ft_printf("ft_printf:\t[ ]\t[% d]\n", d);
	// printf("printf:\t\t[ ]\t[% d]\n", d);
 //    ft_printf("ft_printf:\t[ 2]\t[% 2d]\n", d);
	// printf("printf:\t\t[ 2]\t[% 2d]\n", d);
 //    ft_printf("ft_printf:\t[ 4]\t[% 4d]\n", d);
	// printf("printf:\t\t[ 4]\t[% 4d]\n", d);
 //    ft_printf("ft_printf:\t[ -4]\t[% -4d]\n", d);
	// printf("printf:\t\t[ -4]\t[% -4d]\n", d);
 //    ft_printf("ft_printf:\t[-4]\t[%-4d]\n", d);
	// printf("printf:\t\t[-4]\t[%-4d]\n", d);
 //    ft_printf("ft_printf:\t[ -4]\t[% -4d]\n", -d);
	// printf("printf:\t\t[ -4]\t[% -4d]\n", -d);
 //    ft_printf("ft_printf:\t[ -]\t[% -d]\n", -d);
	// printf("printf:\t\t[ -]\t[% -d]\n", -d);
 //    ft_printf("ft_printf:\t[ -25.5]\t[% -25.5d]\n", -d);
	// printf("printf:\t\t[ -25.5]\t[% -25.5d]\n", -d);
 //    ft_printf("ft_printf:\t[ -25.30]\t[% -25.30d]\n", -d);
	// printf("printf:\t\t[ -25.30]\t[% -25.30d]\n", -d);
    /*ft_printf("ft_printf:\t[-+25.30]\t[%-+25.30d]\n", -d);
	printf("printf:\t\t[-+25.30]\t[%-+25.30d]\n\n", -d);*/

     ft_printf("ft_printf:\t[]\t[%ld]\n", ld);
	printf("printf:\t\t[]\t[%ld]\n", ld);
    /*ft_printf("ft_printf:\t[+]\t[%+ld]\n", ld);
	printf("printf:\t\t[+]\t[%+ld]\n", ld);
    ft_printf("ft_printf:\t[+]\t[%+ld]\n", -ld);
	printf("printf:\t\t[+]\t[%+ld]\n", -ld);*/
    ft_printf("ft_printf:\t[25]\t[%25ld]\n", ld);
	printf("printf:\t\t[25]\t[%25ld]\n", ld);
    ft_printf("ft_printf:\t[-25]\t[%-25ld]\n", ld);
	printf("printf:\t\t[-25]\t[%-25ld]\n", ld);
    /*ft_printf("ft_printf:\t[+25]\t[%+25ld]\n", ld);
	printf("printf:\t\t[+25]\t[%+25ld]\n", ld);
    ft_printf("ft_printf:\t[+-25]\t[%+-25ld]\n", ld);
	printf("printf:\t\t[+-25]\t[%+-25ld]\n", ld);
    ft_printf("ft_printf:\t[+025]\t[%+025ld]\n", ld);
	printf("printf:\t\t[+025]\t[%+025ld]\n", ld);*/
    ft_printf("ft_printf:\t[025]\t[%025ld]\n", -ld);
	printf("printf:\t\t[025]\t[%025ld]\n", -ld);
    ft_printf("ft_printf:\t[025]\t[%025ld]\n", ld);
	printf("printf:\t\t[025]\t[%025ld]\n", ld);
    ft_printf("ft_printf:\t[1]\t[%1ld]\n", ld);
	printf("printf:\t\t[1]\t[%1ld]\n", ld);
    ft_printf("ft_printf:\t[0]\t[%0ld]\n", ld);
	printf("printf:\t\t[0]\t[%0ld]\n", ld);
    ft_printf("ft_printf:\t[-3]\t[%-3ld]\n", ld);
	printf("printf:\t\t[-3]\t[%-3ld]\n", ld);
    /*ft_printf("ft_printf:\t[-+3]\t[%-+3ld]\n", ld);
	printf("printf:\t\t[-+3]\t[%-+3ld]\n", ld);
    ft_printf("ft_printf:\t[-+4]\t[%-+4ld]\n", ld);
	printf("printf:\t\t[-+4]\t[%-+4ld]\n", ld);
    ft_printf("ft_printf:\t[+4]\t[%+4ld]\n", ld);
	printf("printf:\t\t[+4]\t[%+4ld]\n", ld);*/
    ft_printf("ft_printf:\t[.42]\t[%.42ld]\n", ld);
	printf("printf:\t\t[.42]\t[%.42ld]\n", ld);
    /*ft_printf("ft_printf:\t[+.42]\t[%+.42ld]\n", ld);
	printf("printf:\t\t[+.42]\t[%+.42ld]\n", ld);*/
    ft_printf("ft_printf:\t[.1]\t[%.1ld]\n", ld);
	printf("printf:\t\t[.1]\t[%.1ld]\n", ld);
    ft_printf("ft_printf:\t[.0]\t[%.0ld]\n", ld);
	printf("printf:\t\t[.0]\t[%.0ld]\n", ld);
    ft_printf("ft_printf:\t[.]\t[%.ld]\n", ld);
	printf("printf:\t\t[.]\t[%.ld]\n", ld);
    ft_printf("ft_printf:\t[0.0]\t[%0.0ld]\n", ld);
	printf("printf:\t\t[0.0]\t[%0.0ld]\n", ld);
 //    ft_printf("ft_printf:\t[ ]\t[% ld]\n", ld);
	// printf("printf:\t\t[ ]\t[% ld]\n", ld);
 //    ft_printf("ft_printf:\t[ 2]\t[% 2ld]\n", ld);
	// printf("printf:\t\t[ 2]\t[% 2ld]\n", ld);
 //    ft_printf("ft_printf:\t[ 4]\t[% 4ld]\n", ld);
	// printf("printf:\t\t[ 4]\t[% 4ld]\n", ld);
 //    ft_printf("ft_printf:\t[ -4]\t[% -4ld]\n", ld);
	// printf("printf:\t\t[ -4]\t[% -4ld]\n", ld);
 //    ft_printf("ft_printf:\t[-4]\t[%-4ld]\n", ld);
	// printf("printf:\t\t[-4]\t[%-4ld]\n", ld);
 //    ft_printf("ft_printf:\t[ -4]\t[% -4ld]\n", -ld);
	// printf("printf:\t\t[ -4]\t[% -4ld]\n", -ld);
 //    ft_printf("ft_printf:\t[ -]\t[% -ld]\n", -ld);
	// printf("printf:\t\t[ -]\t[% -ld]\n", -ld);
 //    ft_printf("ft_printf:\t[ -25.5]\t[% -25.5ld]\n", -ld);
	// printf("printf:\t\t[ -25.5]\t[% -25.5ld]\n", -ld);
 //    ft_printf("ft_printf:\t[ -25.30]\t[% -25.30ld]\n", -ld);
	// printf("printf:\t\t[ -25.30]\t[% -25.30ld]\n", -ld);
    /*ft_printf("ft_printf:\t[-+25.30]\t[%-+25.30ld]\n", -ld);
	printf("printf:\t\t[-+25.30]\t[%-+25.30ld]\n\n", -ld);*/

    d = 246567;
    ft_printf("ft_printf:\t[]\t[%d]\n", d);
	printf("printf:\t\t[]\t[%d]\n", d);
    /*ft_printf("ft_printf:\t[+]\t[%+d]\n", d);
	printf("printf:\t\t[+]\t[%+d]\n", d);
    ft_printf("ft_printf:\t[+]\t[%+d]\n", -d);
	printf("printf:\t\t[+]\t[%+d]\n", -d);*/
    ft_printf("ft_printf:\t[25]\t[%25d]\n", d);
	printf("printf:\t\t[25]\t[%25d]\n", d);
    ft_printf("ft_printf:\t[-25]\t[%-25d]\n", d);
	printf("printf:\t\t[-25]\t[%-25d]\n", d);
    /*ft_printf("ft_printf:\t[+25]\t[%+25d]\n", d);
	printf("printf:\t\t[+25]\t[%+25d]\n", d);
    ft_printf("ft_printf:\t[+-25]\t[%+-25d]\n", d);
	printf("printf:\t\t[+-25]\t[%+-25d]\n", d);
    ft_printf("ft_printf:\t[+025]\t[%+025d]\n", d);
	printf("printf:\t\t[+025]\t[%+025d]\n", d);*/
    ft_printf("ft_printf:\t[025]\t[%025d]\n", -d);
	printf("printf:\t\t[025]\t[%025d]\n", -d);
    ft_printf("ft_printf:\t[025]\t[%025d]\n", d);
	printf("printf:\t\t[025]\t[%025d]\n", d);
    ft_printf("ft_printf:\t[1]\t[%1d]\n", d);
	printf("printf:\t\t[1]\t[%1d]\n", d);
    ft_printf("ft_printf:\t[0]\t[%0d]\n", d);
	printf("printf:\t\t[0]\t[%0d]\n", d);
    ft_printf("ft_printf:\t[-3]\t[%-3d]\n", d);
	printf("printf:\t\t[-3]\t[%-3d]\n", d);
    /*ft_printf("ft_printf:\t[-+3]\t[%-+3d]\n", d);
	printf("printf:\t\t[-+3]\t[%-+3d]\n", d);
    ft_printf("ft_printf:\t[-+4]\t[%-+4d]\n", d);
	printf("printf:\t\t[-+4]\t[%-+4d]\n", d);
    ft_printf("ft_printf:\t[+4]\t[%+4d]\n", d);
	printf("printf:\t\t[+4]\t[%+4d]\n", d);*/
    ft_printf("ft_printf:\t[.42]\t[%.42d]\n", d);
	printf("printf:\t\t[.42]\t[%.42d]\n", d);
    /*ft_printf("ft_printf:\t[+.42]\t[%+.42d]\n", d);
	printf("printf:\t\t[+.42]\t[%+.42d]\n", d);*/
    ft_printf("ft_printf:\t[.1]\t[%.1d]\n", d);
	printf("printf:\t\t[.1]\t[%.1d]\n", d);
    ft_printf("ft_printf:\t[.0]\t[%.0d]\n", d);
	printf("printf:\t\t[.0]\t[%.0d]\n", d);
    ft_printf("ft_printf:\t[.]\t[%.d]\n", d);
	printf("printf:\t\t[.]\t[%.d]\n", d);
    ft_printf("ft_printf:\t[0.0]\t[%0.0d]\n", d);
	printf("printf:\t\t[0.0]\t[%0.0d]\n", d);
 //    ft_printf("ft_printf:\t[ ]\t[% d]\n", d);
	// printf("printf:\t\t[ ]\t[% d]\n", d);
 //    ft_printf("ft_printf:\t[ 2]\t[% 2d]\n", d);
	// printf("printf:\t\t[ 2]\t[% 2d]\n", d);
 //    ft_printf("ft_printf:\t[ 4]\t[% 4d]\n", d);
	// printf("printf:\t\t[ 4]\t[% 4d]\n", d);
 //    ft_printf("ft_printf:\t[ -4]\t[% -4d]\n", d);
	// printf("printf:\t\t[ -4]\t[% -4d]\n", d);
 //    ft_printf("ft_printf:\t[-4]\t[%-4d]\n", d);
	// printf("printf:\t\t[-4]\t[%-4d]\n", d);
 //    ft_printf("ft_printf:\t[ -4]\t[% -4d]\n", -d);
	// printf("printf:\t\t[ -4]\t[% -4d]\n", -d);
 //    ft_printf("ft_printf:\t[ -]\t[% -d]\n", -d);
	// printf("printf:\t\t[ -]\t[% -d]\n", -d);
 //    ft_printf("ft_printf:\t[ -25.5]\t[% -25.5d]\n", -d);
	// printf("printf:\t\t[ -25.5]\t[% -25.5d]\n", -d);
 //    ft_printf("ft_printf:\t[ -25.30]\t[% -25.30d]\n", -d);
	// printf("printf:\t\t[ -25.30]\t[% -25.30d]\n", -d);
    /*ft_printf("ft_printf:\t[-+25.30]\t[%-+25.30d]\n", -d);
	printf("printf:\t\t[-+25.30]\t[%-+25.30d]\n\n", -d);*/


    return (0);
}
