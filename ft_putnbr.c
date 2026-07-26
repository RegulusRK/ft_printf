#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int     count;
	long    nl;

	count = 0;
	nl = n;
	if (nl < 0)
	{
		nl *= -1;
		count += ft_putchar('-');
	}
	if (nl >= 10)
		count += ft_putnbr(nl / 10);
	count += ft_putchar(nl % 10 + '0');
	return (count);
}