/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:17:47 by diegofranci       #+#    #+#             */
/*   Updated: 2022/05/11 21:03:24 by diegofranci      ###   ########.fr       */
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

// char	*ft_get_flag(t_printf *ob_print, int position)
void	ft_get_flag(t_printf *ob_print, int position, char	*past)
{
	int		end;
	char	str[20];

	position += 2;
	end = ft_findc(ob_print->flags, position, ')');
	ft_strtostr_rango(str, ob_print->flags, position, end);
	ft_strtostr(past, str);
}

void	ft_control(t_printf *ob_print, char *flags, char *str)
{
	int	i;

	i = 0;
	while (flags[i])
	{
		if (flags[i] == '-')
		{
		}
		if ((flags[i] == '0' || flags[i] == '.') && ft_isdigit(flags[i + 1]))
		{
			ft_flag_number(ob_print, flags, str);
		}
		if (flags[i] == ' ' && flags[i - 1] != ' ')
		{
			ft_flag_space(ob_print, str);
		}
		if (flags[i] == '+')
		{
			ft_flag_plus(ob_print, str);
		}
		if (flags[i] == '#')
		{
			ft_flag_cat(ob_print, str);
		}
		i++;
	}
}

void	ft_flags(t_printf *ob_print, char *val, int counter)
{
	int		i;
	char	str[20];

	(void)val;
	(void)counter;
	i = ft_flag_on(ob_print, 1);
	if (i >= 0)
	{
		ft_strtostr(str, "flags");
		ft_get_flag(ob_print, i, str);
		printf("\n-->El valor de flags:/%s/\n", str);
		ft_control(ob_print, str, val);
	}
}
