/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iserzhan <iserzhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 18:04:51 by iulias            #+#    #+#             */
/*   Updated: 2020/07/24 16:28:27 by iserzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
	int i;
	int j;
	int a = 2;
	int b = 6;
	char *str = "hello";
	char c = 'a';
	
	
	printf("\t\t\tINT\n");
	i = ft_printf("%015d %07p %c\n", -2147483647, &a, 'k');
	j = printf("%015d %07p %c\n", -2147483647, &a, 'k');
	printf("Return value ft_printf: %d Return value printf: %d\n\n", i, j);

	printf("\t\t\tINT\n");
	i = ft_printf("%015d\n", -2147483648);
	j = printf("%015d\n", -2147483648);
	printf("Return value ft_printf: %d Return value printf: %d\n\n", i, j);

	printf("STAR with minus, zero, neg num\n");
	i = ft_printf("%*i hh\n", -07, -54);
	j = printf("%*i hh\n", -07, -54);
	printf("Return value ft_printf: %d Return value printf: %d\n\n\n", i, j);

	printf("Minus, zero, neg num\n");
	i = ft_printf("%-07d hh\n", -54);
	j = printf("%-07d hh\n", -54);
	printf("Return value ft_printf: %d Return value printf: %d\n\n", i, j);

	printf("Zero, neg num\n");
	i = ft_printf("%07d hh\n", -54);
	j = printf("%07d hh\n", -54);
	printf("Return value ft_printf: %d Return value printf: %d\n\n\n", i, j);

	printf("Minus, zero, pos num\n");
	i = ft_printf("%-07d\n", 54);
	j = printf("%-07d\n", 54);
	printf("Return value ft_printf: %d Return value printf: %d\n\n\n", i, j);
	

	printf("Field width is less than digit size\n");
	i = ft_printf("%2d\n", a);
	j = printf("%2d\n", a);
	printf("Return value ft_printf: %d Return value printf: %d\n\n", i, j);

	printf("Field width with minus\n");
	i = ft_printf("%-10d hello\n", a);
	j = printf("%-10d hello\n", a);
	printf("Return value ft_printf: %d Return value printf: %d\n\n", i, j);

	printf("Field width with null\n");
	i = ft_printf("%09d\n", a);
	j = printf("%09d\n", a);
	printf("Return value ft_printf: %d Return value printf: %d\n\n", i, j);

	printf("Field width with precision\n");
	i = ft_printf("%10.5d\n", a);
	j = printf("%10.5d\n", a);
	printf("Return value ft_printf: %d Return value printf: %d\n\n", i, j);

	printf("Field width with precision and minus\n");
	i = ft_printf("%-10.5d\n", a);
	j = printf("%-10.5d\n", a);
	printf("Return value ft_printf: %d Return value printf: %d\n\n", i, j);

	printf("Star with precision\n");
	i = ft_printf("%*.d\n", 5, 12);
	j = printf("%*.d\n", 5, 12);
	printf("Return value ft_printf: %d Return value printf: %d\n\n\n", i, j);

	printf("Star with width\n");
	i = ft_printf("%*d\n", 5, 12);
	j = printf("%*d\n", 5, 12);
	printf("Return value ft_printf: %d Return value printf: %d\n\n", i, j);

	printf("Star with neg precision\n");
	i = ft_printf("%.*d\n", -5, 12);
	j = printf("%.*d\n", -5, 12);
	printf("Return value ft_printf: %d Return value printf: %d\n\n\n", i, j);

	printf("Star with zero precision\n");
	i = ft_printf("%.*d\n", 0, 12);
	j = printf("%.*d\n", 0, 12);
	printf("Return value ft_printf: %d Return value printf: %d\n\n\n", i, j);

	printf("Zero precision\n");
	i = ft_printf("%.0d\n", 12);
	j = printf("%.0d\n", 12);
	printf("Return value ft_printf: %d Return value printf: %d\n\n\n", i, j);

	printf("Star with width and precision\n");
	i = ft_printf("%0*d\n", 12, 4);
	j = printf("%000*d\n", 12, 4);
	printf("Return value ft_printf: %d Return value printf: %d\n\n\n", i, j);

	printf("Neg precision\n");
	i = ft_printf("%.-5d\n", 12);
	j = printf("%.-5d\n", 12);
	printf("Return value ft_printf: %d Return value printf: %d\n\n", i, j);

	printf("STAR with width\n");
	i = ft_printf("%*d\n", 12, 8);
	j = printf("%*d\n", 12, 8);
	printf("Return value ft_printf: %d Return value printf: %d\n\n", i, j);

	printf("STAR with precision\n");
	i = ft_printf("%.*d\n", 12, 8);
	j = printf("%.*d\n", 12, 8);
	printf("Return value ft_printf: %d Return value printf: %d\n\n\n\n", i, j);



	printf("\t\tPOINTER\n");

	i = ft_printf("%p\n", &a);
	j = printf("%p\n", &a);
	printf("Return value ft_printf: %d Return value printf: %d\n\n", i, j);

	printf("Field width\n");
	i = ft_printf("%25p\n", &a);
	j = printf("%25p\n", &a);
	printf("Return value ft_printf: %d Return value printf: %d\n\n", i, j);

	printf("Field width is less than digit size\n");
	i = ft_printf("%2p\n", &a);
	j = printf("%2p\n", &a);
	printf("Return value ft_printf: %d Return value printf: %d\n\n", i, j);

	printf("Field width with minus\n");
	i = ft_printf("%-20p hello\n", &a);
	j = printf("%-20p hello\n", &a);
	printf("Return value ft_printf: %d Return value printf: %d\n\n", i, j);

	printf("Field width with zero\n");
	i = ft_printf("%019p\n", &a);
	j = printf("%019p\n", &a);
	printf("Return value ft_printf: %d Return value printf: %d\n\n", i, j);

	printf("Field width with precision more than len, less than width\n");
	i = ft_printf("%%25.17p %25.17p hello\n", &a);
	j = printf("%%25.17p %25.17p hello\n", &a);
	printf("Return value ft_printf: %d Return value printf: %d\n\n", i, j);

	printf("Field width with precision and minus\n");
	i = ft_printf("%20.30p\n", &a);
	j = printf("%20.30p\n", &a);
	printf("Return value ft_printf: %d Return value printf: %d\n\n", i, j);

	printf("Field width with precision more than width\n");
	i = ft_printf("%15.20p\n", &a);
	j = printf("%15.20p\n", &a);
	printf("Return value ft_printf: %d Return value printf: %d\n\n", i, j);

	printf("Field width with invalid precision\n");
	i = ft_printf("%-10.-5p\n", &a);
	j = printf("%-10.-5p\n", &a);
	printf("Return value ft_printf: %d Return value printf: %d\n\n\n", i, j);



	printf("\t\t\tHEX\n");
	i = ft_printf("%x\n", a);
	j = printf("%x\n", a);
	printf("Return value ft_printf: %d Return value printf: %d\n\n", i, j);

	printf("Field width\n");
	i = ft_printf("%15x\n", a);
	j = printf("%15x\n", a);
	printf("Return value ft_printf: %d Return value printf: %d\n\n", i, j);

	printf("Field width is less than digit size\n");
	i = ft_printf("%2X\n", a);
	j = printf("%2X\n", a);
	printf("Return value ft_printf: %d Return value printf: %d\n\n", i, j);

	printf("Field width with minus\n");
	i = ft_printf("%-20x hello\n", a);
	j = printf("%-20x hello\n", a);
	printf("Return value ft_printf: %d Return value printf: %d\n\n", i, j);

	printf("Field width with null\n");
	i = ft_printf("%09x\n", a);
	j = printf("%09x\n", a);
	printf("Return value ft_printf: %d Return value printf: %d\n\n", i, j);

	printf("Field width with precision\n");
	i = ft_printf("%10.5x\n", a);
	j = printf("%10.5x\n", a);
	printf("Return value ft_printf: %d Return value printf: %d\n\n", i, j);

	printf("Field width with precision and minus\n");
	i = ft_printf("%-10.5x\n", a);
	j = printf("%-10.5x\n", a);
	printf("Return value ft_printf: %d Return value printf: %d\n\n", i, j);

	printf("Field width with invalid precision\n");
	i = ft_printf("%-10.-5x\n", a);
	j = printf("%-10.-5x\n", a);
	printf("Return value ft_printf: %d Return value printf: %d\n\n\n", i, j);




	printf("\t\t\tSTRING\n");

	i = ft_printf("%s\n", str);
	j = printf("%s\n", str);
	printf("Return value ft_printf: %d Return value printf: %d\n\n", i, j);

	printf("Field width\n");
	i = ft_printf("%15s\n", str);
	j = printf("%15s\n", str);
	printf("Return value ft_printf: %d Return value printf: %d\n\n", i, j);

	printf("Field width is less than str size\n");
	i = ft_printf("%2s\n", str);
	j = printf("%2s\n", str);
	printf("Return value ft_printf: %d Return value printf: %d\n\n", i, j);

	printf("Field width with minus\n");
	i = ft_printf("%-10s hello\n", str);
	j = printf("%-10s hello\n", str);
	printf("Return value ft_printf: %d Return value printf: %d\n\n", i, j);

	printf("Field width with null\n");
	i = ft_printf("%09s\n", str);
	j = printf("%09s\n", str);
	printf("Return value ft_printf: %d Return value printf: %d\n\n", i, j);

	printf("Field width with precision\n");
	i = ft_printf("%10.5s\n", str);
	j = printf("%10.5s\n", str);
	printf("Return value ft_printf: %d Return value printf: %d\n\n", i, j);

	printf("Field width precision less than strlen\n");
	i = ft_printf("%10.2s\n", str);
	j = printf("%10.2s\n", str);
	printf("Return value ft_printf: %d Return value printf: %d\n\n", i, j);

	printf("Field width with precision and minus\n");
	i = ft_printf("%-10.5s\n", str);
	j = printf("%-10.5s\n", str);
	printf("Return value ft_printf: %d Return value printf: %d\n\n", i, j);

	printf("Field width with precision less than strlen and minus\n");
	i = ft_printf("%-10.2s\n", str);
	j = printf("%-10.2s\n", str);
	printf("Return value ft_printf: %d Return value printf: %d\n\n", i, j);

	printf("NULL string\n");
	//i = ft_printf("%s\n", NULL);
	j = printf("%3.8s\n", NULL);
	printf("Return value ft_printf: %d Return value printf: %d\n\n\n", i, j);






	printf("\t\t\tCHAR\n");
	i = ft_printf("%05c\n", 'a');
	j = printf("%05c\n", 'a');
	printf("Return value ft_printf: %d Return value printf: %d\n\n", i, j);

	i = ft_printf("%-05c\n", 'a');
	j = printf("%-05c\n", 'a');
	printf("Return value ft_printf: %d Return value printf: %d\n\n", i, j);

	printf("Field width\n");
	i = ft_printf("%15c\n", c);
	j = printf("%15c\n", c);
	printf("Return value ft_printf: %d Return value printf: %d\n\n", i, j);

	printf("Field width is less than digit size\n");
	i = ft_printf("%2c\n", a);
	j = printf("%2c\n", a);
	printf("Return value ft_printf: %d Return value printf: %d\n\n", i, j);

	printf("CRAZY\n");
	i = ft_printf("%c%c%c%c%c%c\n", 'i', '!', '"', '#', '~');
	j = printf("%c%c%c%c%c%c\n", 'i', '!', '"', '#', '~');
	printf("Return value ft_printf: %d Return value printf: %d\n\n", i, j);

	printf("Field width with null\n");
	i = ft_printf("%09c\n", a);
	j = printf("%09c\n", a);
	printf("Return value ft_printf: %d Return value printf: %d\n\n", i, j);

	printf("Field width with precision\n");
	i = ft_printf("%10.5d\n", a);
	j = printf("%10.5d\n", a);
	printf("Return value ft_printf: %d Return value printf: %d\n\n", i, j);

	printf("Field width with precision and minus\n");
	i = ft_printf("%-10.5d\n", a);
	j = printf("%-10.5d\n", a);
	printf("Return value ft_printf: %d Return value printf: %d\n\n", i, j);

	printf("Field width with invalid precision\n");
	i = ft_printf("%-10.-5d\n", a);
	j = printf("%-10.-5d\n", a);
	printf("Return value ft_printf: %d Return value printf: %d\n\n\n", i, j);

	printf("Precision\n");
	i = ft_printf("%.d\n", 0);
	j = printf("%.d\n", 0);
	printf("Return value ft_printf: %d Return value printf: %d\n\n", i, j);

	printf("\t\t%%\n");

	i = ft_printf("%%p %p\n", &a);
	j = printf("%%p %p\n", &a);
	printf("Return value ft_printf: %d Return value printf: %d\n\n", i, j);

	printf("Field width\n");
	i = ft_printf("%25p\n", &a);
	j = printf("%25p\n", &a);
	printf("Return value ft_printf: %d Return value printf: %d\n\n", i, j);

	printf("Field width is less than digit size\n");
	i = ft_printf("%2p\n", &a);
	j = printf("%2p\n", &a);
	printf("Return value ft_printf: %d Return value printf: %d\n\n\n\n", i, j);

	printf("%% \n");
	i = ft_printf("%% *.5i 42 == |% *.5i|\n", 4, 42);
	j = printf("%% *.5i 42 == |% *.5i|\n", 4, 42);
	printf("Return value ft_printf: %d Return value printf: %d\n\n", i, j);

	printf("Null Pointer\n");
	i = ft_printf("%5.p\n", NULL);
	j = printf("%5.p\n", NULL);
	printf("Return value ft_printf: %d Return value printf: %d\n\n", i, j);

	printf("Null Pointer with precision\n");
	i = ft_printf("%5.4p\n", NULL);
	j = printf("%5.4p\n", NULL);
	printf("Return value ft_printf: %d Return value printf: %d\n\n", i, j);


	return (0);
}