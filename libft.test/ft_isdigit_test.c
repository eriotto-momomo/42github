#include <stdio.h>

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int main()
{
	char c;
	char result;

	c ='8';
	result = ft_isdigit(c);
	printf ("The result is %d\n", result);
	
	c ='y';
	result = ft_isdigit(c);
	printf ("The result is %d\n", result);
	
	c ='}';
	result = ft_isdigit(c);
	printf ("The result is %d\n", result);
	
	c ='3';
	result = ft_isdigit(c);
	printf ("The result is %d\n", result);
	
	c ='A';
	result = ft_isdigit(c);
	printf ("The result is %d\n", result);
	
	return (0);
}
