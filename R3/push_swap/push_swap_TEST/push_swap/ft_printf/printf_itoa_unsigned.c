/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_itoa_unsigned.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:27:51 by emonacho          #+#    #+#             */
/*   Updated: 2025/01/12 13:04:34 by emonacho         ###   ########.fr       */
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
