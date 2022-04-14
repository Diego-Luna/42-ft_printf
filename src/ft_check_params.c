/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 10:03:25 by diegofranci       #+#    #+#             */
/*   Updated: 2022/04/14 13:16:13 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

	//ob_print.convers, "s", ft_strlen(ob_print.convers)
void	ft_add(t_printf *ob_print, char c)
{
	size_t	i;

	i = ft_strlen(ob_print->convers);
	ob_print->convers[i] = c;
	ob_print->convers[i + 1] = '\0';
	printf("-> El str:%s \n", ob_print->convers);
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
			ft_add(ob_print, s[i + 1]);
		}
		else if (s[i] == c && !ft_check(s[i + 1]) && s[i - 1] != '%')
		{
			return (-1);
		}
		i++;
	}
	return (num);
}

int	ft_check_params(va_list arg, t_printf *ob_print, const char *str)
{
	int	num;

	(void)arg;
	num = ft_strchrall(str, '%', ob_print);
	printf("--> 1-> Valor de num: %i\n", num);
	if (num < 0)
	{
		return (-1);
	}
	return (1);
}

/*
int AddStringd(char *str, ...)
{
  int i;
  int ii;
  va_list ptr1;
  va_list ptr2;
  char *stringValue;

  va_start(ptr1, str);
  va_copy(ptr2, ptr1);

  i = 1;
  stringValue = va_arg(ptr2, char *);
  while (stringValue)
  {
    printf("\n -->stringValue: %s", stringValue);
    stringValue = va_arg(ptr2, char *);
    i++;
  }
  ii = i;
  while (ii > 1)
  {
    printf("\n-> El valor de va_arg(ptr2, int): %s \n", va_arg(ptr1, char *));
    ii--;
  }
  // Ending argument list traversal
  va_end(ptr1);
  va_end(ptr2);

  return i;
}
*/