/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_result_s_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:05:24 by diegofranci       #+#    #+#             */
/*   Updated: 2022/05/17 09:39:17 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_result_s(char	*arg, t_printf *ob_print, int counter)
{
	ft_flags(ob_print, arg, counter);
	ft_update_result(ob_print, arg, counter);
}

	// str[0] = arg;
void	ft_result_c(int arg, t_printf *ob_print, int counter)
{
	char	str[2];

	str[0] = arg;
	str[1] = '\0';
	ft_flags(ob_print, str, counter);
	ft_update_result(ob_print, str, counter);
}
