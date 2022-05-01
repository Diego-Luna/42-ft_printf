/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:17:47 by diegofranci       #+#    #+#             */
/*   Updated: 2022/04/30 19:06:55 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_flag_on(t_printf *ob_print, char counter)
{
	int	i;

	i = 0;
	counter += 48;
	printf("\nEl valor de counter:%c\n", counter);
	while (ob_print->flags[i])
	{
		if (ob_print->flags[i] == counter && ob_print->flags[i + 1] == '(')
		{
			return (i);
		}
		i++;
	}
	printf("\nEl valor de i en flags:%i\n", i);
	return (-1);
}

char	*ft_get_flag(t_printf *ob_print, int position)
{
	int		end;
	char	str[20];

	end = ft_findc(ob_print->flags, position, ')');
	ft_strtostr_rango(str, ob_print->flags, position, end);
	printf("\n -->El valor de str:%s\n", str);
	return (str);
}

void	ft_flags(t_printf *ob_print, char *str, int counter)
{
	int		i;
	char	*flags;

	(void)str;
	(void)counter;
	printf("\n+Valor de flags s:%s\n", ob_print->flags);
	i = ft_flag_on(ob_print, 1);
	printf("\n+++++Valor de i:%i \n", i);
	if (i >= 0)
	{
		flags = ft_get_flag(ob_print, i);
		printf("\n -->El valor de flags:%s\n", flags);
	}
}
