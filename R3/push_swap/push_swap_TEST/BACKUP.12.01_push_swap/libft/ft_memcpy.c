/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:31:38 by emonacho          #+#    #+#             */
/*   Updated: 2025/01/12 13:04:05 by emonacho         ###   ########.fr       */
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
