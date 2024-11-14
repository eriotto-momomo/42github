#include "libft.h"

static int	cntdigits(unsigned int nbr)
{
	size_t	digits;

	if (nbr == 0)
		return (1);
	digits = 0;
	while (nbr >= 1)
	{
		nbr /= 10;
		digits++;
	}
	return (digits);
}

char	*unsigned_itoa(unsigned int n)
{
	char			*str;
	unsigned int	nbr;
	unsigned int	digits;

    nbr = n;
	digits = cntdigits(nbr);
	str = (char *)malloc(digits + 1);
	if (str == 0)
		return (NULL);
	str[digits] = '\0';
	while (digits > 0)
	{
		str[(digits - 1)] = (nbr % 10) + '0';
		nbr /= 10;
		digits--;
	}
	return (str);
}