/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 10:03:25 by diegofranci       #+#    #+#             */
/*   Updated: 2022/04/28 12:15:59 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_add_convers(t_printf *ob_print, char c)
{
	size_t	i;

	i = ft_strlen(ob_print->convers);
	ob_print->convers[i] = c;
	ob_print->convers[i + 1] = '\0';
}

int	ft_check(char s)
{
	if (s == 'c' || s == 's' || s == 'p' || s == 'd' || s == 'i' || s == 'u'
		|| s == 'x' || s == 'X' || s == '%')
	{
		return (1);
	}
	return (0);
}

void	ft_add_flags(t_printf *ob_print, char c)
{
	size_t	i;

	i = ft_strlen(ob_print->flags);
	ob_print->flags[i] = c;
	ob_print->flags[i + 1] = '\0';
}

void	ft_str_flags(const char *s, int i, t_printf *ob_print)
{
	int	num;

	i++;
	num = ft_strfin_end(s, '%', i);
	ft_add_flags(ob_print, (num + 48));
	ft_add_flags(ob_print, '(');
	while (!ft_check(s[i]))
	{
		ft_add_flags(ob_print, s[i]);
		i++;
	}
	ft_add_flags(ob_print, ')');
}

int	ft_strchrall(const char *s, char c, t_printf *ob_print)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	if (!s)
	{
		return (-1);
	}
	while (s[i])
	{
		if (s[i] == c && ft_check(s[i + 1]) && s[i - 1] != '%')
		{
			num++;
			ft_add_convers(ob_print, s[i + 1]);
		}
		else if (s[i] == c && s[i - 1] != '%')
		{
			ft_str_flags(s, i, ob_print);
		}
		i++;
	}
	return (num);
}

int	ft_check_params(va_list arg, t_printf *ob_print, const char *str)
{
	int	num;

	if (!arg)
	{
		return (-1);
	}
	num = ft_strchrall(str, '%', ob_print);
	printf("\n-->ob_print->flags:%s\n", ob_print->flags);
	if (num < 0)
	{
		return (-1);
	}
	return (1);
}
