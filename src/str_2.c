/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 20:19:58 by diegofranci       #+#    #+#             */
/*   Updated: 2022/07/17 13:13:47 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_strtostrnf(char *str1, const char *str2, int n)
{
	int i;

	i = 0;
	while (str2[i] && i < n)
	{
		str1[i] = str2[i];
		i++;
	}
	str1[i] = '\0';
}

void ft_strtostrn(char *str1, const char *str2, int start)
{
	int i;

	i = 0;

	while (str2[i])
	{
		str1[start] = str2[i];
		start++;
		i++;
	}
	str1[start] = '\0';
}

void ft_str_invest(char *str)
{
	int i;
	int ii;
	int leng;
	char tem;

	leng = ft_strlen(str) - 1;
	i = 0;
	ii = leng;
	while (i <= (leng / 2))
	{
		tem = str[i];
		str[i] = str[ii];
		str[ii] = tem;
		i++;
		ii--;
	}
}

void ft_strtostrnn(char *str1, const char *str2, int start1, int start2)
{
	while (str2[start2])
	{
		str1[start1] = str2[start2];
		start1++;
		start2++;
	}
	str1[start1] = '\0';
}

void ft_strtostr_rango(char *str1, char *str2, int start2, int end2)
{
	int i;

	i = 0;
	while (str2[start2] && end2 > start2)
	{
		str1[i] = str2[start2];
		start2++;
		i++;
	}
	str1[i] = '\0';
}

void ft_fill(char *str, char fill, int number)
{
	int i;
	int leng_str;
	char copy_str[40];

	leng_str = ft_strlen(str);
	copy_str[0] = '\0';
	ft_strtostr(copy_str, str);
	i = 0;
	while (i < (number - leng_str))
	{
		str[i] = fill;
		i++;
	}
	ft_strtostrn(str, copy_str, i);
}
