/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 13:06:55 by diegofranci       #+#    #+#             */
/*   Updated: 2022/04/29 14:30:35 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/ft_printf.h"
#include <stdio.h>

	//ft_printf("\n**> tf_    |-|%c|-|%s|-|%i|-|%d|-|%u|-|%x|-|%X|-|%%|-|%p|\n",
	//	'D', "Luna", 42, 24, 12, 2022, 2222, "\n\n");
	//printf("\n**> printf |-|%c|-|%s|-|%i|-|%d|-|%u|-|%x|-|%X|-|%%|-|%p|\n",
	//	'D', "Luna", 42, 24, 12, 2022, 2222, "\n\n");
int	main(void)
{
	ft_printf("f: %-i", 1);
	//ft_printf("f: %i", 1);
	printf("p: %-i", 1);
	return (0);
}
