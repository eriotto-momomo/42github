#include <stdio.h>

int	ft_isprint(int c)
{
	if ((c >= 0040 && c <= 0077) || (c >= 0100 && c <= 0176))
		return (1);
	else
		return (0);
}

int main()
{
	char c;
	char result;

	c = 15;
	result = ft_isprint(c);
	printf ("The result is %d\n", result);
	
	c ='a';
	result = ft_isprint(c);
	printf ("The result is %d\n", result);
		
	c = 0;
	result = ft_isprint(c);
	printf ("The result is %d\n", result);
				
	c = 26;
	result = ft_isprint(c);
	printf ("The result is %d\n", result);
			
	c ='A';
	result = ft_isprint(c);
	printf ("The result is %d\n", result);
		
	c ='0';
	result = ft_isprint(c);
	printf ("The result is %d\n", result);
	
	return (0);
}
