#include "push_swap.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

// NE PAS OUBLIER DE REMPLACER PRINTF PAR FT_PRINTF !!!!!!!
// NE PAS OUBLIER DE REMPLACER AUTRES FONCTIONS PAR FT_* !!
// NE PAS OUBLIER DE SUPPRIMER LIBRAIRIE INUTILES !!!!!!!!!
// UTILISER LIBFT ET SUPPRIMER FONCTIONS EN TROP DANS UTILS

/*char	**ft_split(char const *s, char c);
static char	**splitword(const char *s, char c, char **s2, int num_word);
static char	*putword(char *word, const char *s, int i, int len_word);
static int	cnt_word(char const *str, char c);
static char	**free_array(char **ptr, int i);*/
int	ft_safe_atoi(const char *str, int *error);

int	ft_safe_atoi(const char *str, int *error)
{
	int			i;
	int			sign;
	long long	num;

	i = 0;
	num = 0;
	sign = 1;
	while (((str[i]) >= 9 && (str[i]) <= 13) || (str[i]) == 32)
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ((str[i] != '\0') && (str[i] >= '0') && (str[i] <= '9'))
	{
		num = num * 10 + (str[i++] - '0');
		if ((num * sign) < -2147483648 || (num * sign) > 2147483647)
			*error = -1;
	}
	num *= sign;
	return (num);
}
/*
static char	**free_array(char **ptr, int i)
{
	while (i > 0)
	{
		i--;
		free(ptr[i]);
	}
	free(ptr);
	return (0);
}

static int	cnt_word(char const *str, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			cnt++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (cnt);
}

static char	*putword(char *word, const char *s, int i, int len_word)
{
	int	j;

	j = 0;
	while (len_word > 0)
	{
		word[j] = s[i - len_word];
		j++;
		len_word--;
	}
	word[j] = '\0';
	return (word);
}

static char	**splitword(const char *s, char c, char **s2, int num_word)
{
	int	i;
	int	word;
	int	len_word;

	i = 0;
	word = 0;
	len_word = 0;
	while (word < num_word)
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			len_word++;
		}
		s2[word] = (char *)malloc((len_word + 1) * sizeof(char));
		if (s2[word] == 0)
			return (free_array(s2, word));
		putword(s2[word], s, i, len_word);
		len_word = 0;
		word++;
	}
	s2[word] = 0;
	return (s2);
}

char	**ft_split(char const *s, char c)
{
	char			**s2;
	unsigned int	num_word;

	if (s == 0)
		return (NULL);
	num_word = cnt_word(s, c);
	s2 = (char **)malloc((num_word + 1) * sizeof(char *));
	if (s2 == 0)
		return (NULL);
	s2 = splitword(s, c, s2, num_word);
	return (s2);
}*/