#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_putstr(char *s, int len)
{
	if (len == 0)
		return (0);
	return(write(1, s, len));
}

int	ft_numsize_base(long int n, int base)
{
	int		size;

	size = 1;
	while ((n / base != 0))
    {
		n = n / base;
        size++;
    }
	return (size);
}

int hexbase (unsigned long int n)
{
	char	*str;
	int bytes;
	int len;

	bytes = 2 + ft_numsize_base(n, 16);
	if (!(str = (char *)malloc((bytes + 1) * sizeof(char))))
		return (0);
	str[bytes--] = '\0';
	while (n != 0)
	{
		str[bytes--] = "0123456789abcdef"[n % 16];
		n = n / 16;
	}
	str[bytes--] = 'x';
	str[bytes] = '0';
	len = ft_strlen(str);
	ft_putstr(str, len);
	free(str);
	return (bytes);
}

int main (void)
{
	hexbase(1234834753874);
	return (0);
}