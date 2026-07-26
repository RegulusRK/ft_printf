#include "ft_printf.h"

static int	print_number_conversion(char conversion, va_list *args)
{
	if (conversion == 'd' || conversion == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	if (conversion == 'u')
		return (ft_putunsigned(va_arg(*args, unsigned int)));
	if (conversion == 'x' || conversion == 'X')
		return (ft_puthex(va_arg(*args, unsigned int), conversion));
	return (0);
}

static int	print_text_conversion(char conversion, va_list *args)
{
	if (conversion == 'c')
		return (ft_putchar((char)va_arg(*args, int)));
	if (conversion == '%')
		return (ft_putchar('%'));
	if (conversion == 's')
		return (ft_putstr(va_arg(*args, char *)));
	return (0);
}

static int	print_conversion(char conversion, va_list *args)
{
	if (conversion == 'c' ||
		conversion == 's' ||
		conversion == '%')
		return (print_text_conversion(conversion, args));
	if (conversion == 'i' ||
		conversion == 'd' ||
		conversion == 'u' ||
		conversion == 'x' ||
		conversion == 'X')
		return (print_number_conversion(conversion, args));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

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
			if (format[i] == '\0')
				break ;
			count += print_conversion(format[i], &args);
		}
		i++;
	}
	va_end(args);
	return (count);
}