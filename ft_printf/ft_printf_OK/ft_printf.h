/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:34:54 by emonacho          #+#    #+#             */
/*   Updated: 2024/12/12 14:06:25 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

static int	cntdigits(unsigned int nbr);
int			ft_printf(const char *format, ...);
char		*itoa(unsigned int n);
void		printf_itoa_unsigned(unsigned int n, size_t *cnt);
void		printf_itoa(int n, size_t *cnt);
void		printf_putchar(char c, size_t *cnt);
void		printf_putstr(char *s, size_t *cnt);
void		puthex_dec(unsigned int to_convert, char spec, size_t *cnt);
int			put_ptr(void *ptr, char spec, size_t *cnt);

#endif
