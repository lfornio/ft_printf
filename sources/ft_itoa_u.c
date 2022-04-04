#include "../includes/ft_printf.h"

static unsigned int	delenie(unsigned int n)
{
	unsigned int	len;

	len = 0;
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	return (len + 1);
}

static char	*vivod(char *str, unsigned int nb, int i)
{
	while (nb >= 10)
	{
		str[i--] = nb % 10 + '0';
		nb = nb / 10;
	}
	str[i] = nb % 10 + '0';
	return (str);
}

char	*ft_itoa_u(unsigned int n)
{
	char	*str;
	int		i;
	int		dlina;

	dlina = delenie(n);
	str = (char *)malloc(sizeof(char) * (dlina + 1));
	if (str == NULL)
		return (NULL);
	i = dlina - 1;
	str = vivod(str, n, i);
	str[dlina] = '\0';
	return (str);
}
