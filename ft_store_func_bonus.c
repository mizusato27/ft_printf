/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store_func_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizusato <mizusato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 20:41:51 by mizusato          #+#    #+#             */
/*   Updated: 2024/08/20 20:41:53 by mizusato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

void	ft_store_flag(t_flag *s, const char **fmt)
{
	while (**fmt && **fmt == '0')
	{
		s->flag = 1;
		(*fmt)++;
	}
	while (**fmt && **fmt == '-')
	{
		s->flag = 2;
		(*fmt)++;
	}
}

void	ft_store_field_width(t_flag *s, const char **fmt, va_list *ap)
{
	if (**fmt && ft_isdigit(**fmt))
	{
		s->field = 0;
		while (ft_isdigit(**fmt))
		{
			s->field = (s->field) * 10 + (**fmt - '0');
			(*fmt)++;
		}
	}
	else if (**fmt == '*')
	{
		s->field = va_arg(*ap, int);
		if (s->field < 0)
		{
			s->field *= -1;
			s->flag = 2;
		}
		(*fmt)++;
	}
}

void	ft_store_accuracy(t_flag *s, const char **fmt, va_list *ap)
{
	if (**fmt && ft_isdigit(**fmt))
	{
		while (ft_isdigit(**fmt))
		{
			s->accuracy = (s->accuracy) * 10 + (**fmt - '0');
			(*fmt)++;
		}
	}
	else if (**fmt == '*')
	{
		s->accuracy = va_arg(*ap, int);
		if (s->accuracy < 0)
			s->accuracy = -1;
		(*fmt)++;
	}
}