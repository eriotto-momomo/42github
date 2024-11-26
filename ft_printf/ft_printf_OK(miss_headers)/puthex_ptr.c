/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthex_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:28:52 by emonacho          #+#    #+#             */
/*   Updated: 2024/11/26 10:29:22 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*hex_conversion(unsigned long long ptr, size_t *cnt)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (ptr > 15)
		hex_conversion(ptr / 16, cnt);
	printf_putchar(hex[ptr % 16], cnt);
	return (0);
}

int	puthex_ptr(void *ptr, char spec, size_t *cnt)
{
	unsigned long long	castptr;

	castptr = (unsigned long long)ptr;
	if (ptr == 0)
		printf_putstr("(nil)", cnt);
	else
	{
		printf_putstr("0x", cnt);
		hex_conversion(castptr, cnt);
	}
	return (0);
}
