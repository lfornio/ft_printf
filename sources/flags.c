#include "../includes/ft_printf.h"

static int	ft_found_flag(const char *str, int i)
{
	if (str[i] == '-' || str[i] == '*' || str[i] == '.' || (str[i] >= '0'
			&& str[i] <= '9'))
		return (1);
	else
		return (0);
}

static t_print	*ft_found_number(t_print *flags, char c)
{
	if (flags->star == 1)
		flags->width = 0;
	else
		flags->width = flags->width * 10 + (c - '0');
	return (flags);
}

static t_print	*ft_found_star(t_print *flags, va_list ap)
{
	flags->star = 1;
	flags->width = va_arg(ap, int);
	if (flags->width < 0)
	{
		flags->minus = 1;
		flags->width = -flags->width;
		flags->zero = 0;
	}
	return (flags);
}

static int	ft_found_dot(t_print *flags, va_list ap, const char *str, int i)
{
	flags->dot = 1;
	i++;
	while (str[i] && (ft_found_type(str, i) != 1))
	{
		if (str[i] >= '0' && str[i] <= '9')
			flags->precision = flags->precision * 10 + (str[i] - '0');
		else if (str[i] == '*')
			flags->precision = va_arg(ap, int);
		i++;
	}
	return (i);
}

int	ft_analysis_flags(const char *format, va_list ap, int index, t_print *flags)
{
	while (format[index] && (ft_found_type(format, index) != 1))
	{
		if ((ft_found_type(format, index) != 1)
			&& (ft_found_flag(format, index) != 1))
			break ;
		if (format[index] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (format[index] == '-')
		{
			flags->minus = 1;
			flags->zero = 0;
		}
		if (format[index] >= '0' && format[index] <= '9')
			ft_found_number(flags, format[index]);
		if (format[index] == '.')
			return (ft_found_dot(flags, ap, format, index));
		if (format[index] == '*')
			ft_found_star(flags, ap);
		index++;
	}
	return (index);
}
