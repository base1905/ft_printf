#include"libftprintf.h"

void len_definer(int s, struct s_flags flag, int len, int len_prec)
{
	char isminusprint;

	if (!flag.minus)
	{
		if (flag.zero && s < 0 && !flag.dot)
		{
			write(1, "-", 1);
			isminusprint = '-';
		
		}  
		if (s < 0)
			len++; 
		if (flag.width > len + len_prec)
			(flag.zero && !flag.dot) ? (zero(flag.width - len - len_prec)) : (whitespace(flag.width - len - len_prec));
		if (s < 0 && isminusprint != '-')
		{
			write(1, "-", 1);  
			s = -s;
		}
		if (len_prec)
			zero(len_prec);
		ft_putnbr(s);
	}
	else 
	{ 
		if (s < 0)
		{
			write(1, "-", 1);
			len++;
		}  
		if (len_prec)
			zero(len_prec);
		ft_putnbr(s);
		if (flag.width > len + len_prec)
			whitespace(flag.width - len - len_prec);
	}
}

int	ft_printspec_di(int s, struct s_flags flag)
{
	int bytes;
	int len;
	int len_prec;

	bytes = 0;
	if (s<0)
	{
		flag.negative_di = 1;
		s = -s;
	}
	len	= ft_intlen(s);
	len_prec = (flag.precision > len) ? flag.precision - len : 0;
	if (s == 0  && flag.precision == 0 && flag.dot)
	{
		len = 0;
		whitespace(flag.width);
	}
	else 
		{
			//printf("%d", len);
			//printf("%d\n", len_prec);
			len_definer(s, flag, len, len_prec);
		}
	if (flag.width > len + len_prec)
		bytes += flag.width;
	else
		bytes += len + len_prec;
	return (bytes);
} 
