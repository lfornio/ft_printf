#include "../includes/ft_printf.h"

static int	lenght_pointer(unsigned long number)
{
	int	lenght;

	lenght = 0;
	while (number >= 16)
	{
		number = number / 16;
		lenght++;
	}
	return (lenght + 1);
}

char	*conversion_p(unsigned long number)
{
	char	*str;
	int		len;

	len = lenght_pointer(number) + 2;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len] = '\0';
	len--;
	while (number >= 16 && len > 0)
	{
		if (number % 16 >= 10 && number % 16 <= 15)
			str[len] = number % 16 + 87;
		else
			str[len] = number % 16 + '0';
		number = number / 16;
		len--;
	}
	if (number % 16 >= 10 && number % 16 <= 15)
		str[len] = number % 16 + 87;
	else
		str[len] = number % 16 + '0';
	str[1] = 'x';
	str[0] = '0';
	return (str);
}
