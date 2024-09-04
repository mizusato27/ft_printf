/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizusato <mizusato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:50:47 by mizusato          #+#    #+#             */
/*   Updated: 2024/08/08 13:02:12 by mizusato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_len(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_count_hexa_len(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

int	ft_print_decimal(int s, va_list *ap)
{
	long long	n;
	int			len;

	if (s == 0)
		n = va_arg(*ap, int);
	else
		n = (unsigned int)va_arg(*ap, int);
	len = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
		len++;
	}
	len += ft_count_len((unsigned int)n);
	ft_putnbr_fd(n, 1);
	return (len);
}

int	ft_print_hexadecimal(int s, va_list *ap)
{
	long long	n;
	int			len;

	n = (unsigned int)va_arg(*ap, int);
	len = ft_count_hexa_len((unsigned int)n);
	ft_putnbr_hexa_fd(s, n, 1);
	return (len);
}
