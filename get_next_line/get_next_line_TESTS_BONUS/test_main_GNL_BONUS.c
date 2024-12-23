#include "get_next_line_bonus.h"


int main(void)
{
	int 	fd;
	int		fd1;
	int		fd2;
	int		fd3;
	char	*next_line1;
	char	*next_line2;
	char	*next_line3;

	fd = open("sample.txt", O_RDONLY);
	fd1 = open("1.txt", O_RDONLY);
	fd2 = open("2.txt", O_RDONLY);
	fd3 = open("3.txt", O_RDONLY);

	while (1)
	{
		next_line1 = get_next_line(fd1);
		if (next_line1 == NULL)
			break;
		printf("[%s]\n", next_line1);
		next_line2 = get_next_line(fd2);
		if (next_line2 == NULL)
			break;
		printf("[%s]\n", next_line2);
		next_line3 = get_next_line(fd3);
		if (next_line3 == NULL)
			break;
		printf("[%s]\n", next_line3);

	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
