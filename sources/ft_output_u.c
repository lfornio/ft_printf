#include "../includes/ft_printf.h"

int	ft_output_u(t_print *flags, va_list arg)
{
	unsigned int	num;
	char			*p_u;
	int				length;

	num = va_arg(arg, unsigned int);
	p_u = ft_itoa_u(num);
	if (flags->precision != 0)
		length = ft_output_digit_neg_with_precision(flags, p_u);
	if (flags->dot == 1 && flags->precision == 0)
	{
		if (num == 0)
			p_u = ft_num_null(p_u);
		length = ft_output_result_with_width(flags, p_u);
	}
	if (flags->dot == 0 && flags->width != 0)
		length = ft_output_digit_neg_with_width(flags, p_u);
	if (flags->dot == 0 && flags->width == 0)
		length = ft_output_without(p_u);
	free (p_u);
	return (length);
}
