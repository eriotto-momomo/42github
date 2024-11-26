/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_itoa_REWORKED.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:28:26 by emonacho          #+#    #+#             */
/*   Updated: 2024/11/26 11:35:48 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count(int n)
{
	int	i;

	i = 2;
	if (n < 0)
	{
		i++;
		n = n * -1;
	}
	while (n > 9)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char		*itoa(int n)
{
	long	i;
	int		longueur;
	char	*str;

	i = n;
	if (n == -2147483648)
		write(1, "-2147483648", 12);
	longueur = count(n);
	if (!(str = (char *)malloc(sizeof(char) * longueur)))
		return (NULL);
	if (n < 0)
		n = n * (-1);
	str[--longueur] = '\0';
	while ((--longueur) >= 0)
	{
		str[longueur] = n % 10 + '0';
		n = n / 10;
	}
	if (i < 0)
		*str = '-';
	return (str);
}

void	printf_itoa(int n, size_t *cnt)
{
	char	*str;

	str = itoa(n);
	if (str != 0)
	{
		printf_putstr(str, cnt);
		free(str);
	}
}
