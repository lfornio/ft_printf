#include "../includes/ft_printf.h"

void	ft_output_string_right(t_print *flags, char *s)
{
	int	i;
	int	len;

	i = 0;
	len = (int)ft_strlen(s);
	while (s && (i < (flags->width - len)))
	{
		write(1, " ", 1);
		i++;
	}
	ft_putstr_fd(s, 1);
}

void	ft_output_string_left(t_print *flags, char *s)
{
	int	i;

	i = 0;
	ft_putstr_fd(s, 1);
	while (i < (flags->width - (int)ft_strlen(s)))
	{
		write(1, " ", 1);
		i++;
	}
}

void	ft_output_string_zero(t_print *flags, char *s)
{
	int	i;

	i = 0;
	while (i < (flags->width - (int)ft_strlen(s)))
	{
		write(1, "0", 1);
		i++;
	}
	ft_putstr_fd(s, 1);
}

int	ft_output_string(char *s)
{
	int	lenght;

	ft_putstr_fd(s, 1);
	lenght = (int)ft_strlen(s);
	return (lenght);
}

int	ft_output_string_with_width(char *s, t_print *flags, int len)
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
			ft_output_string_zero(flags, s);
		lenght = flags->width;
	}
	return (lenght);
}
