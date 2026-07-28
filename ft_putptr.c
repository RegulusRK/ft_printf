#include "ft_printf.h"

static int	put_address(unsigned long n)
{
	const char    *base;
	int     count;
	
	count = 0;
	base = "0123456789abcdef";
	if (n >= 16)
		count += put_address(n / 16);
	count += ft_putchar(base[n % 16]);
	return (count);
}

int	ft_putptr(void *ptr)
{
	int     count;

	count = 0;
	if (ptr == NULL)
		return (ft_putstr("(nil)"));
	count += ft_putstr("0x");
	count += put_address((unsigned long)ptr);
	return (count);
}