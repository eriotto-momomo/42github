/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthex_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:28:52 by emonacho          #+#    #+#             */
/*   Updated: 2024/11/26 12:55:03 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_ptr(void *ptr, char spec, size_t *cnt)
{
	unsigned long long	castptr; //`long long` garantit la portabilité

	castptr = (unsigned long long)ptr;
	if (ptr == 0)
		printf_putstr("0x0", cnt);
	else
	{
		printf_putstr("0x", cnt);
		puthex_ptr(castptr, spec, cnt);
	}
	return (0);
}
