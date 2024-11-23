#include <stdio.h>
#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	*ptr = b;
	while (len-- > 0)
		*ptr++ = c;
	return (b);
}

/* 	ALTERNATIVE PLUS CLAIRE
void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)b;
	while (i < len)
		ptr[i++] = (unsigned char)c;
	return (b);
}
*/

int	main(void)
{
	char str[50] = ("GeeksForGeeks is for programming geeks.");
	printf("\nBefore memset(): %s\n", str);

	ft_memset(str + 13, '.', 8*sizeof(char));

	printf("After memset(): %s", str);
	return (0);
}
/*
 * void * : Le type de retour est un pointeur générique (void *), ce qui signifie qu'il peut pointer vers n'importe quel type de données.
 * b : Un pointeur vers le bloc de mémoire à remplir.
 * c : La valeur (un entier) à laquelle on veut remplir la mémoire. Notez que seul le byte inférieur de c sera utilisé, car la mémoire est remplie byte par byte.
 * len : La taille du bloc de mémoire à remplir (en bytes).
 * On déclare un pointeur ptr de type unsigned char * qui est initialisé à la valeur de b. On convertit b en unsigned char * parce que la fonction travaille au niveau des bytes (octets).
 * len-- > 0 : On boucle tant que len est strictement supérieur à 0. À chaque itération, la valeur de len est décrémentée après avoir vérifié la condition. Cela permet de parcourir les len bytes de la mémoire.
* ptr++ = c : On affecte la valeur de c au byte pointé par ptr, puis on incrémente ptr pour passer à l'adresse suivante dans le bloc de mémoire.
*
*
*D'accord ! Imagine que tu as un gros cahier avec plein de pages blanches, et tu veux colorier toutes les pages avec la même couleur, disons du bleu. Mais au lieu de le faire à la main, tu utilises un robot qui peut remplir chaque page pour toi.

Maintenant, voici comment fonctionne le code que tu as montré :

    Le cahier : C'est un peu comme une zone de mémoire (un endroit où l'ordinateur stocke des choses). Le cahier a plusieurs pages, tout comme la mémoire a plusieurs "cases".

    Le robot : Le robot est la fonction ft_memset. C'est elle qui va s'occuper de remplir les pages de ton cahier (la mémoire).

    La couleur bleue : C'est la valeur que tu veux mettre dans toutes les pages. Dans le code, cette couleur est le nombre (ici, le nombre c), mais il est transformé en petites cases (des octets).

    Combien de pages à colorier ? : len est le nombre de pages (ou de cases de mémoire) que tu veux remplir avec ta couleur.

Voici comment le robot travaille :

    Il commence à la première page du cahier (la première case de mémoire).
    Il colorie la page avec du bleu (ou la valeur donnée).
    Ensuite, il passe à la page suivante et fait la même chose, encore et encore, jusqu'à avoir colorié toutes les pages demandées.

À la fin, toutes les pages que tu as demandées sont coloriées en bleu, et tu récupères ton cahier rempli.

En gros, c'est comme si tu disais au robot : "Va remplir toutes ces pages avec du bleu" et le robot le fait, une page après l'autre !

C'est exactement ce que fait la fonction ft_memset : elle remplit un endroit en mémoire avec une même valeur, de manière automatique.
*/
