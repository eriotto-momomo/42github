#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

int *push_swap(int argc, char *argv[]);
int	format_check(char **array, int i);
int array_conversion(int size, int start, char **str_array, int *int_array);
int	arg_is_valid(int size, char **str_array);
void *free_int_or_str_array(void *array, int type, int size);
char	**ft_split(char const *s, char c);
static char	**splitword(const char *s, char c, char **s2, int num_word);
static char	*putword(char *word, const char *s, int i, int len_word);
static int	cnt_word(char const *str, char c);
static char	**free_array(char **ptr, int i);
int	ft_safe_atoi(const char *str, int *error);

#endif
