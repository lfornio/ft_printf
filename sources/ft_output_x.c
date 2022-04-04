#include "../includes/ft_printf.h"

char	*ft_num_null(char *s)
{
	free(s);
	s = malloc(sizeof(char) * 1);
	if (s == NULL)
		return (0);
	s[0] = '\0';
	return (s);
}

int	ft_output_x(t_print *flags, va_list arg)
{
	unsigned int	num;
	char			*p_x;
	int				length;

	num = va_arg(arg, unsigned int);
	p_x = conversion_10_on_16_min(num);
	if (flags->precision != 0)
		length = ft_output_digit_with_precision(flags, p_x);
	if (flags->dot == 1 && flags->precision == 0)
	{
		if (num == 0)
			p_x = ft_num_null(p_x);
		length = ft_output_result_with_width(flags, p_x);
	}
	if (flags->dot == 0 && flags->width != 0)
		length = ft_output_with_width(flags, p_x);
	if (flags->dot == 0 && flags->width == 0)
		length = ft_output_without(p_x);
	free(p_x);
	return (length);
}
