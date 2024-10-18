/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:42:35 by emonacho          #+#    #+#             */
/*   Updated: 2024/10/10 18:44:14 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*ptr_dst;
	const unsigned char	*ptr_src;

	ptr_dst = dst;
	ptr_src = src;
	if (ptr_dst <= ptr_src)
	{
		while (len-- > 0)
			*ptr_dst++ = *ptr_src++;
	}
	else if (dst > src)
	{
		ptr_dst += len - 1;
		ptr_src += len - 1;
		while (len-- > 0)
			*ptr_dst-- = *ptr_src--;
	}
	return (dst);
}
