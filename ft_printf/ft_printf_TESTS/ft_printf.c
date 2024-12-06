/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:15:29 by emonacho          #+#    #+#             */
/*   Updated: 2024/11/26 10:28:13 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_args(va_list args, char spec, size_t *cnt)
{
	if (spec == 'c')
		printf_putchar(va_arg(args, int), cnt);
	else if (spec == 's')
		printf_putstr(va_arg(args, char *), cnt);
	else if (spec == 'p')
		puthex_ptr(va_arg(args, void *), spec, cnt);
	else if (spec == 'd' || spec == 'i')
		printf_itoa(va_arg(args, int), cnt);
	else if (spec == 'u')
		printf_itoa_unsigned(va_arg(args, unsigned int), cnt);
	else if (spec == 'x' || spec == 'X')
		puthex(va_arg(args, int), spec, cnt);
	else if (spec == '%')
		printf_putchar('%', cnt);
}

int	specifier_check(char c)
{
	const char	*spec_list;
	int			i;

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

void	percent_check(va_list args, const char *format, size_t *i, size_t *cnt)
{
	if (format[*i] == '\0')
		return ;
	if (specifier_check(format[*i]))
		put_args(args, format[*i], cnt);
	else
	{
		printf_putchar('%', cnt);
		printf_putchar(format[*i], cnt);
	}
}

int	ft_printf(const char *format, ...)
{
	size_t	i;
	size_t	cnt;
	va_list	args;

	va_start (args, format);
	i = 0;
	cnt = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			percent_check(args, format, &i, &cnt);
		}
		else
			printf_putchar(format[i], &cnt);
		i++;
	}
	va_end(args);
	return ((int)cnt);
}
