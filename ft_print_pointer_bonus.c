/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizusato <mizusato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 20:59:04 by mizusato          #+#    #+#             */
/*   Updated: 2024/10/24 17:48:08 by mizusato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

static int	ft_put_pointer(t_flag *s, unsigned long long n, int len)
{
	if (len - 2 >= s->field)
		ft_putnbr_pointer_fd(n, 1);
	else if (s->flag <= 1)
	{
		ft_put_samechr_fd(' ', s->field - len - 2, 1);
		ft_putnbr_pointer_fd(n, 1);
		len = s->field;
	}
	else
	{
		ft_putnbr_pointer_fd(n, 1);
		ft_put_samechr_fd(' ', s->field - len - 2, 1);
		len = s->field;
	}
	return (len);
}

int	ft_print_pointer_bonus(t_flag *s, va_list *ap)
{
	unsigned long long	n;
	int					len;

	n = (unsigned long long)va_arg(*ap, void *);
	if (n == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	len = ft_count_pointer_len(n);
	len = ft_put_pointer(s, n, len);
	return (len);
}
