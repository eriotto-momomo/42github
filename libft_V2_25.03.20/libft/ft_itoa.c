/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 11:28:29 by emonacho          #+#    #+#             */
/*   Updated: 2025/03/11 18:26:08 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	isnegative(int n)
{
	if (n < 0)
		return (1);
	else
		return (0);
}

static int	cntdigits(unsigned int nbr)
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

char	*ft_itoa(int n)
{
	char			*str;
	int				sign;
	unsigned int	nbr;
	unsigned int	digits;

	sign = isnegative(n);
	if (sign)
		nbr = -n;
	else
		nbr = n;
	digits = cntdigits(nbr);
	str = (char *)malloc(digits + sign + 1);
	if (str == 0)
		return (NULL);
	if (sign == 1)
		str[0] = '-';
	str[digits + sign] = '\0';
	while (digits > 0)
	{
		str[(digits - 1) + sign] = (nbr % 10) + '0';
		nbr /= 10;
		digits--;
	}
	return (str);
}
