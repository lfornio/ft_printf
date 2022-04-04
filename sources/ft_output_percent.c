#include "../includes/ft_printf.h"

int	ft_output_percent(t_print *flags)
{
	char	*p_percent;
	int		length;

	p_percent = "%";
	if (flags->precision != 0)
		length = ft_output_digit_with_precision(flags, p_percent);
	if (flags->dot == 1 && flags->precision == 0)
		length = ft_output_result_with_width(flags, p_percent);
	if (flags->dot == 0 && flags->width != 0)
		length = ft_output_with_width(flags, p_percent);
	if (flags->dot == 0 && flags->width == 0)
		length = ft_output_without(p_percent);
	return (length);
}
