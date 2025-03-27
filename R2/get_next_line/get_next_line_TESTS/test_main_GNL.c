#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*next_line;
	int		count;

	count = 0;
	fd = open("txt.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file");
		return (1);
	}
	/*else
	{
		next_line = get_next_line(fd);
		printf("[%d]:%s\n", count, next_line);
			//count is to show you the line numbers
		free(next_line);
	}*/
	while (1)
	{
		next_line = get_next_line(fd);
		if (next_line == NULL)
			break ;
		count++;
		printf("[%d]:%s\n", count, next_line);
			// count is to show you the line numbers
		free(next_line);
		next_line = NULL;
	}
	free(next_line);
	close(fd);
	return (0);
}
