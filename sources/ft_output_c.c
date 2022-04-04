#include "../includes/ft_printf.h"

static void	ft_output_c_right(t_print *flags, va_list arg, char simbol)
{
	int	i;

	i = flags->width;
	while (i > 1)
	{
		write(1, " ", 1);
		i--;
	}
	simbol = va_arg(arg, int);
	write(1, &simbol, 1);
}

static void	ft_output_c_left(t_print *flags, va_list arg, char simbol)
{
	int	i;

	i = 0;
	simbol = va_arg(arg, int);
	write(1, &simbol, 1);
	while (i < flags->width - 1)
	{
		write(1, " ", 1);
		i++;
	}
}

int	ft_output_c(t_print *flags, va_list arg)
{
	char	simbol;
	int		length;

	if ((flags->minus == 0 || flags->minus == 1) && flags->width == 0)
	{
		simbol = va_arg(arg, int);
		write(1, &simbol, 1);
		length = 1;
	}
	if (flags->minus == 1 && flags->width != 0)
	{
		ft_output_c_left(flags, arg, simbol);
		length = flags->width;
	}
	if (flags->minus == 0 && flags->width != 0)
	{
		ft_output_c_right(flags, arg, simbol);
		length = flags->width;
	}
	return (length);
}
