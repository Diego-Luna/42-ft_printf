/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_result_s_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:05:24 by diegofranci       #+#    #+#             */
/*   Updated: 2022/04/18 19:05:50 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_result_s(char	*arg, t_printf *ob_print, int counter)
{
	int	i;
	int	ii;

	i = 0;
	ii = 0;
	i = ft_strfind(ob_print->result, 0, '%');
	ft_strtostrn(ob_print->result, arg, i);
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

void	ft_result_c(int arg, t_printf *ob_print, int counter)
{
	int	i;
	int	ii;

	i = 0;
	ii = 0;
	i = ft_strfind(ob_print->result, 0, '%');
	ob_print->result[i] = arg;
	ob_print->result[i + 1] = '\0';
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
