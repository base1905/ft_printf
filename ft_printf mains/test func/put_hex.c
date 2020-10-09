#include <stdio.h>
#include <unistd.h>


static int	ft_putchar(char c)
{
	return(write(1, &c, 1));
}
// static void ft_print_hex(unsigned long int n)
// {
// 	char	*str;

// 	str = "0123456789abcdef";
	
// 	if ( n >= 16)
// 		ft_print_hex(n / 16);
// 	ft_putchar(str[n % 16]);


// }

static void	ft_print_hex(unsigned long int c)
{
	char	*hex;

	hex = "0123456789ABCDEF";
	if (c >= 16)
		ft_putchar(hex[c / 16]);
	else
		ft_putchar('0');
	ft_putchar(hex[c % 16]);
}

	

int main (void)
{
	//char *base;
	//base =  "0123456789abcdef";
	ft_print_hex(1234);

}