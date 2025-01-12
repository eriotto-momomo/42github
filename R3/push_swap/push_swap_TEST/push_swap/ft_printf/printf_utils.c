/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:09:12 by emonacho          #+#    #+#             */
/*   Updated: 2025/01/12 13:04:38 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		cntdigits(unsigned int nbr);
char	*itoa(unsigned int n);
void	printf_putchar(char c, size_t *cnt);
void	printf_putstr(char *s, size_t *cnt);
void	puthex_dec(unsigned int to_convert, char spec, size_t *cnt);

void	printf_putchar(char c, size_t *cnt)
{
	write(1, &c, 1);
	(*cnt)++;
}

void	printf_putstr(char *s, size_t *cnt)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		printf_putstr("(null)", cnt);
		return ;
	}
	else
	{
		while (s[i] != '\0')
		{
			printf_putchar(s[i], cnt);
			i++;
		}
	}
}

void	puthex_dec(unsigned int to_convert, char spec, size_t *cnt)
{
	char	*hex;

	if (spec == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (to_convert > 15)
		puthex_dec(to_convert / 16, spec, cnt);
	printf_putchar(hex[to_convert % 16], cnt);
}

int	cntdigits(unsigned int nbr)
{
	size_t	digits;

	if (nbr == 0)
		return (1);
	digits = 0;
	while (nbr >= 1)
	{
		nbr /= 10;
		digits++;
	}
	return (digits);
}

char	*itoa(unsigned int n)
{
	char			*str;
	unsigned int	nbr;
	unsigned int	digits;

	nbr = n;
	digits = cntdigits(nbr);
	str = (char *)malloc(digits + 1);
	if (str == 0)
		return (NULL);
	str[digits] = '\0';
	while (digits > 0)
	{
		str[(digits - 1)] = (nbr % 10) + '0';
		nbr /= 10;
		digits--;
	}
	return (str);
}
