/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizusato <mizusato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 20:43:41 by mizusato          #+#    #+#             */
/*   Updated: 2024/08/20 20:45:49 by mizusato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

int	ft_print_char_bonus(t_flag *s, va_list *ap)
{
	char	c;
	int		len;

	c = (char)va_arg(*ap, int);
	len = 1;
	if (s->flag <= 1)
	{
		if (s->field > 1)
		{
			ft_put_samechr_fd(' ', s->field - 1, 1);
			len = s->field;
		}
		write(1, &c, 1);
	}
	else
	{
		write(1, &c, 1);
		if (s->field > 1)
		{
			ft_put_samechr_fd(' ', s->field - 1, 1);
			len = s->field;
		}
	}
	return (len);
}

static int	ft_putstr_printf(t_flag *s, char *str, int len)
{
	if (len > s->accuracy && s->accuracy > 0)
		len = s->accuracy;
	if (len >= s->field)
		ft_putstr_n_fd(str, len, 1);
	else if (s->flag <= 1)
	{
		ft_put_samechr_fd(' ', s->field - len, 1);
		ft_putstr_n_fd(str, len, 1);
		len = s->field;
	}
	else
	{
		ft_putstr_n_fd(str, len, 1);
		ft_put_samechr_fd(' ', s->field - len, 1);
		len = s->field;
	}
	return (len);
}

int	ft_print_string_bonus(t_flag *s, va_list *ap)
{
	char	*str;
	int		len;

	str = (char *)va_arg(*ap, char *);
	if (!str)
	{
		str = "(null)";
		ft_putstr_n_fd(str, 6, 1);
		return (6);
	}
	len = ft_strlen(str);
	len = ft_putstr_printf(s, str, len);
	return (len);
}
