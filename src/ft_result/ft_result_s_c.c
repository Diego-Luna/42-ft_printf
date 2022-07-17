/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_result_s_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:05:24 by diegofranci       #+#    #+#             */
/*   Updated: 2022/07/17 13:29:13 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_result_s(char	*arg, t_printf *ob_print, int counter)
{
	ft_flags(ob_print, arg, counter);
	ft_update_result(ob_print, arg, counter);
}

	// str[0] = arg;
void	ft_result_c(int arg, t_printf *ob_print, int counter)
{
	char	str[2];

	if (ob_print->str_end == 0 )
	{
		if (arg < 0)
		{
			arg = '0';
			ob_print->str_end = 1;
		}
		if (arg > 32)
		{
			str[0] = arg;
			str[1] = '\0';
		}
		else
		{
			str[0] = '\0';
			ob_print->str_end = 1;
		}
		// if (arg == 0){
		// 	// printf("\n**> de 0 a 32");
		// 	str[0] = '\0';
		// 	ob_print->str_end = 0;
		// }
		ft_flags(ob_print, str, counter);
		ft_update_result(ob_print, str, counter);
	}
}

// void	ft_result_c(int arg, t_printf *ob_print, int counter)
// {
// 	char	str[2];

// 	str[0] = arg;
// 	str[1] = '\0';
// 	ft_flags(ob_print, str, counter);
// 	ft_update_result(ob_print, str, counter);
// }
