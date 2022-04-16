/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 13:06:55 by diegofranci       #+#    #+#             */
/*   Updated: 2022/04/16 12:48:40 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	ft_printf("\n ft_printf u |%x| \n", 42);
	printf("\n printf u |%x| \n", 42);
	printf("\n");
	return (0);
}

/*
int	main(void)
{
	ft_printf("string ", "1", "2", "3");
}
*/