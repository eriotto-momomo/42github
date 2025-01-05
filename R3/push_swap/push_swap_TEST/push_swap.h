#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

char *push_swap(int argc, char *argv[]);
int	check_arguments(char *array[], int	i);
int str_arr_to_int_arr(int argc, char *str_array[argc], int int_array[argc - 1]);
int check_duplicates(int argc, int int_array[argc - 1]);
int	argv_is_valid(int argc, char **array, int a_stack[argc - 1]);
char	**ft_split(char const *s, char c);
static char	**splitword(const char *s, char c, char **s2, int num_word);
static char	*putword(char *word, const char *s, int i, int len_word);
static int	cnt_word(char const *str, char c);
static char	**free_array(char **ptr, int i);
int	ft_safe_atoi(const char *str, int *error);

#endif
