#include "ft_printf.h"

int	ft_putchar(char c)
{
	int	n;

	n = write(1, &c, 1);
	return (n);
}