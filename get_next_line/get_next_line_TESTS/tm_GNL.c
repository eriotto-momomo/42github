#include "get_next_line.h"

char *store_remainder(char *str)
{
	size_t i;
	char *remainder;
	size_t len;

	i = 0;
	len = ft_strlen(str);
	remainder = (char*)ft_calloc(len + 1, sizeof(char));
	if (remainder == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			printf("\n2# NEXTLINE reached!\n");
			break;
		}
		remainder[i] = str[i];
		i++;
	}
	// printf("1# NEXTLINE is: %s\n", remainder);
	return (remainder);
}

char read_buffer(char *str)
{
	size_t i;
	static char *remainder;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i+1] == '\0')
			printf("'null-terminated'\n");
		else if (str[i+1] == '\n')
		{
			remainder = store_remainder(&str[i+2]); // stock ce qui est après '\n'
			break;
		}
		i++;
	}
	printf("1# NEXTLINE is: %s\n", remainder);
	return (0);
}

char *get_next_line(int fd)
{
	int bytes_read;
	static char *buffer;

	buffer = ft_calloc(17 + 1, sizeof(char));
	if (buffer == NULL) // si allocation échoue
		return (NULL);
	bytes_read = read(fd, buffer, 17); // lis les char
	read_buffer(buffer);
	if (bytes_read <= 0) // STOP si la fonction read ne lis rien
		return (NULL);
	return (buffer);
}
