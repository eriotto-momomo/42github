/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_itoa_unsigned.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:27:51 by emonacho          #+#    #+#             */
/*   Updated: 2024/12/12 14:34:42 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_itoa_unsigned(unsigned int n, size_t *cnt)
{
	char	*str;

	str = itoa(n);
	if (str != 0)
		printf_putstr(str, cnt);
	free(str);
}
