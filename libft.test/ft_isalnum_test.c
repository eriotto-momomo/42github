#include <stdio.h>

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int main()
{
	char c;
	char result;

	c ='0';
	result = ft_isalnum(c);
	printf ("The result is %d\n", result);
	
	c ='9';
	result = ft_isalnum(c);
	printf ("The result is %d\n", result);
	
	c ='q';
	result = ft_isalnum(c);
	printf ("The result is %d\n", result);
	
	c ='K';
	result = ft_isalnum(c);
	printf ("The result is %d\n", result);
	
	c ='?';
	result = ft_isalnum(c);
	printf ("The result is %d\n", result);
	
	return (0);
}
