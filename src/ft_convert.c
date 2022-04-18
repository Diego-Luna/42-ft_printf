/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:37:50 by diegofranci       #+#    #+#             */
/*   Updated: 2022/04/17 20:20:54 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
