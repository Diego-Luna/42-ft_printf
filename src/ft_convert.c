/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:37:50 by diegofranci       #+#    #+#             */
/*   Updated: 2022/04/16 13:08:13 by diegofranci      ###   ########.fr       */
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

void	ft_result_s(char	*arg, t_printf *ob_print)
{
	int	i;

	i = ft_strfind(ob_print->result, 0, '%');
	ft_strtostrn(ob_print->result, arg, i);
	//printf("--> 2-> 1 El valor de ob_print->result:%s\n", ob_print->result);
	ft_strtostrnn(ob_print->result, ob_print->str, \
		ft_strlen(ob_print->result), i + 2);
	//printf("--> 2-> 2 El valor de ob_print->result:%s\n", ob_print->result);
}

void	ft_result_c(int arg, t_printf *ob_print)
{
	int	i;

	i = ft_strfind(ob_print->result, 0, '%');
	ob_print->result[i] = arg;
	ob_print->result[i + 1] = '\0';
	ft_strtostrnn(ob_print->result, ob_print->str, \
		ft_strlen(ob_print->result), i + 2);
	//printf("--> 2-> 1 El valor de ob_print->result:%s\n", ob_print->result);
}

void	ft_write(int n, char *str)
{
	int	leng;

	n += 48;
	leng = ft_strlen(str);
	str[leng] = n;
	str[leng + 1] = '\0';
}

void	ft_inttostr(int nb, char *str)
{
	if (nb <= -2147483648)
	{
		ft_inttostr(nb / 10, str);
		ft_write(8, str);
	}
	else if (nb < 0)
	{
		ft_write(-3, str);
		ft_inttostr(-nb, str);
	}
	else
	{
		if (nb > 9)
		{
			ft_inttostr(nb / 10, str);
		}
		ft_write(nb % 10, str);
	}
}

void	ft_inttostrx(int nb, char *str, char *val)
{
	int	leng;

	if (nb <= -2147483648)
	{
		ft_inttostrx(nb / ft_strlen(val), str, val);
		ft_write(8, str);
	}
	else if (nb < 0)
	{
		ft_write(-3, str);
		ft_inttostrx(-nb, str, val);
	}
	else
	{
		if (nb > 9)
		{
			ft_inttostrx(nb / ft_strlen(val), str, val);
		}
		leng = ft_strlen(str);
		str[leng] = val[nb % ft_strlen(val)];
		str[leng + 1] = '\0';
	}
}

void	ft_inttostrn(unsigned int nb, char *str)
{
	if (nb > 9)
	{
		ft_inttostrn(nb / 10, str);
	}
	ft_write(nb % 10, str);
}

void	ft_result_di(int arg, t_printf *ob_print)
{
	int		i;
	char	str[12];

	str[0] = '\0';
	ft_inttostr(arg, str);
	//printf("---> 2-> El valor de str:%s\n", str);
	//printf("---> 2-> 0 El valor de ob_print->result:%s\n", ob_print->result);
	i = ft_strfind(ob_print->result, 0, '%');
	//printf("---> 2-> El valor de i:%d\n", i);
	ft_strtostrn(ob_print->result, str, i);
	//printf("---> 2-> 1 El valor de ob_print->result:%s\n", ob_print->result);
	ft_strtostrnn(ob_print->result, ob_print->str, \
		ft_strlen(ob_print->result), i + 2);
	//printf("---> 2-> 2 El valor de ob_print->result:%s\n", ob_print->result);
}

void	ft_result_u(unsigned int arg, t_printf *ob_print)
{
	int		i;
	char	str[12];

	str[0] = '\0';
	ft_inttostrn(arg, str);
	//printf("---> 2-> El valor de str:%s, arg: %u\n", str, arg);
	//printf("---> 2-> 0 El valor de ob_print->result:%s\n", ob_print->result);
	i = ft_strfind(ob_print->result, 0, '%');
	//printf("---> 2-> El valor de i:%d\n", i);
	ft_strtostrn(ob_print->result, str, i);
	//printf("---> 2-> 1 El valor de ob_print->result:%s\n", ob_print->result);
	ft_strtostrnn(ob_print->result, ob_print->str, \
		ft_strlen(ob_print->result), i + 2);
	//printf("---> 2-> 2 El valor de ob_print->result:%s\n", ob_print->result);
}

void	ft_result_x(unsigned int arg, t_printf *ob_print, char *val)
{
	int		i;
	char	str[12];

	str[0] = '\0';
	ft_inttostrx(arg, str, val);
	//printf("---> 2-> El valor de str:%s, arg: %u\n", str, arg);
	//printf("---> 2-> 0 El valor de ob_print->result:%s\n", ob_print->result);
	i = ft_strfind(ob_print->result, 0, '%');
	//printf("---> 2-> El valor de i:%d\n", i);
	ft_strtostrn(ob_print->result, str, i);
	//printf("---> 2-> 1 El valor de ob_print->result:%s\n", ob_print->result);
	ft_strtostrnn(ob_print->result, ob_print->str, \
		ft_strlen(ob_print->result), i + 2);
	//printf("---> 2-> 2 El valor de ob_print->result:%s\n", ob_print->result);
}

int	ft_convert(va_list arg, t_printf *ob_print, const char *str)
{
	int	i;
	int	leng;

	i = 0;
	leng = ft_strlen(ob_print->convers);
	ft_strtostr(ob_print->str, str);
	ft_strtostr(ob_print->result, str);
	while (ob_print->convers[i] && i < leng)
	{
		if (ob_print->convers[i] == 's')
			ft_result_s(va_arg(arg, char *), ob_print);
		if (ob_print->convers[i] == 'c')
			ft_result_c(va_arg(arg, int), ob_print);
		if (ob_print->convers[i] == 'd' || ob_print->convers[i] == 'i')
			ft_result_di(va_arg(arg, int), ob_print);
		if (ob_print->convers[i] == 'u')
			ft_result_u(va_arg(arg, unsigned int), ob_print);
		if (ob_print->convers[i] == 'x')
			ft_result_x(va_arg(arg, int), ob_print, "0123456789abcdef");
		if (ob_print->convers[i] == 'X')
			ft_result_x(va_arg(arg, int), ob_print, "0123456789ABCDEF");
		i++;
	}
	return (1);
}
