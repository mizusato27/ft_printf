/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizusato <mizusato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 20:41:28 by mizusato          #+#    #+#             */
/*   Updated: 2024/10/24 18:20:57 by mizusato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	ft_put_samechr_fd(char c, int n, int fd)
{
	int	i;

	i = 0;
	while (i < n)
	{
		write(fd, &c, 1);
		i++;
	}
}

void	ft_putnbr_hexa_bonus_fd(t_flag *s, unsigned int n, int fd)
{
	if (s->specifier == 2)
	{
		if (n > 15)
			ft_putnbr_hexa_bonus_fd(s, (n / 16), fd);
		write(fd, &"0123456789abcdef"[n % 16], 1);
	}
	else if (s->specifier == 3)
	{
		if (n > 15)
			ft_putnbr_hexa_bonus_fd(s, (n / 16), fd);
		write(fd, &"0123456789ABCDEF"[n % 16], 1);
	}
}
