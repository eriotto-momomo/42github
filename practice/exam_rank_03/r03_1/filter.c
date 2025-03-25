#include <fcntl.h>
#include <stdio.h>
#include <unsitd.h>

#define BUFFER_SIZE 8192

void	replace_str(char *buffer, const char *target, char replace_char)
{
	size_t	i;

	i = 0, j, target_len;
	i = 0, j, target_len = 0;
	// Calculer la longueur de target (sans utiliser strlen)
	while (target[target_len] != '\0')
	{
		target_len++;
	}
	// Parcourir le buffer
	while (buffer[i] != '\0')
	{
		// Vérifier si on trouve une occurrence de target
		j = 0;
		while (buffer[i + j] == target[j] && target[j] != '\0')
		{
			j++;
		}
		// Si on a trouvé une occurrence complète, on remplace
		if (j == target_len)
		{
			for (size_t k = 0; k < target_len; k++)
			{
				buffer[i + k] = replace_char;
			}
			i += target_len - 1;
			// Avancer pour éviter de remplacer partiellement une occurrence
		}
		i++;
	}
}

int	main(int ac, char *av[])
{
	int			fd;
	char		*buffer;
	const char	*filename;
	const char	*target;
	ssize_t		bytes_read;

	fd = 0;
	bytes_read = 0;
	if (ac != 2)
	{
		printf("Error! Invalid arguments.\n");
		exit(1);
	}
	// Alloue le buffer et ouvre le fichier en lecture seule.
	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (buffer == NULL)
		exit(1);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file.\n");
		exit(1);
	}
	// Lis le fichier dans un buffer
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
	{
		printf("Error while reading file.\n");
		if (buffer != NULL)
			free(buffer);
		close(fd);
		exit(1);
	}
	buffer[bytes_read] = '\0';
	close(fd);
	// Modifier le contenu
	replace_str(buffer, target, '*');
	// Réouvrir en écriture et écraser le contenu
	fd = open(filename, O_WRONLY | O_TRUNC);
	if (fd == -1)
	{
		perror("Erreur réouverture fichier");
		return (EXIT_FAILURE);
	}
	// Écrire le contenu modifié
	if (write(fd, buffer, bytes_read) == -1)
	{
		perror("Erreur écriture fichier");
		close(fd);
		return (EXIT_FAILURE);
	}
	close(fd);
	printf("Remplacement terminé.\n");
	return (EXIT_SUCCESS);
}
