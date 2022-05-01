/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 20:17:36 by diegofranci       #+#    #+#             */
/*   Updated: 2022/04/30 14:27:34 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_findc(const char *str, int start, char c)
{
	while (str[start])
	{
		if (str[start] == c)
		{
			return (start);
		}
		start++;
	}
	return (0);
}

int	ft_strfind(const char *str, int start, char c)
{
	while (str[start])
	{
		if (str[start] == c && ft_check(str[start + 1]))
		{
			return (start);
		}
		start++;
	}
	return (0);
}

int	ft_strfin(const char *str, char c)
{
	int	i;
	int	ii;

	i = 0;
	ii = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			ii++;
		}
		i++;
	}
	return (ii);
}

int	ft_strfin_end(const char *str, char c, int end)
{
	int	i;
	int	ii;

	i = 0;
	ii = 0;
	while (str[i] && i <= end)
	{
		if (str[i] == c)
		{
			ii++;
		}
		i++;
	}
	return (ii);
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
