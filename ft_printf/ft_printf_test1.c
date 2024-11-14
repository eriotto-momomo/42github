/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_test1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:17:23 by emonacho          #+#    #+#             */
/*   Updated: 2024/11/09 19:57:42 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libft.h>
#include <stdarg.h>

int	ft_printf(const char *, ...);

int	check_spec(char spec) // check specifier after '%'
{
	size_t count; // ?????

	count = 0;
        if (spec == 'c')
			ft_putchar(va_arg(args, char));
        if (spec == 's')
            ft_putstr(va_arg(args, char *));
        if (spec == 'p')
			ptr_to_hex(va_arg(args, void *));
        if (spec == 'd' || spec == 'i')
			ft_itoa(va_arg(args, int));
        if (spec == 'u')
			unsigned_itoa(va_arg(args, unsigned int));
    	if (spec == 'x')
			dec_to_lowerhex(va_arg(args, int));
        if (spec == 'X')
			dec_to_upperhex(va_arg(args, int));
		if (spec == '%')
			write(1, '%', 1);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	va_start	(args, *format);
	size_t		i;

	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			check_spec(format[i + 1]); // check for specifier after '%'
		i++;
	}
}

/*
1. parcour la chaine
2. si tombe sur % -> fonction specificateur
3. en avancant dans la chaine -> fonction count
4. pour avoir count: count doit donc etre incremente dans specificateur et additionne a i
*/

/*
int	ft_printf(const char *format, ...)
{
	va_list		args;
	va_start	(args, *format);
	size_t		count;
	size_t		i;
	
	count = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
            if (format[i + 1] == 'c')
				ft_putchar(va_arg(args, char));
            if (format[i + 1] == 's')
                ft_putstr(va_arg(args, char *));
            if (format[i + 1] == 'p')
            if (format[i + 1] == 'd' || format[i + 1] == 'i')
				ft_itoa(va_arg(args, int));
            if (format[i + 1] == 'u')
            if (format[i + 1] == 'x')
				dec_to_hex(va_arg(args, int)); // to lower, faire deuxieme fonction 
            if (format[i + 1] == 'X') //to upper
				dec_to_hex(va_arg(args, int));
			if (format[i + 1] == '%')
				write(1, '%', 1);
		}
		else
			ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (0);
}
*/

/*
 * %c prints a single character
 * %s prints a string
 * %p the void * pointer has to be printed in hexadecimal format
 * %d prints a decimal (base 10) number
 * %i prints an integer in base 10
 * %u prints an unsigned decimal (base 10) number
 * %x prints a number in hexadecimal (base16) lowercase format
 * %X prints a number in hexadecimal (base 16) uppercase format
 * %% prints a percent sign 
 */