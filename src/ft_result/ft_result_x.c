/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_result_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:07:06 by diegofranci       #+#    #+#             */
/*   Updated: 2022/07/17 13:20:38 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_result_x(int arg, t_printf *ob_print, char *val, \
	int counter)
{
	char	str[12];
	char	hex[20];

	str[0] = '\0';
	hex[0] = '\0';
	ft_strtostr(hex, val);
	if (arg >= 0)
	{
		ft_inttostrx(arg, str, val);
	}
	else
	{
		ft_str_invest(hex);
		arg *= -1;
		arg -= 1;
		ft_inttostrx(arg, str, hex);
		ft_fill(str, hex[0], 8);
	}
	ft_update_result(ob_print, str, counter);
}

void	ft_result_sign(t_printf *ob_print, int counter)
{
	char	str[2];

	str[0] = '%';
	str[1] = '\0';

	// printf("\n***> result de %%:{%s}", ob_print->result);
	// printf("\n***> str de %%:{%s}", ob_print->str);

	ft_flags(ob_print, str, counter);
	ft_update_result(ob_print, str, counter);
	// printf("\n***> despues de %%:{%s}", ob_print->result);
}

void	ft_result_p(unsigned long p, t_printf *ob_print, int counter)
{
	char	str1[20];
	char	str2[15];

	// printf("\n--> p {%lu}", p);
	// printf("\n--> p {%lx}", p);

	ft_inttostrx(p, str2, "0123456789abcdef");
	// printf("\n--> ft_strlen(str2) {%zu}", ft_strlen(str2));
	if (ft_strlen(str2) >= 9)
	{
		// printf("\n--> if");
		ft_strtostr(str1, "0x10");
	}
	else if (ft_strlen(str2) >= 4){
		ft_strtostr(str1, "0x1");
	}
	else
	{
		// printf("\n--> else");
		ft_strtostr(str1, "0x");
	}
	ft_strtostrn(str1, str2, ft_strlen(str1));
	ft_flags(ob_print, str1, counter);
	ft_update_result(ob_print, str1, counter);
}

// void	ft_result_p(unsigned long p, t_printf *ob_print, int counter)
// {
// 	char	str1[20];
// 	char	str2[15];

// 	printf("\n--> p {%lu}", p);
// 	printf("\n--> p {%lx}", p);

// 	if (p <= )
// 	{
// 		ft_strtostr(str1, "0x100");
// 	}
// 	else
// 	{
// 		ft_strtostr(str1, "0x10");
// 	}
// 	ft_inttostrx(p, str2, "0123456789abcdef");
// 	ft_strtostrn(str1, str2, ft_strlen(str1));
// 	ft_flags(ob_print, str1, counter);
// 	ft_update_result(ob_print, str1, counter);
// }
