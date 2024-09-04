/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexadecimal_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizusato <mizusato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 20:52:31 by mizusato          #+#    #+#             */
/*   Updated: 2024/08/20 21:03:12 by mizusato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

static int	ft_putnbr_hexa_right(t_flag *s, unsigned int n, int len)
{
	if (s->field > len && len >= s->accuracy)
	{
		ft_put_samechr_fd(' ', s->field - len, 1);
		ft_putnbr_hexa_bonus_fd(s, n, 1);
	}
	else
	{
		ft_put_samechr_fd(' ', s->field - s->accuracy, 1);
		ft_put_samechr_fd('0', s->accuracy - len, 1);
		ft_putnbr_hexa_bonus_fd(s, n, 1);
	}
	return (s->field);
}

static int	ft_putnbr_hexa_left(t_flag *s, unsigned int n, int len)
{
	if (s->field > len && len >= s->accuracy)
	{
		ft_putnbr_hexa_bonus_fd(s, n, 1);
		ft_put_samechr_fd(' ', s->field - len, 1);
	}
	else
	{
		ft_put_samechr_fd('0', s->accuracy - len, 1);
		ft_putnbr_hexa_bonus_fd(s, n, 1);
		ft_put_samechr_fd(' ', s->field - s->accuracy, 1);
	}
	return (s->field);
}

static int	ft_put_hexa_number(t_flag *s, unsigned int n, int len)
{
	if (len >= s->field && len >= s->accuracy)
		ft_putnbr_hexa_bonus_fd(s, n, 1);
	else if (s->accuracy > len && s->accuracy >= s->field)
	{
		ft_put_samechr_fd('0', s->accuracy - len, 1);
		ft_putnbr_hexa_bonus_fd(s, n, 1);
		len = s->accuracy;
	}
	else if (s->flag <= 1)
		len = ft_putnbr_hexa_right(s, n, len);
	else
		len = ft_putnbr_hexa_left(s, n, len);
	return (len);
}

int	ft_print_hexadecimal_bonus(t_flag *s, va_list *ap)
{
	long long	n;
	int			len;

	n = (unsigned int)va_arg(*ap, int);
	len = ft_count_hexa_len((unsigned int)n);
	len = ft_put_hexa_number(s, (unsigned int)n, len);
	return (len);
}
