/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_putstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:28:41 by emonacho          #+#    #+#             */
/*   Updated: 2024/11/26 10:28:42 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
