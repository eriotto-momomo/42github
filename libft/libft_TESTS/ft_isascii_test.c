#include <stdio.h>

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
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
