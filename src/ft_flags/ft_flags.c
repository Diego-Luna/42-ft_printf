/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:17:47 by diegofranci       #+#    #+#             */
/*   Updated: 2022/04/29 15:21:21 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int  ft_flag_on(t_printf *ob_print, int counter)
{
  int i;

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

char  ft_get_flag(t_printf *ob_print, int position)
{
  int end;
  char *str;

  end = ft_findc(ob_print, position,')');
}

void	ft_flags(t_printf *ob_print, char *str, int counter)
{
  int i;
  char *flags;
  (void)str;

	printf("\n-- ON --");
  i = ft_flag_on(ob_print, counter);
  if (i >= 0)
  {
    flags = ft_get_flag(ob_print, i);
  }
}
