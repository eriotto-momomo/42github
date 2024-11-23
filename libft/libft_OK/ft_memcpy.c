/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:31:38 by emonacho          #+#    #+#             */
/*   Updated: 2024/10/20 13:38:10 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char			*ptr_dst;
	const unsigned char		*ptr_src;

	ptr_dst = dst;
	ptr_src = src;
	if (ptr_dst == 0 && ptr_src == 0)
		return (NULL);
	while (n > 0)
	{
		*ptr_dst++ = *ptr_src++;
		n--;
	}
	return (dst);
}
