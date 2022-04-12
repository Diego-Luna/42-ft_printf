/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 13:06:55 by diegofranci       #+#    #+#             */
/*   Updated: 2022/04/11 19:12:50 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/ft_printf.h"
#include <stdio.h>

// Driver Code
int main()
{
//    printf("\n\n Variadic functions: \n");
 
    // Variable number of arguments
/*    printf("\n 1 + 2 = %d ",
           AddNumbers(2, 1, 2));
 
    printf("\n 3 + 4 + 5 = %d ",
           AddNumbers(3, 3, 4, 5));
 
    printf("\n 6 + 7 + 8 + 9 = %d ",
           AddNumbers(4, 6, 7, 8, 9));
 
    printf("\n"); */
 
	printf("\n\n ft_printf functions: \n");

	// Variable number of arguments
    printf("\n hola + mundo = %d ",
           ft_AddStringd("Hola", "Mundo"));

    printf("\n");

    return 0;
}

/*
int	main(void)
{
	ft_printf("string ", "1", "2", "3");
}
*/