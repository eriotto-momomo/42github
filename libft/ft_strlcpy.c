/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:00:57 by emonacho          #+#    #+#             */
/*   Updated: 2024/10/10 19:57:02 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	pos;

	pos = 0;
	if (dstsize < 1)
		return (0);
	dstsize--;
	while ((pos < dstsize) && (*src))
	{
		dst[pos++] = *src;
		src++;
	}
	dst[pos] = 0;
	return (pos);
}
