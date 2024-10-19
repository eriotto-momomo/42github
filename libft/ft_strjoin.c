/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 11:52:28 by emonacho          #+#    #+#             */
/*   Updated: 2024/10/19 11:57:34 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cat;
	int		i;
	int		j;

	i = 0;
	j = 0;
	cat = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (cat == 0)
		return (NULL);
	while (s1[i])
		cat[j++] = s1[i++];
	i = 0;
	while (s2[i])
		cat[j++] = s2[i++];
	cat[j] = '\0';
	return (cat);
}
