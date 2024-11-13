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
#include <stdarg.h>

int	ft_printf(const char *, ...);

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
            if (format[i + 1] == 'X')
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

// conversion dec to hexadec
// 1453/16 = 90,8125
// You take the number before the comma and you have 0,8125. 0,8125 * 16 = 13. So the remainder is 13

int	conversion(int decimal_nbr)
{
	int		tmp;
	int		i;
	char	hexa_nbr[100];

	i = 0;
	while (decimal_nbr != 0)
		{
			tmp = decimal_nbr % 16;
			if (tmp < 10)
				tmp += 48;
			else
				tmp += 55;
			hexa_nbr[i] = tmp;
			i++;
			decimal_nbr /= 16;
		}
}

char	write_hex(int hex)
{
	if (hex >= 0 && hex <= 9)
		ft_itoa(hex);
	if (hex == 10)
		write(1 , 'a', 1);
	if (hex == 11)
		write(1 , 'b', 1);
	if (hex == 12)
		write(1 , 'c', 1);
	if (hex == 13)
		write(1 , 'd', 1);
	if (hex == 14)
		write(1 , 'e', 1);
	if (hex == 15)
		write(1 , 'f', 1);
	return (0);
}

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

/*
 * WHILE (const char*[i] =! '\0')
 * 	IF [i] est un char imprimable 
 * 		IF %c -> write(1, &c, 1)
 * 		IF %s -> ft_putstr
 * 		IF %p the void * pointer has to be printed in hexadecimal format
 * 		IF %d -> write(1, &c, 1)
 * 		IF %i -> ft_itoa
 * 		IF %u prints an unsigned decimal (base 10) number
 * 		IF %x prints a number in hexadecimal (base16) lowercase format
 * 		IF %X prints a number in hexadecimal (base 16) uppercase format
 * 		IF %% -> write(1, "%", 1)
 * 	ELSE
 * 		write(1, &i, 1)
 * 	i++ 
 */

// 1. prend une chaine de caracteres et X arguments variables en parametres
// 2. ecrit la chaine tant que la chaine n'est pas \0
// 3. des qu'il trouve un specificateur %* le traite en consequence
