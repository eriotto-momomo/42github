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
// Affiche le specificateur avec la fonction correspondante.
void	put_args(va_list args, char spec, size_t *cnt)
{
        if (spec == 'c')
			printf_putchar(va_arg(args, int), cnt);
        else if (spec == 's')
           	printf_putstr(va_arg(args, char *), cnt);
        else if (spec == 'p')
			ptr_to_hex(va_arg(args, void *), cnt);
        else if (spec == 'd' || spec == 'i')
			printf_itoa(va_arg(args, int), cnt);
        else if (spec == 'u')
			printf_unsigned_itoa(va_arg(args, unsigned int), cnt);
    	else if (spec == 'x')
			dec_to_lowerhex(va_arg(args, int), cnt);
        else if (spec == 'X')
			dec_to_upperhex(va_arg(args, int), cnt);
        else if (spec == '%')
			printf_putchar('%', cnt);
}

int	specifier_check(char c)// specifier_check: Controle si le caractere
{			//suivant `%` correspond a un specificateur de conversion.
	const char *spec_list; // specifiers list
	int i;
	
	spec_list = "cspdiuxX%";
	i = 0;
	while (spec_list[i] != '\0')
	{
		if (c == spec_list[i])
			return (1);
		i++;
	}
	return (0);
}

void percent_check(va_list args, const char *format, size_t *i, size_t *cnt)
{// percent_check: Decide du comportement a adopter a la suite d'un `%`.
	if (format[*i] == '\0')
		return;
	if (specifier_check(format[*i])) // Controle si le spec est dans la liste. 
		put_args(args, format[*i], cnt); 	// Affiche l'argument du spec et execute
	else									// execute la fonction correspondante.
	{
		printf_putchar('%', cnt);
		printf_putchar(format[*i], cnt);
	}
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
			i++; // avance et decide de la suite apres avoir rencontre ce `%`
			percent_check(args, format, &i, &cnt); 
		}
		else
			printf_putchar(format[i], &cnt);
		i++;
	}
	va_end(args);
	return((int)cnt);
}