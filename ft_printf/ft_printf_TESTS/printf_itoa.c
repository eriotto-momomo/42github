/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_itoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:28:26 by emonacho          #+#    #+#             */
/*   Updated: 2024/11/26 11:36:44 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_itoa(int n, size_t *cnt)
{
	char	*str;
	if (n == -2147483648)
		printf_putstr("-2147483648", cnt);
	else if (n < 0)
	{
		n = -n;
		printf_putchar('-', cnt);
	}
	str = itoa(n);
	if (str != 0)
	{
		printf_putstr(str, cnt);
		free(str);
	}
}
