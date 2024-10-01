#include <stdio.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i]) /*ou (str[i] != '/0')*/
	{
		i++;
	}
	return (i);
}

int main()
{
	char *str;
    int len;
	str = "Hello Worldgggggggggggggggggggggggggggggg !";
	len = ft_strlen(str); 
	ft_strlen(str);
    printf("La longueur de la chaîne est : %d\n", len);
	return (0);
}

/*RECURSIVE
int ft_strlen(char *str)
{
    if (*str == '\0')  // Cas de base : fin de la chaîne
        return 0;
    return 1 + ft_strlen(str + 1);  // Appel récursif en avançant d'un caractère
}*/
