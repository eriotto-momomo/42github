#include <stdio.h>

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || ( c >= '0' && c <= '9') ? 1 : 0);
}

/*int main()
{
	char c;
	char result;

	c ='0';
	result = ft_isalpha(c);
	printf ("The result is %d\n", result);
	
	c ='9';
	result = ft_isalpha(c);
	printf ("The result is %d\n", result);
	
	c ='q';
	result = ft_isalpha(c);
	printf ("The result is %d\n", result);
	
	c ='K';
	result = ft_isalpha(c);
	printf ("The result is %d\n", result);
	
	c ='?';
	result = ft_isalpha(c);
	printf ("The result is %d\n", result);
	
	return (0);
}*/
