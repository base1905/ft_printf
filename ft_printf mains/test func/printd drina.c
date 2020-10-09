/* int check (char **s)
{
	int bytes;

	bytes = 0;
	if (*s[0] == '-')
		bytes += putchar(*s[0]);
	(*s) += bytes;
	return (bytes);
}


int	ft_printspec_di(char *s, struct s_flags flag)
{
	int len;
	int bytes;

	bytes = 0;
	if (s[0] == '0' && flag.dot && !flag.precision)
		s[0] = '\0';
	flag.len_list = ft_strlen(s);
	if (!flag.width && flag.precision && flag.precision > flag.len_list)
		len = flag.precision - flag.len_list;
	else if (flag.precision && flag.precision > flag.len_list && flag.width)
		len = flag.width - flag.precision;
	else
		len = flag.width - flag.len_list;
	if (s[0] == '-' && flag.precision >= flag.len_list)
		len--;
	if (flag.width && !flag.minus && (!flag.zero || flag.dot))
		bytes += whitespace(len);
	if (flag.zero && !flag.minus && !flag.dot)
		bytes += check(&s) + zero(len);
	if (flag.dot && flag.precision >= flag.len_list)
		bytes += check(&s) + zero(flag.precision - ft_strlen(s));
	bytes += ft_putstr(s,ft_strlen(s));
	if (flag.minus && flag.width)
		bytes += whitespace(len);
	return (bytes);
} */