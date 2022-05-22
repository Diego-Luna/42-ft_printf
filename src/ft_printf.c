/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 10:30:18 by diegofranci       #+#    #+#             */
/*   Updated: 2022/05/22 17:13:11 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list		arg;
	t_printf	ob_print;

	ob_print.position = -1;
	ob_print.str[0] = '\0';
	ob_print.flags[0] = '\0';
	ob_print.strold[0] = '\0';
	ob_print.result[0] = '\0';
	ob_print.convers[0] = '\0';
	va_start(arg, str);
	ft_strtostr(ob_print.str, str);
	if (ft_check_params(arg, &ob_print) < 0)
	{
		return (-1);
	}
	ft_strtostr(ob_print.result, ob_print.str);
	if (!ft_convert(arg, &ob_print))
	{
		return (-1);
	}
	ft_putstr_fd(ob_print.result, 1);
	va_end(arg);
	return (ft_strlen(ob_print.result));
}
