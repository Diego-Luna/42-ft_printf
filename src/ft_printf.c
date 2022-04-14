/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 10:30:18 by diegofranci       #+#    #+#             */
/*   Updated: 2022/04/14 13:30:42 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list		arg;
	t_printf	ob_print;

	ob_print.str[0] = '\0';
	ob_print.result[0] = '\0';
	ob_print.convers[0] = '\0';
	printf("0-> 1 Valor de ob_print.convers: %s\n", ob_print.convers);
	va_start(arg, str);
	if (ft_check_params(arg, &ob_print, str) < 0)
	{
		printf("0-> Error - 0");
		return (-1);
	}
	if (!ft_convert(arg, &ob_print, str))
	{
		printf("Error - 1");
		return (-1);
	}
	printf("0->   2 Valor de ob_print.convers: %s\n", ob_print.convers);
	printf("0->  Valor de ob_print.result: %s\n", ob_print.result);
	printf("0->  go");
	va_end(arg);
	return (10);
}
