#include "../includes/ft_printf.h"

int	ft_found_type(const char *str, int i)
{
	if (str[i] == 'c' || str[i] == 's' || str[i] == 'p' || str[i] == 'd'
		|| str[i] == 'i' || str[i] == 'u' || str[i] == 'x' || str[i] == 'X'
		|| str[i] == '%')
		return (1);
	else
		return (0);
}

static int	ft_output_with_width_x(t_print *flags, char *str)
{
	char	*s;
	int		len;

	s = ft_substr(str, 0, (int)ft_strlen(str));
	len = ft_output_digit_with_width(s, flags, (int)ft_strlen(s));
	free(s);
	return (len);
}

static char	*ft_new_s_p(char *str, int flag)
{
	char	*s;
	int		i;
	int		j;

	i = 0;
	j = 0;
	s = malloc(sizeof(char) * (flag + 1));
	if (s == NULL)
		return (NULL);
	while (i < flag)
	{
		while (i < (flag - (int)ft_strlen(str)))
		{
			s[i] = ' ';
			i++;
		}
		s[i] = str[j];
		i++;
		j++;
	}
	s[i] = '\0';
	return (s);
}

int	ft_output_result_with_width(t_print *flags, char *str)
{
	char	*s;
	int		length;

	if (flags->width >= (int)ft_strlen(str))
	{
		if (flags->zero == 1)
		{
			if (flags->dot != 1)
				s = ft_new_string(str, flags->width);
			else
				s = ft_new_s_p(str, flags->width);
			length = ft_output_string(s);
			free(s);
		}
		else
			length = ft_output_with_width_x(flags, str);
	}
	else
		length = ft_output_string(str);
	return (length);
}

char	*ft_new_string(char *str, int flag)
{
	char	*s;
	int		i;
	int		j;

	i = 0;
	j = 0;
	s = malloc(sizeof(char) * (flag + 1));
	if (s == NULL)
		return (NULL);
	while (str[j] && (i < flag))
	{
		while (i < (flag - (int)ft_strlen(str)))
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
