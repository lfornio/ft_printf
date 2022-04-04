#include "../includes/ft_printf.h"

static int	ft_output_with_precision(t_print *flags, char *str)
{
	int		len;
	char	*s;

	if (flags->precision < (int)ft_strlen(str))
		s = ft_substr(str, 0, flags->precision);
	else
		s = ft_substr(str, 0, (int)ft_strlen(str));
	if (flags->width != 0)
		len = ft_output_string_with_width(s, flags, ft_strlen(s));
	else
		len = ft_output_string(s);
	free(s);
	return (len);
}

static int	ft_output_with_dot(t_print *flags)
{
	char	*s;
	int		len;
	int		i;

	i = 0;
	if (flags->width != 0)
	{
		s = malloc(sizeof(char) * (flags->width + 1));
		if (s == NULL)
			return (0);
		while (i < flags->width)
		{
			s[i] = ' ';
			i++;
		}
		s[i] = '\0';
		ft_putstr_fd(s, 1);
		len = (int)ft_strlen(s);
		free(s);
	}
	else
		len = 0;
	return (len);
}

int	ft_output_s(t_print *flags, va_list arg)
{
	char	*str;
	int		len;

	str = va_arg(arg, char *);
	if (!str)
		str = "(null)";
	if (flags->precision != 0)
		len = ft_output_with_precision(flags, str);
	if (flags->dot == 1 && flags->precision == 0)
		len = ft_output_with_dot(flags);
	if (flags->dot == 0 && flags->width != 0)
		len = ft_output_with_width(flags, str);
	if (flags->dot == 0 && flags->width == 0)
		len = ft_output_without(str);
	return (len);
}
