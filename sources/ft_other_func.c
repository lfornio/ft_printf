#include "../includes/ft_printf.h"

int	ft_output_with_width(t_print *flags, char *str)
{
	char	*s;
	int		len;

	s = ft_substr(str, 0, (int)ft_strlen(str));
	len = ft_output_string_with_width(s, flags, (int)ft_strlen(s));
	free(s);
	return (len);
}

int	ft_output_without(char *str)
{
	char	*s;
	int		len;

	s = ft_substr(str, 0, (int)ft_strlen(str));
	len = ft_output_string(s);
	free(s);
	return (len);
}

void	ft_output_x_zero(t_print *flags, char *s)
{
	int	i;

	i = 0;
	if (flags->precision < 0)
	{
		while (i < (flags->width - (int)ft_strlen(s)))
		{
			write(1, "0", 1);
			i++;
		}
	}
	else
	{
		while (i < (flags->width - (int)ft_strlen(s)))
		{
			write(1, " ", 1);
			i++;
		}
	}
	ft_putstr_fd(s, 1);
}

int	ft_output_digit_with_width(char *s, t_print *flags, int len)
{
	int	lenght;

	if (flags->width <= len)
		lenght = ft_output_string(s);
	else
	{
		if (flags->minus == 0 && flags->zero == 0)
			ft_output_string_right(flags, s);
		if (flags->minus == 1)
			ft_output_string_left(flags, s);
		if (flags->zero == 1)
			ft_output_x_zero(flags, s);
		lenght = flags->width;
	}
	return (lenght);
}

int	ft_output_digit_with_precision(t_print *flags, char *str)
{
	int		length;
	char	*s;

	if (flags->precision < (int)ft_strlen(str) || flags->precision < 0)
		s = ft_substr(str, 0, (int)ft_strlen(str));
	else
		s = ft_new_string(str, flags->precision);
	if (flags->width != 0)
		length = ft_output_digit_with_width(s, flags, (int)ft_strlen(s));
	else
		length = ft_output_string(s);
	free(s);
	return (length);
}
