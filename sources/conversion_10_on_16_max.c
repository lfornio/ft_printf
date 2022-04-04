#include "../includes/ft_printf.h"

static int	lenght_x_max(unsigned int number)
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

char	*conversion_10_on_16_max(unsigned int number)
{
	char	*str;
	int		len;

	len = 0;
	len = lenght_x_max(number);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len] = '\0';
	len = len - 1;
	while (number >= 16 && len >= 0)
	{
		if (number % 16 >= 10 && number % 16 <= 15)
			str[len] = number % 16 + 55;
		else
			str[len] = number % 16 + '0';
		number = number / 16;
		len--;
	}
	if (number % 16 >= 10 && number % 16 <= 15)
		str[len] = number % 16 + 55;
	else
		str[len] = number % 16 + '0';
	return (str);
}
