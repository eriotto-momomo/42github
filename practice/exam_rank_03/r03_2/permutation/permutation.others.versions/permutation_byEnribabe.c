/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_practice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 16:37:40 by emurillo          #+#    #+#             */
/*   Updated: 2025/05/29 16:57:46 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void sort_str(char *s, int len)
{
	int		i;
	int		swapped;
	char	tmp;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (i < len - 1)
		{
			if (s[i] > s[i + 1])
			{
				tmp = s[i];
				s[i] = s[i + 1];
				s[i + 1] = tmp;
				swapped = 1;
			}
			i++;
		}
	}
}

void init_arr(int *arr, char *res, int len)
{
	int	i;

	i = 0;
	if (!res || !arr)
		return ;
	while (i < len)
	{
		arr[i] = 0;
		i++;
	}
	res[0] = '\0';
}

void	permutation(char *sorted, int *used, char *res, int len, int pos)
{
	int	i;

	if (pos == len)
	{
		res[pos] = '\0';
		puts(res);
		return ;
	}
	i = 0;
	while (i < len)
	{
		if (used[i] == 0)
		{
			if (!(i > 0 && sorted[i] == sorted[i - 1] && used[i - 1] == 0))
			{
				res[pos] = sorted[i];
				used[i] = 1;
				permutation(sorted, used, res, len, pos + 1);
				used[i] = 0;
			}
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int		len;
	char	*res;
	int		*used;

	if (ac != 2 || av[1][0] == '\0')
		return (puts("error: invalid args.\n"), 2);
	len = ft_strlen(av[1]);
	res = malloc(sizeof(char) * len + 1);
	used = malloc(sizeof(int) * len);
	if (!res || !used)
		return (puts("Error: malloc allocation"), 1);
	init_arr(used, res, len);
	sort_str(av[1], len);
	permutation(av[1], used, res, len, 0);
	free(res);
	free(used);
	return (0);
}
