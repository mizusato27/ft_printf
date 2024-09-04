/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizusato <mizusato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:53:39 by mizusato          #+#    #+#             */
/*   Updated: 2024/08/08 14:53:42 by mizusato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd(unsigned int n, int fd)
{
	if (n > 9)
		ft_putnbr_fd((n / 10), fd);
	write(fd, &"0123456789"[n % 10], 1);
}

void	ft_putnbr_hexa_fd(int s, unsigned int n, int fd)
{
	if (s == 2)
	{
		if (n > 15)
			ft_putnbr_hexa_fd(s, (n / 16), fd);
		write(fd, &"0123456789abcdef"[n % 16], 1);
	}
	else if (s == 3)
	{
		if (n > 15)
			ft_putnbr_hexa_fd(s, (n / 16), fd);
		write(fd, &"0123456789ABCDEF"[n % 16], 1);
	}
}

void	ft_putnbr_pointer_fd(unsigned long long n, int fd)
{
	if (n > 15)
		ft_putnbr_pointer_fd((n / 16), fd);
	write(fd, &"0123456789abcdef"[n % 16], 1);
}
