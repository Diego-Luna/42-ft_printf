/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:37:50 by diegofranci       #+#    #+#             */
/*   Updated: 2022/04/18 19:08:06 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert(va_list arg, t_printf *ob_print, const char *str)
{
	int	i;
	int	leng;

	i = 0;
	leng = ft_strlen(ob_print->convers);
	ft_strtostr(ob_print->str, str);
	ft_strtostr(ob_print->result, str);
	while (ob_print->convers[i] && i < leng)
	{
		if (ob_print->convers[i] == 's')
			ft_result_s(va_arg(arg, char *), ob_print, i);
		if (ob_print->convers[i] == 'c')
			ft_result_c(va_arg(arg, int), ob_print, i);
		if (ob_print->convers[i] == 'd' || ob_print->convers[i] == 'i')
			ft_result_di(va_arg(arg, int), ob_print, i);
		if (ob_print->convers[i] == 'u')
			ft_result_u(va_arg(arg, unsigned int), ob_print, i);
		if (ob_print->convers[i] == 'x')
			ft_result_x(va_arg(arg, int), ob_print, "0123456789abcdef", i);
		if (ob_print->convers[i] == 'X')
			ft_result_x(va_arg(arg, int), ob_print, "0123456789ABCDEF", i);
		i++;
	}
	return (1);
}
