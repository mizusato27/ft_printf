/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizusato <mizusato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:05:43 by mizusato          #+#    #+#             */
/*   Updated: 2024/08/08 14:45:17 by mizusato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr_n_fd(char *str, int n, int fd)
{
	int	i;

	i = 0;
	while (str[i] && i < n)
	{
		write(fd, &str[i], 1);
		i++;
	}
}

int	ft_print_char(va_list *ap)
{
	char	c;

	c = (char)va_arg(*ap, int);
	write(1, &c, 1);
	return (1);
}

int	ft_print_string(va_list *ap)
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
	ft_putstr_n_fd(str, len, 1);
	return (len);
}

int	ft_print_percent(void)
{
	write(1, "%", 1);
	return (1);
}
