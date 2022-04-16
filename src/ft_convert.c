/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:37:50 by diegofranci       #+#    #+#             */
/*   Updated: 2022/04/15 20:49:39 by diegofranci      ###   ########.fr       */
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
	str1[i] = '\0';
}

void	ft_strtostrnf(char *str1, const char *str2, int n)
{
	int	i;

	i = 0;
	while (str2[i] && i < n)
	{
		str1[i] = str2[i];
		i++;
	}
	str1[i] = '\0';
}

void	ft_strtostrn(char *str1, const char *str2, int start)
{
	int	i;

	i = 0;
	while (str2[i])
	{
		str1[start] = str2[i];
		start++;
		i++;
	}
	str1[start] = '\0';
}

void	ft_strtostrnn(char *str1, const char *str2, int start1, int start2 )
{
	while (str2[start2] && !(start2 > (int)ft_strlen(str2)))
	{
		str1[start1] = str2[start2];
		start1++;
		start2++;
	}
	str1[start1] = '\0';
}

void	ft_result_s(char	*arg, t_printf *ob_print)
{
	int	i;

	i = ft_strfind(ob_print->result, 0, '%');
	printf("--> 2-> Valor de i = %i\n", i);
	printf("--> 2-> Valor ob_print->result = %s\n", ob_print->result);
	printf("--> 2-> Valor de arg = %s\n", arg);
	ft_strtostrn(ob_print->result, arg, i);
	printf("--> 2-> 2 Valor ob_print->result = %s\n", ob_print->result);
	ft_strtostrnn(ob_print->result, ob_print->str, \
		ft_strlen(ob_print->result), i + 2);
	printf("--> 2-> 3 Valor ob_print->result = %s\n", ob_print->result);
}

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
		{
			ft_result_s(va_arg(arg, char *), ob_print);
		}
		printf("--> 2-> El valor de i: %i,--\n", i);
		i++;
	}
	ft_result_s(va_arg(arg, char *), ob_print);
	printf("--> 2-> El ob_print->result: %s,--\n", ob_print->result);
	return (1);
}
