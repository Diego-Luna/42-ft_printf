/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 20:19:58 by diegofranci       #+#    #+#             */
/*   Updated: 2022/04/18 19:00:49 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	while (str2[start2])
	{
		str1[start1] = str2[start2];
		start1++;
		start2++;
	}
	str1[start1] = '\0';
}
