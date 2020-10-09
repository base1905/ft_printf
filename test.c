

#include <stdio.h>

int		ft_numsize_base(long int n, int base)
{
	int	size;

	size = 1;
	while ((n / base != 0))
	{
		n = n / base;
		size++;
	}
	return (size);
}


int main (void)

{
	int d = -54;

	printf("%d", ft_numsize_base(d, 10));

}