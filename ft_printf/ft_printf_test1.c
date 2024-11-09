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

int	ft_printf(const char *, ...)
{
	va_list		args;
	va_start	(args, *);
	size_t		count;
	size_t		i;
	
	count = 0;
	i = 0;
	while (*[i] != '\0')
	{
		if (*[i + 1] == '%')
		{
			conversion(*[i]);
		}
		else
			write(1, &*[i], 1);
		count++;
		i++;
	}
	va_end(args);
	return (0);
}

int	conversion(char c)
{
	if (c + 1 =
}

// write(1, &va_arg, 1) ???

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
