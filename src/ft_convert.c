/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:37:50 by diegofranci       #+#    #+#             */
/*   Updated: 2022/04/13 16:28:30 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strfind(const char *str, int start, char c)
{
	while (str[start] && str[start] != c)
	{
		start++;
	}
	return (start);
}

void	ft_strtostr(char *str1, const char *str2)
{
	int	i;

	i = 0;
	while (str2[i])
	{
		str1[i] = str2[i];
		i++;
	}
}

void	ft_strtostrn(char *str1, const char *str2, int start)
{
	int	i;

	i = start;
	while (str2[i])
	{
		str1[i] = str2[i];
		i++;
	}
}

void	ft_result_s(va_list arg, t_printf *ob_print, const char *str)
{
	int	i;
	int	ii;

	i = ft_strfind(str, 0, '%');
	ii = 0;
	ft_strtostr(ob_print->result, str);
	ft_strtostrn(ob_print->result, arg, i);
}

int	ft_which_choose(char c, va_list arg, t_printf *ob_print, const char *str)
{
	if (c == 's')
	{
		ft_result_s(arg, &ob_print, str);
	}
}

int	ft_convert(va_list arg, t_printf *ob_print, const char *str)
{
	int	i;
	int	max;

	i = 0;
	max = ft_strlen(ob_print->convers);
	ft_strtostr(ob_print->str, str);
	while (ob_print->convers[i])
	{
		if (max)
		{
		}
		if (ob_print->convers[i] == 's')
		{
			ft_result_s(arg, &ob_print, str);
		}
		i++;
	}
	return (1);
}
