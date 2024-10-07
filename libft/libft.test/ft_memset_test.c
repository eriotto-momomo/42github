#include <stdio.h>
#include <string.h>
/*
void	*ft_memset(void *b, int c, size_t len)
{
	int i;

	i = 0;
	while (str[i] != 
	{

	}
-tant que i n'est pas a la valeur indiquee, avance / dep
-quand i est au bon endroit, remplacer char par valeur X, Y fois
		 */
/*
-string / par ex. 'Hello World!'
-point de depart de la valeur a remplacer / par ex 4
-valeur a remplacer / par ex '.'
- *void b : C'est un pointeur générique vers une zone mémoire à remplir. En C, un void* peut pointer vers n'importe quel type de donnéesnombre de bytes a remplacer en partant du point de depart / par ex 6
*/

int	main(void)
{
	char str[50] = ("GeeksForGeeks is for programming geeks.");
	printf("\nBefore memset(): %s\n", str);

	memset(str + 13, '.', 8*sizeof(char));

	printf("After memset(): %s", str);
	return (0);
}
