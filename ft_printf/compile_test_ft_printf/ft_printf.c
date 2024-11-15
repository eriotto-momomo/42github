/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:17:23 by emonacho          #+#    #+#             */
/*   Updated: 2024/11/14 19:31:45 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *, ...);

void	check_spec(va_list args, char spec, size_t *cnt) // check specifier after '%'
{
        if (spec == 'c')
			printf_putchar(va_arg(args, int), cnt);
        if (spec == 's')
           	printf_putstr(va_arg(args, char *), cnt);
        if (spec == 'p')
			ptr_to_hex(va_arg(args, void *), cnt);
        if (spec == 'd' || spec == 'i')
			printf_itoa(va_arg(args, int), cnt);
        if (spec == 'u')
			printf_unsigned_itoa(va_arg(args, unsigned int), cnt);
    	if (spec == 'x')
			dec_to_lowerhex(va_arg(args, int), cnt);
        if (spec == 'X')
			dec_to_upperhex(va_arg(args, int), cnt);
		if (spec == '%')
			printf_putchar(spec, cnt);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	va_start	(args, format);
	size_t		i;
	size_t		cnt;

	i = 0;
	cnt = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			check_spec(args, format[i], &cnt); // check for specifier after '%'
		}
		else
			printf_putchar(format[i], &cnt);
		i++;
	}
	va_end(args);
	return((int)cnt);
}