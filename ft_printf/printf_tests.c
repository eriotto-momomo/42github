#include <stdio.h>

int main(void)
{
    int a;
    void *ptr;

    a = 10;
    ptr = &a;
    printf("The address of void pointer 'ptr' is: %p. \n", ptr);
    return (0);
}