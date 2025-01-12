/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_itoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:28:26 by emonacho          #+#    #+#             */
/*   Updated: 2025/01/12 13:04:36 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_itoa(int n, size_t *cnt)
{
	char	*str;

	if (n == -2147483648)
	{
		printf_putstr("-2147483648", cnt);
		return ;
	}
	else if (n < 0)
	{
		n = -n;
		printf_putchar('-', cnt);
	}
	str = itoa(n);
	if (str != 0)
		printf_putstr(str, cnt);
	free(str);
}
