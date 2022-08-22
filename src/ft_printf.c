/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacamilalunalopez <anacamilalunalopez@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 10:30:18 by diegofranci       #+#    #+#             */
/*   Updated: 2022/08/21 19:03:19 by anacamilalu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list		arg;
	t_printf	ob_print;

	ob_print.i_str = 0;
	ob_print.i_result = 0;
	ob_print.str_end = 0;
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
	if (ob_print.str_end == 1)
	{
		// printf("\n--> str_end = 1, ft_strlen(ob_print.str):{%zu}, ft_strlen(ob_print.convers):{%zu}{%s}", ft_strlen(ob_print.str), ft_strlen(ob_print.convers), ob_print.convers);
		printf("\n--> str_end = 1, ft_strlen(ob_print.str):{%zu}, ft_strlen(ob_print.convers):{%zu}{%s}", ft_strlen(ob_print.result), ft_strlen(ob_print.convers), ob_print.convers);
		// printf("\n--> ft_strlen(ob_print.convers):{%zu}", ft_strlen(ob_print.convers));
		// return (ft_strlen(ob_print.str) - ft_strlen(ob_print.convers));
		return (ft_strlen(ob_print.result) + (2));
	}
	// printf("\n--> no if, ft_strlen(ob_print.str):{%zu}", ft_strlen(ob_print.str));
	return (ft_strlen(ob_print.result));
}
