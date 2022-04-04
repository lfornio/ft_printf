#include "includes/ft_printf.h"

static t_print	*ft_set_values_for_flags(t_print *flags)
{
	flags->width = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->dot = 0;
	flags->precision = 0;
	flags->star = 0;
	return (flags);
}

static int	ft_analysis_types(const char *format, va_list arg, int index,
							 t_print *flags)
{
	int	len;

	len = 1;
	if (format[index] == 'c')
		len = ft_output_c(flags, arg);
	else if (format[index] == 's')
		len = ft_output_s(flags, arg);
	else if (format[index] == 'x')
		len = ft_output_x(flags, arg);
	else if (format[index] == 'X')
		len = ft_output_x_max(flags, arg);
	else if (format[index] == 'p')
		len = ft_output_pointer(flags, arg);
	else if (format[index] == 'u')
		len = ft_output_u(flags, arg);
	else if (format[index] == 'd' || format[index] == 'i')
		len = ft_output_d_and_i(flags, arg);
	else if (format[index] == '%')
		len = ft_output_percent(flags);
	return (len);
}

static int	ft_output_pr(t_print *flags, va_list ap, const char *format, int i)
{
	int	len;

	len = 0;
	if (ft_found_type(format, i) != 0)
		len = ft_analysis_types(format, ap, i, flags);
	return (len);
}

static int	ft_output_print(t_print *flags, va_list ap, const char *format)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (format[i])
	{
		ft_set_values_for_flags(flags);
		if (format[i] != '%')
			len += write(1, &format[i], 1);
		else
		{
			if (format[i + 1] == ' ')
			{
				len += write(1, " ", 1);
				i++;
			}
			i = ft_analysis_flags(format, ap, i + 1, flags);
			len += ft_output_pr(flags, ap, format, i);
			if (format[i] == '\0')
				return (len);
		}
		i++;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	t_print	*flags;
	va_list	ap;
	int		length;

	if (!format)
		return (-1);
	flags = (t_print *)malloc(sizeof(t_print));
	if (!flags)
		return (0);
	va_start(ap, format);
	length = ft_output_print(flags, ap, format);
	va_end(ap);
	free(flags);
	return (length);
}
