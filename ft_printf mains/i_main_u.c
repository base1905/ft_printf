#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "libftprintf.h"


void error(int c1, int c2)
{
	if (c1 != c2)
		printf("__________________!!!!!!!!!!!!!!ERROR!!!!!!!!!!!!!!!!____________________\nprintf_%d | ft_printf_%d\n\n\n\n", c1, c2);
}

int main ()
{
	int c1;
	int c2;

	printf("\n\n\n__________________________________________________________________________________\n");
	printf("\nTEST_UNSIGNEu_NUMBERS\n\n");

	printf("Test min max\n");
	c1 = printf("|%%u|%%15u|%%-15u|%%015u|                    |%u|%15u|%-15u|%015u|\n", 4294967295, 4294967295, 4294967295, 4294967295);
	c2 = ft_printf("|%%u|%%15u|%%-15u|%%015u|                   *|%u|%15u|%-15u|%015u|\n", 4294967295, 4294967295, 4294967295, 4294967295);
	error(c1, c2);
	c1 = printf("|%%u|%%15u|%%-15u|%%015u|                    |%u|%15u|%-15u|%015u|\n", -4294967295, -4294967295, -4294967295, -4294967295);
	c2 = ft_printf("|%%u|%%15u|%%-15u|%%015u|                   *|%u|%15u|%-15u|%015u|\n", -4294967295, -4294967295, -4294967295, -4294967295);
	error(c1, c2);
	printf("\n");

	printf("Test larger min max\n");
	c1 = printf("|%%u|%%15u|%%-15u|%%015u|                    |%u|%15u|%-15u|%015u|\n", 2147483648, 2147483648, 2147483648, 2147483648);
	c2 = ft_printf("|%%u|%%15u|%%-15u|%%015u|                   *|%u|%15u|%-15u|%015u|\n", 2147483648, 2147483648, 2147483648, 2147483648);
	error(c1, c2);
	c1 = printf("|%%u|%%15u|%%-15u|%%015u|                    |%u|%15u|%-15u|%015u|\n", -2147483649, -2147483649, -2147483649, -2147483649);
	c2 = ft_printf("|%%u|%%15u|%%-15u|%%015u|                   *|%u|%15u|%-15u|%015u|\n", -2147483649, -2147483649, -2147483649, -2147483649);
	error(c1, c2);
	c1 = printf("|%%u|%%15u|%%-15u|%%015u|                    |%u|%15u|%-15u|%015u|\n", 2147483650, 2147483650, 2147483650, 2147483650);
	c2 = ft_printf("|%%u|%%15u|%%-15u|%%015u|                   *|%u|%15u|%-15u|%015u|\n", 2147483650, 2147483650, 2147483650, 2147483650);
	error(c1, c2);
	c1 = printf("|%%u|%%15u|%%-15u|%%015u|                    |%u|%15u|%-15u|%015u|\n", 4294967296, 4294967296, 4294967296, 4294967296);
	c2 = ft_printf("|%%u|%%15u|%%-15u|%%015u|                   *|%u|%15u|%-15u|%015u|\n", 4294967296, 4294967296, 4294967296, 4294967296);
	error(c1, c2);
	c1 = printf("|%%u|%%15u|%%-15u|%%015u|                    |%u|%15u|%-15u|%015u|\n", 4294967297, 4294967297, 4294967297, 4294967297);
	c2 = ft_printf("|%%u|%%15u|%%-15u|%%015u|                   *|%u|%15u|%-15u|%015u|\n", 4294967297, 4294967297, 4294967297, 4294967297);
	error(c1, c2);
	c1 = printf("|%%u|%%15u|%%-15u|%%015u|                    |%u|%15u|%-15u|%015u|\n", 140737488355327, 140737488355327, 140737488355327, 140737488355327);
	c2 = ft_printf("|%%u|%%15u|%%-15u|%%015u|                   *|%u|%15u|%-15u|%015u|\n", 140737488355327, 140737488355327, 140737488355327, 140737488355327);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%u_%%0u_%%3u_%%5u_%%10u|                    |%u|%0u|%3u|%5u|%10u|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%u_%%0u_%%3u_%%5u_%%10u|                   *|%u|%0u|%3u|%5u|%10u|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%u_%%0u_%%3u_%%5u_%%10u|                    |%u|%0u|%3u|%5u|%10u|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%u_%%0u_%%3u_%%5u_%%10u|                   *|%u|%0u|%3u|%5u|%10u|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%u_%%0u_%%3u_%%5u_%%10u|                    |%u|%0u|%3u|%5u|%10u|\n", -234u, -234u, -234u, -234u, -234u);
	c2 = ft_printf("%%u_%%0u_%%3u_%%5u_%%10u|                   *|%u|%0u|%3u|%5u|%10u|\n", -234u, -234u, -234u, -234u, -234u);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%-u_%%-0u_%%-3u_%%-5u_%%-10u|               |%-u|%-0u|%-3u|%-5u|%-10u|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%-u_%%-0u_%%-3u_%%-5u_%%-10u|              *|%-u|%-0u|%-3u|%-5u|%-10u|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%-u_%%-0u_%%-3u_%%-5u_%%-10u|               |%-u|%-0u|%-3u|%-5u|%-10u|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%-u_%%-0u_%%-3u_%%-5u_%%-10u|              *|%-u|%-0u|%-3u|%-5u|%-10u|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%-u_%%-0u_%%-3u_%%-5u_%%-10u|               |%-u|%-0u|%-3u|%-5u|%-10u|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%-u_%%-0u_%%-3u_%%-5u_%%-10u|              *|%-u|%-0u|%-3u|%-5u|%-10u|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%2u_%%3u_%%5u_%%7u_%%10u|              |%2u|%3u|%5u|%7u|%10u|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%2u_%%3u_%%5u_%%7u_%%10u|             *|%2u|%3u|%5u|%7u|%10u|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%2u_%%3u_%%5u_%%7u_%%10u|              |%2u|%3u|%5u|%7u|%10u|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%2u_%%3u_%%5u_%%7u_%%10u|             *|%2u|%3u|%5u|%7u|%10u|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%2u_%%3u_%%5u_%%7u_%%10u|              |%2u|%3u|%5u|%7u|%10u|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%2u_%%3u_%%5u_%%7u_%%10u|             *|%2u|%3u|%5u|%7u|%10u|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%02u_%%03u_%%05u_%%07u_%%010u|              |%02u|%03u|%05u|%07u|%010u|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%02u_%%03u_%%05u_%%07u_%%010u|             *|%02u|%03u|%05u|%07u|%010u|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%02u_%%03u_%%05u_%%07u_%%010u|              |%02u|%03u|%05u|%07u|%010u|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%02u_%%03u_%%05u_%%07u_%%010u|             *|%02u|%03u|%05u|%07u|%010u|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%02u_%%03u_%%05u_%%07u_%%010u|              |%02u|%03u|%05u|%07u|%010u|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%02u_%%03u_%%05u_%%07u_%%010u|             *|%02u|%03u|%05u|%07u|%010u|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%.0u_%%0.0u_%%3.0u_%%5.0u_%%10.0u|          |%.0u|%0.0u|%3.0u|%5.0u|%10.0u|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%.0u_%%0.0u_%%3.0u_%%5.0u_%%10.0u|         *|%.0u|%0.0u|%3.0u|%5.0u|%10.0u|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%.0u_%%0.0u_%%3.0u_%%5.0u_%%10.0u|          |%.0u|%0.0u|%3.0u|%5.0u|%10.0u|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%.0u_%%0.0u_%%3.0u_%%5.0u_%%10.0u|         *|%.0u|%0.0u|%3.0u|%5.0u|%10.0u|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%u.0_%%0.0u_%%3.0u_%%5.0u_%%10.0u|          |%.0u|%0.0u|%3.0u|%5.0u|%10.0u|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%u.0_%%0.0u_%%3.0u_%%5.0u_%%10.0u|         *|%.0u|%0.0u|%3.0u|%5.0u|%10.0u|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%-.0u_%%-0.0u_%%-3.0u_%%-5.0u_%%-10.0u|     |%-.0u|%-0.0u|%-3.0u|%-5.0u|%-10.0u|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%-.0u_%%-0.0u_%%-3.0u_%%-5.0u_%%-10.0u|    *|%-.0u|%-0.0u|%-3.0u|%-5.0u|%-10.0u|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%-.0u_%%-0.0u_%%-3.0u_%%-5.0u_%%-10.0u|     |%-.0u|%-0.0u|%-3.0u|%-5.0u|%-10.0u|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%-.0u_%%-0.0u_%%-3.0u_%%-5.0u_%%-10.0u|    *|%-.0u|%-0.0u|%-3.0u|%-5.0u|%-10.0u|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%-.0u_%%-0.0u_%%-3.0u_%%-5.0u_%%-10.0u|     |%-.0u|%-0.0u|%-3.0u|%-5.0u|%-10.0u|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%-.0u_%%-0.0u_%%-3.0u_%%-5.0u_%%-10.0u|    *|%-.0u|%-0.0u|%-3.0u|%-5.0u|%-10.0u|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%02.0u_%%03.0u_%%05.0u_%%07.0u_%%010.0u|    |%02.0u|%03.0u|%05.0u|%07.0u|%010.0u|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%02.0u_%%03.0u_%%05.0u_%%07.0u_%%010.0u|   *|%02.0u|%03.0u|%05.0u|%07.0u|%010.0u|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%02.0u_%%03.0u_%%05.0u_%%07.0u_%%010.0u|    |%02.0u|%03.0u|%05.0u|%07.0u|%010.0u|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%02.0u_%%03.0u_%%05.0u_%%07.0u_%%010.0u|   *|%02.0u|%03.0u|%05.0u|%07.0u|%010.0u|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%02.0u_%%03.0u_%%05.0u_%%07.0u_%%010.0u|    |%02.0u|%03.0u|%05.0u|%07.0u|%010.0u|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%02.0u_%%03.0u_%%05.0u_%%07.0u_%%010.0u|   *|%02.0u|%03.0u|%05.0u|%07.0u|%010.0u|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%.3u_%%0.3u_%%3.3u_%%5.3u_%%10.3u|          |%.3u|%0.3u|%3.3u|%5.3u|%10.3u|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%.3u_%%0.3u_%%3.3u_%%5.3u_%%10.3u|         *|%.3u|%0.3u|%3.3u|%5.3u|%10.3u|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%.3u_%%0.3u_%%3.3u_%%5.3u_%%10.3u|          |%.3u|%0.3u|%3.3u|%5.3u|%10.3u|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%.3u_%%0.3u_%%3.3u_%%5.3u_%%10.3u|         *|%.3u|%0.3u|%3.3u|%5.3u|%10.3u|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%.3u_%%0.3u_%%3.3u_%%5.3u_%%10.4u|          |%.3u|%0.3u|%3.3u|%5.3u|%10.4u|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%.3u_%%0.3u_%%3.3u_%%5.3u_%%10.4u|         *|%.3u|%0.3u|%3.3u|%5.3u|%10.4u|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%-.2u_%%-0.2u_%%-3.2u_%%-5.2u_%%-10.2u|     |%-.2u|%-0.2u|%-3.2u|%-5.2u|%-10.2u|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%-.2u_%%-0.2u_%%-3.2u_%%-5.2u_%%-10.2u|    *|%-.2u|%-0.2u|%-3.2u|%-5.2u|%-10.2u|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%-.2u_%%-0.2u_%%-3.2u_%%-5.2u_%%-10.2u|     |%-.2u|%-0.2u|%-3.2u|%-5.2u|%-10.2u|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%-.2u_%%-0.2u_%%-3.2u_%%-5.2u_%%-10.2u|    *|%-.2u|%-0.2u|%-3.2u|%-5.2u|%-10.2u|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%-.2u_%%-0.2u_%%-3.2u_%%-5.2u_%%-10.2u|     |%-.2u|%-0.2u|%-3.2u|%-5.2u|%-10.2u|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%-.2u_%%-0.2u_%%-3.2u_%%-5.2u_%%-10.2u|    *|%-.2u|%-0.2u|%-3.2u|%-5.2u|%-10.2u|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%02.2u_%%03.2u_%%05.2u_%%07.2u_%%010.2u|    |%02.2u|%03.2u|%05.2u|%07.2u|%010.2u|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%02.2u_%%03.2u_%%05.2u_%%07.2u_%%010.2u|   *|%02.2u|%03.2u|%05.2u|%07.2u|%010.2u|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%02.2u_%%03.2u_%%05.2u_%%07.2u_%%010.2u|    |%02.2u|%03.2u|%05.2u|%07.2u|%010.2u|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%02.2u_%%03.2u_%%05.2u_%%07.2u_%%010.2u|   *|%02.2u|%03.2u|%05.2u|%07.2u|%010.2u|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%02.2u_%%03.2u_%%05.2u_%%07.2u_%%010.2u|    |%02.2u|%03.2u|%05.2u|%07.2u|%010.2u|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%02.2u_%%03.2u_%%05.2u_%%07.2u_%%010.2u|   *|%02.2u|%03.2u|%05.2u|%07.2u|%010.2u|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%.5u_%%0.5u_%%3.5u_%%5.5u_%%10.5u|          |%.5u|%0.5u|%3.5u|%5.5u|%10.5u|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%.5u_%%0.5u_%%3.5u_%%5.5u_%%10.5u|         *|%.5u|%0.5u|%3.5u|%5.5u|%10.5u|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%.5u_%%0.5u_%%3.5u_%%5.5u_%%10.5u|          |%.5u|%0.5u|%3.5u|%5.5u|%10.5u|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%.5u_%%0.5u_%%3.5u_%%5.5u_%%10.5u|         *|%.5u|%0.5u|%3.5u|%5.5u|%10.5u|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%.5u_%%0.5u_%%3.5u_%%5.5u_%%6.5u|           |%.5u|%0.5u|%3.5u|%5.5u|%6.5u|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%.5u_%%0.5u_%%3.5u_%%5.5u_%%6.5u|          *|%.5u|%0.5u|%3.5u|%5.5u|%6.5u|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%-.5u_%%-0.5u_%%-3.5u_%%-5.5u_%%-10.5u|     |%-.5u|%-0.5u|%-3.5u|%-5.5u|%-10.5u|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%-.5u_%%-0.5u_%%-3.5u_%%-5.5u_%%-10.5u|    *|%-.5u|%-0.5u|%-3.5u|%-5.5u|%-10.5u|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%-.5u_%%-0.5u_%%-3.5u_%%-5.5u_%%-10.5u|     |%-.5u|%-0.5u|%-3.5u|%-5.5u|%-10.5u|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%-.5u_%%-0.5u_%%-3.5u_%%-5.5u_%%-10.5u|    *|%-.5u|%-0.5u|%-3.5u|%-5.5u|%-10.5u|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%-.5u_%%-0.5u_%%-3.5u_%%-5.5u_%%-10.5u|     |%-.5u|%-0.5u|%-3.5u|%-5.5u|%-10.5u|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%-.5u_%%-0.5u_%%-3.5u_%%-5.5u_%%-10.5u|    *|%-.5u|%-0.5u|%-3.5u|%-5.5u|%-10.5u|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%02.5u_%%03.5u_%%05.5u_%%07.5u_%%010.5u|    |%02.5u|%03.5u|%05.5u|%07.5u|%010.5u|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%02.5u_%%03.5u_%%05.5u_%%07.5u_%%010.5u|   *|%02.5u|%03.5u|%05.5u|%07.5u|%010.5u|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%02.5u_%%03.5u_%%05.5u_%%07.5u_%%010.5u|    |%02.5u|%03.5u|%05.5u|%07.5u|%010.5u|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%02.5u_%%03.5u_%%05.5u_%%07.5u_%%010.5u|   *|%02.5u|%03.5u|%05.5u|%07.5u|%010.5u|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%02.5u_%%03.5u_%%05.5u_%%07.5u_%%010.5u|    |%02.5u|%03.5u|%05.5u|%07.5u|%010.5u|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%02.5u_%%03.5u_%%05.5u_%%07.5u_%%010.5u|   *|%02.5u|%03.5u|%05.5u|%07.5u|%010.5u|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	printf("\n\n-------------------------------\n|  Undefined behavior tests:  |\n-------------------------------\n\n");

	c1 = printf("%%0-8.3u|%%0-8.5u|%%10|                         |%0-8.3u|%0-8.5u|%10|\n", -8473);
	c2 = ft_printf("%%0-8.3u|%%0-8.5u|%%10|                        *|%0-8.3u|%0-8.5u|%10|\n", -8473);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%2-2.5u_%%2-3.5u_%%2-5.5u_%%2-7.5u_%%2-10.5u|    |%2-2.5u|%2-3.5u|%2-5.5u|%2-7.5u|%2-10.5u|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%2-2.5u_%%2-3.5u_%%2-5.5u_%%2-7.5u_%%2-10.5u|   *|%2-2.5u|%2-3.5u|%2-5.5u|%2-7.5u|%2-10.5u|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%2-2.5u_%%2-3.5u_%%2-5.5u_%%2-7.5u_%%2-10.5u|    |%2-2.5u|%2-3.5u|%2-5.5u|%2-7.5u|%2-10.5u|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%2-2.5u_%%2-3.5u_%%2-5.5u_%%2-7.5u_%%2-10.5u|   *|%2-2.5u|%2-3.5u|%2-5.5u|%2-7.5u|%2-10.5u|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%2-2.5u_%%2-3.5u_%%2-5.5u_%%2-7.5u_%%2-10.5u|    |%2-2.5u|%2-3.5u|%2-5.5u|%2-7.5u|%2-10.5u|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%2-2.5u_%%2-3.5u_%%2-5.5u_%%2-7.5u_%%2-10.5u|   *|%2-2.5u|%2-3.5u|%2-5.5u|%2-7.5u|%2-10.5u|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%2.6-8u_%%3.6-8u_%%5.6-8u_%%7.6-8u_%%10u|              |%2.6-8u|%3.6-8u|%5.6-8u|%7.6-8u|%10.6-8u|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%2.6-8u_%%3.6-8u_%%5.6-8u_%%7.6-8u_%%10.6-8u|             *|%2.6-8u|%3.6-8u|%5.6-8u|%7.6-8u|%10.6-8u|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%2.6-8u_%%3.6-8u_%%5.6-8u_%%7.6-8u_%%10.6-8u|              |%2.6-8u|%3.6-8u|%5.6-8u|%7.6-8u|%10.6-8u|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%2.6-8u_%%3.6-8u_%%5.6-8u_%%7.6-8u_%%10.6-8u|             *|%2.6-8u|%3.6-8u|%5.6-8u|%7.6-8u|%10.6-8u|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%2.6-8u_%%3.6-8u_%%5.6-8u_%%7.6-8u_%%10.6-8u|              |%2.6-8u|%3.6-8u|%5.6-8u|%7.6-8u|%10.6-8u|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%2.6-8u_%%3.6-8u_%%5.6-8u_%%7.6-8u_%%10.6-8u|             *|%2.6-8u|%3.6-8u|%5.6-8u|%7.6-8u|%10.6-8u|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");
}