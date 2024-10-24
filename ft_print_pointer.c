/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizusato <mizusato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:45:44 by mizusato          #+#    #+#             */
/*   Updated: 2024/10/24 17:46:04 by mizusato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_pointer_len(unsigned long long n)
{
	int	i;

	i = 2;
	if (n == 0)
		return (i + 1);
	while (n != 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

int	ft_print_pointer(va_list *ap)
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
	ft_putnbr_pointer_fd(n, 1);
	return (len);
}
