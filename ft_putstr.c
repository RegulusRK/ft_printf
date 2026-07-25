#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int i;
	int count;

	count = 0;
	i = 0;
	if (str == NULL)
		str = "(null)";
	while (str[i])
	{
		count += ft_putchar(str[i]);
		i++;
	}
	return (count);
}