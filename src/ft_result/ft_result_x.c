/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_result_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:07:06 by diegofranci       #+#    #+#             */
/*   Updated: 2022/04/19 08:33:37 by diegofranci      ###   ########.fr       */
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

void	ft_result_p(void *p, t_printf *ob_print, int counter)
{
	printf("\n--2> 0> %p\n", p);
}
