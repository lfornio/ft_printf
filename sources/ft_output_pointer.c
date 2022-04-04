#include "../includes/ft_printf.h"

static char	*ft_p_null(char *s)
{
	free(s);
	s = malloc(sizeof(char) * 3);
	if (s == NULL)
		return (NULL);
	s[0] = '0';
	s[1] = 'x';
	s[2] = '\0';
	return (s);
}

static char	*ft_new_p(char *str, int flag)
{
	char	*s;
	int		i;
	int		j;

	i = 2;
	j = 2;
	s = malloc(sizeof(char) * (flag + 2 + 1));
	if (s == NULL)
		return (NULL);
	while (str[j] && (i < flag + 2))
	{
		s[0] = '0';
		s[1] = 'x';
		while (i < (flag - (int)ft_strlen(str) + 4))
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

static int	ft_output_p_with_precision(t_print *flags, char *p_x_min,
	unsigned int num)
{
	int		len;
	char	*s;

	if (flags->precision < 0)
	{
		s = ft_substr(p_x_min, 0, (int)ft_strlen(p_x_min));
		len = ft_output_string(s);
		free(s);
		return (len);
	}
	if (flags->precision < (int)ft_strlen(p_x_min) && flags->precision > 0)
	{
		if (num == 0)
			s = ft_new_p(p_x_min, flags->precision);
		else
			s = ft_substr(p_x_min, 0, (int)ft_strlen(p_x_min));
	}
	else
		s = ft_new_p(p_x_min, flags->precision);
	if (flags->width != 0)
		len = ft_output_string_with_width(s, flags, (int)ft_strlen(s));
	else
		len = ft_output_string(s);
	free(s);
	return (len);
}

int	ft_output_pointer(t_print *flags, va_list arg)
{
	unsigned long	num;
	char			*p;
	int				length;

	num = va_arg(arg, unsigned long);
	p = conversion_p(num);
	if (flags->precision != 0)
		length = ft_output_p_with_precision(flags, p, num);
	if (flags->dot == 0 && flags->width != 0)
		length = ft_output_with_width(flags, p);
	if (flags->dot == 1 && flags->precision == 0)
	{
		if (num == 0)
			p = ft_p_null(p);
		length = ft_output_result_with_width(flags, p);
	}
	if (flags->dot == 0 && flags->width == 0)
		length = ft_output_without(p);
	free(p);
	return (length);
}
