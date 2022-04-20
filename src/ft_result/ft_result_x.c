/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_result_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:07:06 by diegofranci       #+#    #+#             */
/*   Updated: 2022/04/20 10:32:14 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_result_x(unsigned int arg, t_printf *ob_print, char *val, \
	int counter)
{
	char	str[12];

	str[0] = '\0';
	ft_inttostrx(arg, str, val);
	ft_update_result(ob_print, str, counter);
}

void	ft_result_sign(t_printf *ob_print, int counter)
{
	char	str[2];

	str[0] = '%';
	str[1] = '\0';
	ft_update_result(ob_print, str, counter);
}

void	test(void *p)
{
	int	i;

	i = 0;
	while (p[i])
	{
		printf("--> v: %p", p[i]);
		i++;
	}
}

void	ft_result_p(void *p, t_printf *ob_print, int counter)
{
	char	*p_char;

	p_char = p;
	test(&p);
	printf("\n--2> 0> p: %p\n", p);
	printf("\n--2> 0> d: %p\n", &p_char);
	printf("\n--2> 0> convers: %s\n", ob_print->convers);
	printf("\n--2> 0> counter: %d\n", counter);
}
