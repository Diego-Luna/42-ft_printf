/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 13:06:55 by diegofranci       #+#    #+#             */
/*   Updated: 2022/04/12 18:29:47 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	printf("\n\n ft_printf functions: \n");
	printf("\n hola = %d ", ft_printf("Hola mundo %s"));
	printf("\n");
	return (0);
}

/*
int	main(void)
{
	ft_printf("string ", "1", "2", "3");
}
*/