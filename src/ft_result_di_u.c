/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_result_di_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:06:25 by diegofranci       #+#    #+#             */
/*   Updated: 2022/04/18 19:08:17 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_result_di(int arg, t_printf *ob_print, int counter)
{
	int		i;
	int		ii;
	char	str[12];

	i = 0;
	ii = 0;
	str[0] = '\0';
	ft_inttostr(arg, str);
	i = ft_strfind(ob_print->result, 0, '%');
	ft_strtostrn(ob_print->result, str, i);
	i = 0;
	while (counter >= 0)
	{
		i = ft_strfind(ob_print->str, i + ii, '%');
		ii = 1;
		counter--;
	}
	ft_strtostrnn(ob_print->result, ob_print->str, \
		ft_strlen(ob_print->result), i + 2);
}

void	ft_result_u(unsigned int arg, t_printf *ob_print, int counter)
{
	int		i;
	int		ii;
	char	str[12];

	i = 0;
	ii = 0;
	str[0] = '\0';
	ft_inttostrn(arg, str);
	i = ft_strfind(ob_print->result, 0, '%');
	ft_strtostrn(ob_print->result, str, i);
	i = 0;
	while (counter >= 0)
	{
		i = ft_strfind(ob_print->str, i + ii, '%');
		ii = 1;
		counter--;
	}
	ft_strtostrnn(ob_print->result, ob_print->str, \
		ft_strlen(ob_print->result), i + 2);
}
