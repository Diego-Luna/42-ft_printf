/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 13:06:55 by diegofranci       #+#    #+#             */
/*   Updated: 2022/05/09 16:20:03 by diegofranci      ###   ########.fr       */
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
	ft_printf("f: %  i\n", 1);
	printf("p: %  i\n", 1);
	return (0);
}
