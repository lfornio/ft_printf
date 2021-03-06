#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const unsigned char	*src2;
	unsigned char		*dst2;
	size_t				i;

	i = 0;
	if (dst == src || n == 0)
		return (dst);
	src2 = (const unsigned char *)src;
	dst2 = (unsigned char *)dst;
	while (n)
	{
		dst2[i] = src2[i];
		i++;
		n--;
	}
	return (dst);
}
