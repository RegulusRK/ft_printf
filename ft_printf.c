#include "ft_printf.h"

static int	print_conversion(char conversion, va_list *args)
{
	int	n;

	if (conversion == 'c')
	{
		n = ft_putchar((char)va_arg(*args, int));
		return (n);
	}
	if (conversion == '%')
	{
		n = ft_putchar('%');
		return (n);
	}
	if (conversion == 's')
	{
		n = ft_putstr(va_arg(*args, char *));
		return (n);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int 	i;
	int 	count;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] != '%')
			count += ft_putchar(format[i]);
		if (format[i] == '%')
		{
			i++;
			count += print_conversion(format[i], &args);
		}
		i++;
	}
	va_end(args);
	return (count);
} 