/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 09:23:59 by diegofranci       #+#    #+#             */
/*   Updated: 2022/04/17 20:21:43 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// Test
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef struct s_printf
{
	char	str[1000];
	char	convers[255];
	char	result[1000];
}	t_printf;

int	ft_printf(const char *str, ...);
int	ft_convert(va_list arg, t_printf *ob_print, const char *str);
int	ft_check_params(va_list arg, t_printf *ob_print, const char *str);

//str
void	ft_write(int n, char *str);
void	ft_inttostr(int nb, char *str);
void	ft_inttostrn(unsigned int nb, char *str);
void	ft_strtostr(char *str1, const char *str2);
void	ft_inttostrx(int nb, char *str, char *val);
int	ft_strfind(const char *str, int start, char c);
void	ft_strtostrnf(char *str1, const char *str2, int n);
void	ft_strtostrn(char *str1, const char *str2, int start);
void	ft_strtostrnn(char *str1, const char *str2, int start1, int start2 );

#endif
