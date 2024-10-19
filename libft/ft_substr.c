/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:09:16 by emonacho          #+#    #+#             */
/*   Updated: 2024/10/19 12:10:19 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;

	i = 0;
	if (s == 0)
		return (NULL);
	dst = (char *)malloc((len + 1) * sizeof(char));
	if (dst == 0)
		return (NULL);
	if (s != 0)
	{
		while (i < len)
		{
			dst[i] = s[start + i];
			i++;
		}
	}
	dst[i] = '\0';
	return (dst);
}
