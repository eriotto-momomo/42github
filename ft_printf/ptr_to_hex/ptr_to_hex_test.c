#include <unistd.h>

void reverse_string(char *str, int len)
{
    int start = 0;
    int end = len - 1;
    char tmp;

    while (start < end)
    {
        tmp = str[start];
        str[start] = str[end];
        str[end] = tmp;
        start++;
        end--;
    }
}

char	*hexa_conversion(unsigned long long ptr)
{
	int		    tmp;
	int		    i;
	static char hexa_ptr[100];

	i = 0;

    if (ptr == 0)
        hexa_ptr[i] = '0';
    else
    {
	    while (ptr != 0)
        {
		    tmp = ptr % 16;
		    if (tmp < 10)
			    hexa_ptr[i] = tmp + '0';
    		else
	    		hexa_ptr[i] = tmp + 'a' - 10; // lower case
		    i++;
		    ptr /= 16;
	    }
    }
    hexa_ptr[i] = '\0';
    reverse_string(hexa_ptr, i);
    return (hexa_ptr);
}

int ptr_to_hex(void *ptr) // ptr to [lower]case hexadecimal
{ 
    unsigned long long  castptr;
    char    *hexa_ptr;
    int     i;

    ptr = (unsigned long long)castptr;
    hexa_ptr = hexa_conversion(castptr);
    i = 0;
    while (hexa_ptr[i] != 0)
    {
        write(1, &hexa_ptr[i], 1);
        i++;
    }
    write(1, "\n", 1);
    return(0);
}

int main(void)
{
    int a;
    void *ptr;

    a = 10;
    ptr = &a;
    ptr_to_hex(ptr);
    return (0);
}