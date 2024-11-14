/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_test1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:17:23 by emonacho          #+#    #+#             */
/*   Updated: 2024/11/09 19:57:39 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * %c prints a single character
 * %s prints a string
 * %p the void * pointer has to be printed in hexadecimal format
 * %d prints a decimal (base 10) number
 * %i prints an integer in base 10
 * %u prints an unsigned decimal (base 10) number
 * %x prints a number in hexadecimal (base16) lowercase format
 * %X prints a number in hexadecimal (base 16) uppercase format
 * %% prints a percent sign 
 */

/*
 * WHILE (const char*[i] =! '\0')
 * 	IF [i] est un char imprimable 
 * 		IF %c -> write(1, &c, 1)
 * 		IF %s -> ft_putstr
 * 		IF %p the void * pointer has to be printed in hexadecimal format
 * 		IF %d -> write(1, &c, 1)
 * 		IF %i -> ft_itoa
 * 		IF %u prints an unsigned decimal (base 10) number
 * 		IF %x prints a number in hexadecimal (base16) lowercase format
 * 		IF %X prints a number in hexadecimal (base 16) uppercase format
 * 		IF %% -> write(1, "%", 1)
 * 	ELSE
 * 		write(1, &i, 1)
 * 	i++ 
 */

// 1. `printf` prend une chaine de caracteres et X arguments variables en parametres.
// 2. La fonction parcoure la chaine et ecrit chaque caracteres jusqu'a `\0`.
// 3. Si en cours de route un `%` est trouve, alors la fonction doit convertir le specificateur.
// 4. La conversion (`cspdiuxX%`) se fait a partir de l'index(`i + 1`), donc `%`.
// 5. La lecture dans la chaine doit ensuite se poursuivre a partir de l'index plus la taille de la conversion (`i + count`).  
//
// EXEMPLE: printf(`"Hello_%s_how_you_doin?", "DOG"`);
// - `printf` ecrit `"Hello_"` et ne va pas plus loin car il detecte que le char suivant `_` est `%` ----- "Hello_%" -> 7 char / "Hello_DOG" -> 9 char
// - Les caractere correspondant a l'argument variable est ecrit et pour chaque conversion de `char` faite, l'index `count` est incremente. A la fin de la conversion `count` est retourne.
// - La lecture et l'ecriture de la chaine d'origine est poursuivie a partir de `i + count` et ce jusqu'a un nouveau secificateur `%` ou `\0`.                
