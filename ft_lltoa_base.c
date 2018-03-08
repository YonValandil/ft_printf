#include "libft.h"

// static int		nbrlen(long long n, unsigned int base)
// {
	// return ((n < 0) + (n < base) ? 1 : nbrlen(n / base * ((n < 0) * -1 + !(n < 0)), base));
// }

static char		*sizemallocstr(char *str, long long n, int base)
{
	int i;

	i = (n < 0);
	while ((n >= base || (n < 0 && -base > n)) && (++i))
		n /= base;
	if(!(str = ft_strnew(i + 1)))//
		exit(EXIT_FAILURE);
	return (str);
}

static char		convert_char_base(long long n)
{
	char c;

	if (n > 9)
		c = n - 10 + 'a';
	else
		c = n + '0';
	return (c);
}

static void	nbr_to_str(char *str, unsigned int *i, long long n, int base)
{
	int sign;

	sign = (n < 0) ? -1 : 1;
	if (n < 0)
		str[0] = '-';
	if (n >= base || n <= -base)
	{
		nbr_to_str(str, i, n / base * sign, base);
		nbr_to_str(str, i, n % base, base);
	}
	else
		str[(*i)++] = convert_char_base(n * sign);
}

char	*ft_lltoa_base(long long n, int base)
{
    char    		*str;
	unsigned int	i;

	i = n < 0;
	str = NULL;
	str = sizemallocstr(str, n, base);
	nbr_to_str(str, &i, n, base);
	return (str);
}
