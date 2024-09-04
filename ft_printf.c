/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizusato <mizusato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:25:01 by mizusato          #+#    #+#             */
/*   Updated: 2024/08/20 20:34:51 by mizusato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(const char **fmt)
{
	const char	*start;

	start = *fmt;
	while (**fmt && **fmt != '%')
		(*fmt)++;
	write(1, start, *fmt - start);
	return (*fmt - start);
}

int	ft_store_specifier(const char **fmt)
{
	if (**fmt == 'd' || **fmt == 'i')
		return (0);
	if (**fmt == 'u')
		return (1);
	if (**fmt == 'x')
		return (2);
	if (**fmt == 'X')
		return (3);
	if (**fmt == 'c')
		return (4);
	if (**fmt == 's')
		return (5);
	if (**fmt == 'p')
		return (6);
	if (**fmt == '%')
		return (7);
	return (-1);
}

#ifdef BONUS

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	va_start(ap, fmt);
	if (!fmt)
		len = -1;
	while (len >= 0 && *fmt)
	{
		if (*fmt != '%')
			len += ft_print_str(&fmt);
		else
		{
			fmt++;
			if (*fmt == 0)
				break ;
			len += ft_store_info(&fmt, &ap);
		}
	}
	va_end(ap);
	return (len);
}

#else

static int	ft_allot_specifier(const char **fmt, va_list *ap)
{
	int	len;
	int	specifier;

	len = 0;
	specifier = ft_store_specifier(fmt);
	if (specifier == 0 || specifier == 1)
		len = ft_print_decimal(specifier, ap);
	else if (specifier == 2 || specifier == 3)
		len = ft_print_hexadecimal(specifier, ap);
	else if (specifier == 4)
		len = ft_print_char(ap);
	else if (specifier == 5)
		len = ft_print_string(ap);
	else if (specifier == 6)
		len = ft_print_pointer(ap);
	else if (specifier == 7)
		len = ft_print_percent();
	return (len);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	va_start(ap, fmt);
	if (!fmt)
		len = -1;
	while (len >= 0 && *fmt)
	{
		if (*fmt != '%')
			len += ft_print_str(&fmt);
		else
		{
			fmt++;
			if (*fmt == 0)
				break ;
			len += ft_allot_specifier(&fmt, &ap);
			fmt++;
		}
	}
	va_end(ap);
	return (len);
}

#endif

// #include <stdio.h>
// int	main(void)
// {

// }
