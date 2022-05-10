/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:17:47 by diegofranci       #+#    #+#             */
/*   Updated: 2022/05/10 14:21:38 by diegofranci      ###   ########.fr       */
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
	printf("\n Valor de atoi:%i, len:%i, ceros:%s\n", leng_numbes, leng_string, str);
}

void	ft_flag_space(t_printf *ob_print, char *str)
{
	ft_strtostr(ob_print->strold, str);
	ft_strtostr(str, " ");
	ft_strtostrn(str, ob_print->strold, 1);
}

void	ft_flag_plus(t_printf *ob_print, char *str)
{
	int	number;

	if (str[0] != '+')
	{
		number = ft_atoi(str);
		ft_strtostr(ob_print->strold, str);
		if (number < 0)
		{
			ft_strtostrn(str, ob_print->strold, 0);
		}
		else
		{
			ft_strtostr(str, "+");
			ft_strtostrn(str, ob_print->strold, 1);
		}
	}
}

void	ft_flag_cat(t_printf *ob_print, char *str)
{
	ft_strtostr(ob_print->strold, str);
	ft_strtostr(str, "0x");
	printf("**>str{%s}\n", str);
	ft_strtostrn(str, ob_print->strold, 2);
	printf("**>str{%s}\n", str);
}

void	ft_control(t_printf *ob_print, char *flags, char *str)
{
	int	i;

	i = 0;
	while (flags[i])
	{
		if (flags[i] == '#')
		{
			ft_flag_cat(ob_print, str);
			// printf("\n<ft_flag_cat>\n");
		}
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
