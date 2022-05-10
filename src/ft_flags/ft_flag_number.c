/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:45:23 by diegofranci       #+#    #+#             */
/*   Updated: 2022/05/10 14:46:28 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_flag_number(t_printf *ob_print, char *flags, char *str)
{
	char	ceros[200];
	int		leng_numbes;
	int		leng_string;
	int		full;
	int		i;

	leng_string = ft_strlen(str);
	leng_numbes = ft_atoi(flags);
	if (leng_numbes > leng_string)
	{
		full = leng_numbes - leng_string;
		i = 0;
		while (full > 0)
		{
			ceros[i] = '0';
			i++;
			full--;
		}
		ceros[i] = '\0';
		ft_strtostr(ob_print->strold, str);
		ft_strtostr(str, ceros);
		ft_strtostrn(str, ob_print->strold, i);
	}
}
