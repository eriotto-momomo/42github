#include <stdio.h>

int	ft_isascii(int c)
{
	return ((c >= 0 && c <= 127) ? 1 : 0);
}

int main()
{
	char c;
	char result;

	c ='8';
	result = ft_isascii(c);
	printf ("The result is %d\n", result);
	
	c =' ';
	result = ft_isascii(c);
	printf ("The result is %d\n", result);
		
	c ='	';
	result = ft_isascii(c);
	printf ("The result is %d\n", result);
	
	return (0);
}
