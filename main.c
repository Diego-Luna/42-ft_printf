/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 13:06:55 by diegofranci       #+#    #+#             */
/*   Updated: 2022/07/17 13:28:05 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/ft_printf.h"
#include <stdio.h>

#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int	main(void)
{
	// ft_printf("--------------------%%p--------------------\n");
	int ii = ft_printf("\nf :%c%%", 0);
	int	i = printf("\np :%c%%", 0);
	// int ii = ft_printf("\nf:%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42);
	// int	i = printf("\np:%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42);

	printf("\nValor de p :{%i}", i);
	printf("\nValor de f :{%i}", ii);
	return (0);
}

	// int i = printf("\n12");
	// int ii = ft_printf("\n12");
	// ft_printf("1:%c\n", '0');

	// printf("01) print PRINTF : |%c|\n", 'a');
	// ft_printf("01) ft_ PRINTF  : |%c|\n", 'a'); -> ready
	// printf("02) print PRINTF : |%-c|\n", 'z');
	// ft_printf("02) ft_ PRINTF  : |%-c|\n", 'z'); -> ready
	// printf("03) print PRINTF : |%-----c|\n", '!');
	// ft_printf("03) ft_ PRINTF  : |%-----c|\n", '!'); -> ready
	// printf("04) print PRINTF : |%5c|\n", 'R');
	// ft_printf("04) ft_ PRINTF  : |%5c|\n", 'R');
	// printf("05) print PRINTF : |%-5c|\n", 'R');
	// ft_printf("05) ft_ PRINTF  : |%-5c|\n", 'R');
	// printf("06) print PRINTF : |%1c|\n", '3');
	// ft_printf("06) ft_ PRINTF  : |%1c|\n", '3');
	// printf("07) print PRINTF : |%c|\n", '\0');
	// ft_printf("07) ft_ PRINTF  : |%c|\n", '\0');
	// printf("08) print PRINTF : |%5c|\n", '\0');
	// ft_printf("08) ft_ PRINTF  : |%5c|\n", '\0');
	// printf("09) print PRINTF : |%-5c|\n", '\0');
	// ft_printf("09) ft_ PRINTF  : |%-5c|\n", '\0');
	// printf("10) print PRINTF : |%1c|\n", '\0');
	// ft_printf("10} ft_ PRINTF  : |%1c|\n", '\0');
	// ft_printf("--------------------%%s--------------------\n");			//Perfect