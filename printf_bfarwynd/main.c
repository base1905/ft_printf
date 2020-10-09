/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfarwynd <bfarwynd@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 13:58:05 by bfarwynd          #+#    #+#             */
/*   Updated: 2020/07/21 11:45:34 by bfarwynd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdarg.h>

#include <stdio.h>
#include "h/ft_printf.h"

/*
flag

'0' - '9'
'-'
'.'
'*'
' '
*/

int	main()
{
	int i;
	
	i = printf("printf t00 !%s!\n","123456789");
	printf("i = %d\n",i);
	i = printf("printf t00 !%.5s!\n","123456789");
	printf("i = %d\n",i);
	i = printf("printf t00 !%*s!\n",20,"123456789");
	printf("i = %d\n",i);
	i = printf("printf t00 !%20s!\n","123456789");
	printf("i = %d\n",i);
	i = printf("printf t00 !%*.3s!\n",5,"123456789");
	printf("i = %d\n",i);
	i = printf("printf t00 !%*.4s!\n",5,"123456789");
	printf("i = %d\n",i);
	i = printf("printf t00 !%*.5s!\n",5,"123456789");
	printf("i = %d\n",i);
	i = printf("printf t00 !%*.6s!\n",5,"123456789");
	printf("i = %d\n",i);
	i = printf("printf t00 !%-*.3s!\n",5,"123456789");
	printf("i = %d\n",i);
	i = printf("printf t00 !%0*.3s!\n",5,"123456789");
	printf("i = %d\n",i);
	

//printf("%.p", NULL);
//ft_printf("%.p", NULL);
//printf("%.5p", NULL);
//ft_printf("%.5p", NULL);
//printf("%5.p", NULL);
//ft_printf("%5.p", NULL);
//printf("%.-3p", NULL);
//ft_printf("%.-3p", NULL);

//i = printf("%.p", &i);
//ft_printf("%.p", &i);
//printf("\ni = %d\n",i);
//i = printf("%.5p", &i);
//ft_printf("%.5p", &i);
//printf("\ni = %d\n",i);
//i = printf("%020.p", &i);
//ft_printf("%020.p", &i);
//printf("\ni = %d\n",i);
//i = printf("%.-3p", &i);
//ft_printf("%.-3p", &i);
//printf("\ni = %d\n",i);


	// i = printf("ft_printf FLAGS %%%*d|",10,-1234);
	// printf("\ni = %d\n",i);

i = printf("ft_printf FLAGS %%%0*.*d|",10,6,-1234);
printf("\ni = %d\n",i);
i = ft_printf("ft_printf FLAGS %%%0*.*d|",10,6,-1234);
printf("\ni = %d\n",i);

i = printf("ft_printf FLAGS %%%0*.*d|",10,6,-1234);
printf("\ni = %d\n",i);
i = ft_printf("ft_printf FLAGS %%%0*.*d|",10,6,-1234);
printf("\ni = %d\n",i);

i = printf("ft_printf FLAGS %%%020.*d|",6,-1234);
printf("\ni = %d\n",i);
i = ft_printf("ft_printf FLAGS %%%020.*d|",6,-1234);
printf("\ni = %d\n",i);

i = printf("ft_printf FLAGS %%%0*.6d|",10,-1234);
printf("\ni = %d\n",i);
i = ft_printf("ft_printf FLAGS %%%0*.6d|",10,-1234);
printf("\ni = %d\n",i);

i = printf("ft_printf FLAGS %%%0*d|",10,-1234);
printf("\ni = %d\n",i);
i = ft_printf("ft_printf FLAGS %%%0*d|",10,-1234);
printf("\ni = %d\n",i);


		i = printf("ft_printf FLAGS %%%0*.-1i|",10,-1234);
		printf("\ni = %d\n",i);
		i = ft_printf("ft_printf FLAGS %%%0*.-1i|",10,-1234);
		printf("\ni = %d\n",i);


i = printf("ft_printf FLAGS %%%0*.*i|",10,-1,-1234);
printf("\ni = %d\n",i);
i = ft_printf("ft_printf FLAGS %%%0*.*i|",10,-1,-1234);
printf("\ni = %d\n",i);

i = printf("ft_printf t00 !%%%%%s|%%%c!|%%%u|%%%x|%%%X|%%%p|%%%d|%%%i","123456789",'T',199,1039,1039,&i,-98,-99);
printf("\ni = %d\n",i);
i = ft_printf("ft_printf t00 !%%%%%s|%%%c!|%%%u|%%%x|%%%X|%%%p|%%%d|%%%i","123456789",'T',199,1039,1039,&i,-98,-99);
printf("\ni = %d\n",i);

i = printf("ft_printf FLAGS %%%3.2s|","-1234");
printf("\ni = %d\n",i);
i = ft_printf("ft_printf FLAGS %%%3.2s|","-1234");
printf("\ni = %d\n",i);

i = printf("ft_printf FLAGS %%%0*X|",20,1034);
printf("\ni = %d\n",i);
i = ft_printf("ft_printf FLAGS %%%0*X|",20,1034);
printf("\ni = %d\n",i);

i = printf("ft_printf FLAGS %%%0*.*X|",20,10,1034);
printf("\ni = %d\n",i);
i = ft_printf("ft_printf FLAGS %%%0*.*X|",20,10,1034);
printf("\ni = %d\n",i);

i = printf("ft_printf FLAGS %%%020.10X|",1034);
printf("\ni = %d\n",i);
i = ft_printf("ft_printf FLAGS %%%020.10X|",1034);
printf("\ni = %d\n",i);

i = printf("ft_printf FLAGS %%%0-*.*X|",20,10,1034);
printf("\ni = %d\n",i);
i = ft_printf("ft_printf FLAGS %%%0-*.*X|",20,10,1034);
printf("\ni = %d\n",i);

i = printf("ft_printf FLAGS %%%0-20.10X|",1034);
printf("\ni = %d\n",i);
i = ft_printf("ft_printf FLAGS %%%0-20.10X|",1034);
printf("\ni = %d\n",i);

i = printf("ft_printf FLAGS %%%-0*.*X|",20,10,1034);
printf("\ni = %d\n",i);
i = ft_printf("ft_printf FLAGS %%%-0*.*X|",20,10,1034);
printf("\ni = %d\n",i);

i = printf("ft_printf FLAGS %%%-020.10X|",1034);
printf("\ni = %d\n",i);
i = ft_printf("ft_printf FLAGS %%%-020.10X|",1034);
printf("\ni = %d\n",i);

i = printf("ft_printf FLAGS %%%-*.*X|",20,10,1034);
printf("\ni = %d\n",i);
i = ft_printf("ft_printf FLAGS %%%-*.*X|",20,10,1034);
printf("\ni = %d\n",i);

i = printf("ft_printf FLAGS %%%-20.10X|",1034);
printf("\ni = %d\n",i);
i = ft_printf("ft_printf FLAGS %%%-20.10X|",1034);
printf("\ni = %d\n",i);



	i = printf("ft_printf FLAGS %%%0*p|",20,&i);
	printf("\ni = %d\n",i);
	i = ft_printf("ft_printf FLAGS %%%0*p|",20,&i);
	printf("\ni = %d\n",i);


i = printf("ft_printf FLAGS %%%0*.*p|",20,10,&i);
printf("\ni = %d\n",i);
i = ft_printf("ft_printf FLAGS %%%0*.*p|",20,10,&i);
printf("\ni = %d\n",i);

i = printf("ft_printf FLAGS %%%020.10p|",&i);
printf("\ni = %d\n",i);
i = ft_printf("ft_printf FLAGS %%%020.10p|",&i);
printf("\ni = %d\n",i);


	i = printf("ft_printf FLAGS %%%0-*.*p|",20,10,&i);
	printf("\ni = %d\n",i);
	i = ft_printf("ft_printf FLAGS %%%0-*.*p|",20,10,&i);
	printf("\ni = %d\n",i);

	i = printf("ft_printf FLAGS %%%0-20.10p|",&i);
	printf("\ni = %d\n",i);
	i = ft_printf("ft_printf FLAGS %%%0-20.10p|",&i);
	printf("\ni = %d\n",i);

	i = printf("ft_printf FLAGS %%%-0*.*p|",20,10,&i);
	printf("\ni = %d\n",i);
	i = ft_printf("ft_printf FLAGS %%%-0*.*p|",20,10,&i);
	printf("\ni = %d\n",i);

	i = printf("ft_printf FLAGS %%%-020.10p|",&i);
	printf("\ni = %d\n",i);
	i = ft_printf("ft_printf FLAGS %%%-020.10p|",&i);
	printf("\ni = %d\n",i);

	i = printf("ft_printf FLAGS %%%-*.*p|",20,10,&i);
	printf("\ni = %d\n",i);
	i = ft_printf("ft_printf FLAGS %%%-*.*p|",20,10,&i);
	printf("\ni = %d\n",i);

	i = printf("ft_printf FLAGS %%%-20.10p|",&i);
	printf("\ni = %d\n",i);
	i = ft_printf("ft_printf FLAGS %%%-20.10p|",&i);
	printf("\ni = %d\n",i);


	i = printf("%5.0d!", 0);
	printf("\ni = %d\n",i);
	i = ft_printf("%5.0d!", 0);
	printf("\ni = %d\n",i);


	return (0);
	//gcc -Wall -Wextra -Werror ../main.c s/ft_*.c h/ft_printf.h 
	//gcc ../main.c s/ft_*.c h/ft_printf.h

	// gcc -Wall -Wextra -Werror main.c my_ft_printf/s/ft_*.c my_ft_printf/h/ft_printf.h -g
	// gcc -Wall -Wextra -Werror main.c primer/src/*.c primer/header/ft_printf.h -g 
	// gcc main.c primer/src/*.c primer/header/ft_printf.h -g 
}