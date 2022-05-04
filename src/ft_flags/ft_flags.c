/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:17:47 by diegofranci       #+#    #+#             */
/*   Updated: 2022/05/03 20:52:24 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_flag_on(t_printf *ob_print, char counter)
{
	int	i;

	i = 0;
	counter += 48;
	while (ob_print->flags[i])
	{
		if (ob_print->flags[i] == counter && ob_print->flags[i + 1] == '(')
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

void	ft_get_flag(t_printf *ob_print, int position, char	*str)
{
	int		end;

	position += 2;
	end = ft_findc(ob_print->flags, position, ')');
	ft_strtostr_rango(str, ob_print->flags, position, end);
	printf("\n>start:{%i}-end:{%i}\n", position, end);
}

void	ft_control(t_printf *ob_print, char *flags, char *str)
{
	int	i;

	i = 0;
	(void)ob_print;
	while (flags[i])
	{
		if (flags[i] == '-')
		{
			(void)str;
		}
		if ((flags[i] == '0' || flags[i] == '.') && ft_isdigit(flags[i + 1]))
		{
			(void)str;
		}
		i++;
	}
}

void	ft_flags(t_printf *ob_print, char *str, int counter)
{
	int		i;
	char	flags[20];

	(void)str;
	(void)counter;
	flags[19] = '\0';
	printf("\n+Valor de flags s:%s\n", ob_print->flags);
	i = ft_flag_on(ob_print, 1);
	printf("\n+++++Valor de i:%i \n", i);
	if (i >= 0)
	{
		ft_get_flag(ob_print, i, flags);
		//printf("\n -->El valor de flags:/%s/\n", flags);
		//ft_control(ob_print, flags, str);
	}
}
