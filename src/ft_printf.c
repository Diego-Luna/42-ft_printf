/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 10:30:18 by diegofranci       #+#    #+#             */
/*   Updated: 2022/04/26 10:21:41 by diegofranci      ###   ########.fr       */
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
	va_start(arg, str);
	if (ft_check_params(arg, &ob_print, str) < 0)
	{
		printf("0-> Error - 0");
		return (-1);
	}
	ft_strtostr(ob_print.str, str);
	ft_strtostr(ob_print.result, str);
	if (!ft_convert(arg, &ob_print))
	{
		printf("0-> Error - 1");
		return (-1);
	}
	ft_putstr_fd(ob_print.result, 1);
	va_end(arg);
	return (10);
}
