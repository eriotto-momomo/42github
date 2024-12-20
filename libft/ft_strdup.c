/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliotmonachon <eliotmonachon@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 11:50:00 by emonacho          #+#    #+#             */
/*   Updated: 2024/12/15 19:44:34 by eliotmonach      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*dst;

	i = 0;
	dst = (char *) malloc(ft_strlen(s1) + 1);
	if (dst == 0)
		return (NULL);
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}
