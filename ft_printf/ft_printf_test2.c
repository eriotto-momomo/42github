#include <unistd.h>

int	main(void)
{
	void *p;

	write(1, &*p, 1);

	return (0);
}
