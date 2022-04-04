#include "../includes/ft_printf.h"

char	*ft_new_d(char *str, int flag)
{
	char	*s;
	int		i;
	int		j;

	i = 1;
	j = 1;
	s = malloc(sizeof(char) * (flag + 1));
	if (s == NULL)
		return (NULL);
	while (str[j] && (i < flag))
	{
		s[0] = '-';
		while (i <= (flag - (int)ft_strlen(str)))
		{
			s[i] = '0';
			i++;
		}
		s[i] = str[j];
		i++;
		j++;
	}
	s[i] = '\0';
	return (s);
}

int	ft_output_string_with_width_d(char *s, t_print *flags, int len)
{
	int		lenght;
	char	*new;

	if (flags->width <= len)
		lenght = ft_output_string(s);
	else
	{
		if (flags->minus == 0 && flags->zero == 0)
			ft_output_string_right(flags, s);
		if (flags->minus == 1)
			ft_output_string_left(flags, s);
		if (flags->zero == 1)
		{
			if (s[0] == '-')
				new = ft_new_d(s, flags->width);
			else
				new = ft_new_string(s, flags->width);
			ft_output_string(new);
			free(new);
		}
		lenght = flags->width;
	}
	return (lenght);
}

int	ft_output_digit_neg_with_precision(t_print *flags, char *str)
{
	int		length;
	char	*s;

	if (flags->precision < 0)
	{
		s = ft_substr(str, 0, (int)ft_strlen(str));
		length = ft_output_string_with_width_d(s, flags, (int)ft_strlen(s));
		free(s);
		return (length);
	}
	if (flags->precision < (int)ft_strlen(str) && flags->precision >= 0)
		s = ft_substr(str, 0, (int)ft_strlen(str));
	else
	{
		if (str[0] == '-')
			s = ft_new_d(str, flags->precision + 1);
		else
			s = ft_new_string(str, flags->precision);
	}
	if (flags->width != 0)
		length = ft_output_digit_with_width(s, flags, ft_strlen(s));
	else
		length = ft_output_string(s);
	free(s);
	return (length);
}

int	ft_output_digit_neg_with_width(t_print *flags, char *str)
{
	char	*s;
	int		length;

	s = NULL;
	if (flags->width >= (int)ft_strlen(str))
	{
		if (flags->zero == 1)
		{
			if (flags->dot != 1)
			{
				if (str[0] == '-')
					s = ft_new_d(str, flags->width);
				else
					s = ft_new_string(str, flags->width);
			}
			length = ft_output_string(s);
			free(s);
		}
		else
			length = ft_output_with_width(flags, str);
	}
	else
		length = ft_output_string(str);
	return (length);
}

int	ft_output_d_and_i(t_print *flags, va_list arg)
{
	int		length;
	char	*p_d_and_i;
	int		num;

	num = va_arg(arg, int);
	p_d_and_i = ft_itoa(num);
	if (flags->precision != 0)
		length = ft_output_digit_neg_with_precision(flags, p_d_and_i);
	if (flags->dot == 1 && flags->precision == 0)
	{
		if (num == 0)
			p_d_and_i = ft_num_null(p_d_and_i);
		length = ft_output_result_with_width(flags, p_d_and_i);
	}
	if (flags->dot == 0 && flags->width != 0)
		length = ft_output_digit_neg_with_width(flags, p_d_and_i);
	if (flags->dot == 0 && flags->width == 0)
		length = ft_output_without(p_d_and_i);
	free(p_d_and_i);
	return (length);
}
