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
    int         tmp;
	static char hexa_ptr[100];
    int         i;
	
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
    char                *hexa_ptr;
    char                *str
    int                 i;

    castptr = (unsigned long long)ptr;
    hexa_ptr = hexa_conversion(castptr);
    str = "0x";
    i = 0;
    printf_putstr(str);
    while (hexa_ptr[i] != 0)
    {
        printf_putstr(hexa_ptr, cnt);
    }
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