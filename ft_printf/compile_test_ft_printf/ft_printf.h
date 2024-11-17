#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *, ...);
int ptr_to_hex(void *ptr, char spec, size_t *cnt);
void	dec_to_hex(int decimal_nbr, char spec, size_t *cnt);
void	printf_itoa(int n, size_t *cnt);
void	printf_putchar(char c, size_t *cnt);
void	printf_putstr(char *s, size_t *cnt);
void	printf_unsigned_itoa(int n, size_t *cnt);

#endif