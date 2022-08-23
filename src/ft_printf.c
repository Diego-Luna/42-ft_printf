/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacamilalunalopez <anacamilalunalopez@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 10:30:18 by diegofranci       #+#    #+#             */
/*   Updated: 2022/08/22 19:58:14 by anacamilalu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_check_c(t_printf *ob_print)
{
	int i;
	int result;

	result = 0;
	if (!(ft_strlen(ob_print->convers)))
	{
		return (0);
	}
	i = ft_strfin(ob_print->convers, 'c');

	// printf("\n!!--> (int)(ft_strlen(ob_print->result) + (i - 1)):{%i} \n", (int)(ft_strlen(ob_print->result) + (i - 1)));
	// printf("\n!!--> (int)(ft_strlen(ob_print->str) - ft_strlen(ob_print->convers)):{%i} \n", (int)(ft_strlen(ob_print->str) - ft_strlen(ob_print->convers)));

	if ((int)(ft_strlen(ob_print->result) + (i - 1)) > (int)(ft_strlen(ob_print->str) - ft_strlen(ob_print->convers)))
	{
		// return ((int)(ft_strlen(ob_print->result) + (i - 1)));
		result = ft_findc_next_same(ob_print->convers, ft_findc(ob_print->convers, 0, 'c'), 'c') + 1 ;
		// printf("##> Value de result{%i}", result);
		return ((int)(ft_strlen(ob_print->result) + (result)));
	}
	return (ft_strlen(ob_print->str) - ft_strlen(ob_print->convers));
}

// int ft_check_c(t_printf *ob_print)
// {
// 	int i;
// 	int retult;

// 	retult = 0;
// 	// printf("\n ---> 1 ft_strlen(ob_print->convers):{%zu} \n", ft_strlen(ob_print->convers));
// 	if (!(ft_strlen(ob_print->convers)))
// 	{
// 		return (0);
// 	}
// 	i = ft_findc(ob_print->convers, 0, 'c');

// 	// printf("\n ---> 2 ft_findc(ob_print->convers, 0,'c'):{%d} \n", i);
// 	if (!(ob_print->convers[i] == 'c'))
// 	{
// 		return (0);
// 	}

// 	while (ob_print->convers[i] == 'c')
// 	{
// 		// printf("\n ---> 3 ob_print->convers[i] == 'c':{%c} \n", ob_print->convers[i]);
// 		i++;
// 		retult++;
// 	}
// 	if (retult > 1)
// 	{
// 		return (retult + 1);
// 	}
// 	return (retult);
// }

int ft_printf(const char *str, ...)
{
	va_list arg;
	t_printf ob_print;

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

	if (ob_print.str_end == 2)
	{
		// printf("\n-> Ft_strlen(ob_print.str):{%zu}, ft_strlen(ob_print.convers):{%zu}{%s}, ft_strlen(ob_print.result):{%zu}", ft_strlen(ob_print.str), ft_strlen(ob_print.convers), ob_print.convers, ft_strlen(ob_print.result));

		// return (ft_strlen(ob_print.result) + ft_check_c(&ob_print));
		return (ft_check_c(&ob_print));
		// return (ft_strlen(ob_print.str) - ft_strlen(ob_print.convers));
		// return (ft_strlen(ob_print.result) + ft_strlen(ob_print.convers));
	}
	// printf("\n--> no if, ft_strlen(ob_print.str):{%zu}", ft_strlen(ob_print.str));
	return (ft_strlen(ob_print.result));
}
