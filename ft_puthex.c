#include "ft_printf.h"

int	ft_puthex(unsigned int n, char conversion)
{
	int     count;
	char    *base;
	char    *base_m;

	count = 0;
	base = "0123456789abcdef";
	base_m = "0123456789ABCDEF";
	if (n >= 16)
		count += ft_puthex(n / 16, conversion);
	if (conversion == 'x')
		count += ft_putchar(base[n % 16]);
	if (conversion == 'X')
		count += ft_putchar(base_m[n % 16]);
	return (count);
}