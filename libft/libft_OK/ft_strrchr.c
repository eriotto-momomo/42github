/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:06:20 by emonacho          #+#    #+#             */
/*   Updated: 2024/10/20 13:46:47 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			i;
	unsigned char	cc;
	char			*res;

	i = 0;
	res = 0;
	cc = (unsigned char)c;
	while (s[i])
	{
		if ((unsigned char)s[i] == cc)
			res = ((char *)&s[i]);
		i++;
	}
	if ((unsigned char)s[i] == cc)
		res = ((char *)&s[i]);
	return (res);
}
