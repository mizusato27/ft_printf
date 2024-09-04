/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizusato <mizusato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 20:50:35 by mizusato          #+#    #+#             */
/*   Updated: 2024/08/20 20:50:37 by mizusato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

static int	ft_putnbr_right(t_flag *s, unsigned int n, int len, int neg_flag)
{
	if (s->field > len && len >= s->accuracy)
	{
		ft_put_samechr_fd(' ', s->field - len + neg_flag, 1);
		if (neg_flag < 0)
			write(1, "-", 1);
		ft_putnbr_fd(n, 1);
	}
	else
	{
		ft_put_samechr_fd(' ', s->field - s->accuracy + neg_flag, 1);
		if (neg_flag < 0)
			write(1, "-", 1);
		ft_put_samechr_fd('0', s->accuracy - len, 1);
		ft_putnbr_fd(n, 1);
	}
	return (s->field);
}

static int	ft_putnbr_left(t_flag *s, unsigned int n, int len, int neg_flag)
{
	if (s->field > len && len >= s->accuracy)
	{
		if (neg_flag < 0)
			write(1, "-", 1);
		ft_putnbr_fd(n, 1);
		ft_put_samechr_fd(' ', s->field - len + neg_flag, 1);
	}
	else
	{
		if (neg_flag < 0)
			write(1, "-", 1);
		ft_put_samechr_fd('0', s->accuracy - len, 1);
		ft_putnbr_fd(n, 1);
		ft_put_samechr_fd(' ', s->field - s->accuracy + neg_flag, 1);
	}
	return (s->field);
}

static int	ft_put_number(t_flag *s, unsigned int n, int len, int neg_flag)
{
	if (len >= s->field && len >= s->accuracy)
	{
		if (neg_flag < 0)
		{
			write(1, "-", 1);
			len++;
		}
		ft_putnbr_fd(n, 1);
	}
	else if (s->accuracy > len && s->accuracy >= s->field)
	{
		if (neg_flag < 0)
			write(1, "-", 1);
		ft_put_samechr_fd('0', s->accuracy - len, 1);
		ft_putnbr_fd(n, 1);
		len = s->accuracy;
		if (neg_flag < 0)
			len++;
	}
	else if (s->flag <= 1)
		len = ft_putnbr_right(s, n, len, neg_flag);
	else
		len = ft_putnbr_left(s, n, len, neg_flag);
	return (len);
}

int	ft_print_decimal_bonus(t_flag *s, va_list *ap)
{
	long long	n;
	int			neg_flag;
	int			len;

	if (s->specifier == 0)
		n = va_arg(*ap, int);
	else
		n = (unsigned int)va_arg(*ap, int);
	neg_flag = 0;
	if (n < 0)
	{
		neg_flag = -1;
		n *= -1;
	}
	len = ft_count_len((unsigned int)n);
	len = ft_put_number(s, (unsigned int)n, len, neg_flag);
	return (len);
}
