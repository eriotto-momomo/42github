#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char *buffer;

	buffer = (char*)calloc(BUFFER_SIZE + 1);
	if (buffer == 0)
		return (NULL);
}

/*
// si BUFFER_SIZE n'est pas défini à la compilation, lui donner une valeur par défaut
// ouvrir un fichier et gérer la lecture jusqu'au '\n'
// gérer les "restes" en cas de dépassement de '\n'
// libérer la mémoire

A. avec calloc alloue à "buffer" la taille définie par BUFFER_SIZE
B. lis "sample.txt" dans le "fd1" depuis "buffer" ---> read(buffer, &c, &i)
	Si buffer[i]:
	= '\n', stocke la suite de la prochaine ligne dans "remainder"
	= '\0', libère la mémoire allouée


1. lis TOUTE la taille du buffer et arrive a '\0'
- read() tout le contenu du buffer
- free les malloc
2. lis PARTIELLEMENT la taille du buffer et arrive a '\0'
- read() tout le contenu du buffer
- free les malloc

3. lis TOUTE la taille du buffer et arrive a '\n'
- read() tout le contenu du buffer
- controle le caractere suivant '\n':
	- si c'est un nouveau caractere

4. lis PARTIELLEMENT la taille du buffer et arrive a '\n'
- read() tout le contenu du buffer
- stocke le reste de la prochaine ligne dans remainder
*/
