/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 20:17:36 by diegofranci       #+#    #+#             */
/*   Updated: 2022/04/17 20:19:29 by diegofranci      ###   ########.fr       */
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
