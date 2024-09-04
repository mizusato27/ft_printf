/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizusato <mizusato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 20:42:10 by mizusato          #+#    #+#             */
/*   Updated: 2024/08/20 20:42:12 by mizusato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

static void	ft_set_flags(t_flag *s)
{
	s->flag = 0;
	s->field = -1;
	s->accuracy = -1;
	s->specifier = -1;
}

static int	ft_print_specifier(t_flag *s, va_list *ap)
{
	int	len;

	len = 0;
	if (s->specifier == 0 || s->specifier == 1)
		len = ft_print_decimal_bonus(s, ap);
	else if (s->specifier == 2 || s->specifier == 3)
		len = ft_print_hexadecimal_bonus(s, ap);
	else if (s->specifier == 4)
		len = ft_print_char_bonus(s, ap);
	else if (s->specifier == 5)
		len = ft_print_string_bonus(s, ap);
	else if (s->specifier == 6)
		len = ft_print_pointer_bonus(s, ap);
	else if (s->specifier == 7)
		len = ft_print_percent();
	return (len);
}

int	ft_store_info(const char **fmt, va_list *ap)
{
	int			len;
	t_flag		*cs_info;

	cs_info = (t_flag *)malloc(sizeof(t_flag));
	if (!cs_info)
		return (0);
	len = 0;
	ft_set_flags(cs_info);
	ft_store_flag(cs_info, fmt);
	ft_store_field_width(cs_info, fmt, ap);
	if (**fmt == '.')
	{
		cs_info->accuracy = 0;
		(*fmt)++;
		ft_store_accuracy(cs_info, fmt, ap);
	}
	cs_info->specifier = ft_store_specifier(fmt);
	len = ft_print_specifier(cs_info, ap);
	(*fmt)++;
	free(cs_info);
	return (len);
}
