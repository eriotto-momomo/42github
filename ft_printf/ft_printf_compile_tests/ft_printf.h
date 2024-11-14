#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *, ...);
int dec_to_lowerhex(int decimal_nbr, size_t *cnt);
int dec_to_upperhex(int decimal_nbr, size_t *cnt);
void	printf_itoa(int n, size_t *cnt);
void	printf_putchar(char c, size_t *cnt);
void	printf_putstr(char *s, size_t *cnt);
void	printf_unsigned_itoa(int n, size_t *cnt);
int ptr_to_hex(void *ptr, size_t *cnt);

#endif