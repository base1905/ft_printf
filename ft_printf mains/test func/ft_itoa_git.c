#include <stdlib.h>

static int	ft_unsignint(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int		get_len(int nbr)
{
	int len = 0;
	if (nbr <= 0)
		++len;
	while (nbr != 0)
	{
		++len;
		nbr = nbr / 10;
	}
	return (len);
}

char		*ft_itoa(int n, int prec)
{
	int		i;
	int		len;
	char	*str;

	len = get_len(n);
	if (prec > len)
		len = prec;
	if (n < 0)
		len++;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
		str[i++] = '0';
	if (n < 0)
		str[0] = '-';
	str[len] = '\0';
	while (n / 10 != 0)
	{
		str[--len] = ft_unsignint(n % 10) + '0';
		n /= 10;
	}
//	str[--len] = ft_unsignint(n % 10) + '0';
	return (str);
}

// int		absolute_value(int nbr)
// {
// 	if (nbr < 0)
// 		return (-nbr);
// 	return (nbr);
// }
 
// int		get_len(int nbr)
// {
// 	int len = 0;
// 	if (nbr <= 0)
// 		++len;
// 	while (nbr != 0)
// 	{
// 		++len;
// 		nbr = nbr / 10;
// 	}
// 	return (len);
// }
 
// char	*ft_itoa(int nbr)
// {
// 	char *result;
// 	int len;
 
// 	len = get_len(nbr);
// 	result = malloc(sizeof(char) * (len + 1));
// 	result[len] = '\0';
 
// 	if (nbr < 0)
// 		result[0] = '-';
// 	else if (nbr == 0)
// 		result[0] = '0';
 
// 	while (nbr != 0)
// 	{
// 		--len;
// 		result[len] = absolute_value(nbr % 10) + '0';
// 		nbr = nbr / 10;
// 	}
// 	return (result);
// }
 
#include <stdio.h>
#include <limits.h>
 
int		main(void)
{
 int d = INT_MIN;
 printf("%d =? %s\n", d, ft_itoa(d, 10));
 
 d = -13;
 printf("%d =? %s\n", d, ft_itoa(d, 10));
 
 d = 0;
 printf("%d =? %s\n", d, ft_itoa(d, 10));
 
 d = 5;
 printf("%d =? %s\n", d, ft_itoa(d, 10));
 
 d = INT_MAX;
 printf("%d =? %s\n", d, ft_itoa(d, 10));
}