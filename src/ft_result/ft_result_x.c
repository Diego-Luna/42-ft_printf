/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_result_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:07:06 by diegofranci       #+#    #+#             */
/*   Updated: 2022/04/26 09:34:05 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_result_x(unsigned int arg, t_printf *ob_print, char *val, \
	int counter)
{
	char	str[12];

	str[0] = '\0';
	ft_inttostrx(arg, str, val);
	ft_update_result(ob_print, str, counter);
}

void	ft_result_sign(t_printf *ob_print, int counter)
{
	char	str[2];

	str[0] = '%';
	str[1] = '\0';
	ft_update_result(ob_print, str, counter);
}

//void	ft_result_p(void *p, t_printf *ob_print, int counter)
void	ft_result_p(unsigned long p, t_printf *ob_print, int counter)
{
	char	str1[20];
	char	str2[15];

	if (p <= 4309661745)
	{
		ft_strtostr(str1, "0x100");
	}
	else
	{
		ft_strtostr(str1, "0x10");
	}
	ft_inttostrx(p, str2, "0123456789abcdef");
	ft_strtostrn(str1, str2, ft_strlen(str1));
	ft_update_result(ob_print, str1, counter);
}
	//printf("\n--2> 0> p-i: %lu\n", p);
	//printf("\n--2> 0> s2: %s\n", str2);
	//printf("\n--2> 0> s1: %s\n", str1);

/*
void	ft_result_p(void *p, t_printf *ob_print, int counter)
{
	char	*p_char;

	(void)counter;
	(void)ob_print;
	p_char = p;
	printf("\n--2> 0> p: %p\n", p);
	printf("\n--2> 0> d: %p\n", p_char);
}
*/