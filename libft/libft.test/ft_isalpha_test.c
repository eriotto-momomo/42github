#include <stdio.h>

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ? 1 : 0);
}

/*int main()
{
	char c;
	char result;

	c ='#';
	result = ft_isalpha(c);
	printf ("The result is %d\n", result);
	
	c ='A';
	result = ft_isalpha(c);
	printf ("The result is %d\n", result);
	
	c ='Z';
	result = ft_isalpha(c);
	printf ("The result is %d\n", result);
	
	c ='?';
	result = ft_isalpha(c);
	printf ("The result is %d\n", result);

	c ='2';
	result = ft_isalpha(c);
	printf ("The result is %d\n", result);
	
	c ='s';
	result = ft_isalpha(c);
	printf ("The result is %d\n", result);
		
	c ='o';
	result = ft_isalpha(c);
	printf ("The result is %d\n", result);

	return (0);
}*/
