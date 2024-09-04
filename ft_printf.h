/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizusato <mizusato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:23:39 by mizusato          #+#    #+#             */
/*   Updated: 2024/08/20 20:35:13 by mizusato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_strlen(char *str);
void	ft_putstr_n_fd(char *str, int n, int fd);
int		ft_print_char(va_list *ap);
int		ft_print_string(va_list *ap);
int		ft_print_percent(void);

int		ft_count_len(unsigned int n);
int		ft_count_hexa_len(unsigned int n);
int		ft_print_decimal(int s, va_list *ap);
int		ft_print_hexadecimal(int s, va_list *ap);

int		ft_count_pointer_len(unsigned long long n);
int		ft_print_pointer(va_list *ap);

int		ft_print_str(const char **fmt);
int		ft_store_specifier(const char **fmt);
int		ft_printf(const char *fmt, ...);

void	ft_putnbr_fd(unsigned int n, int fd);
void	ft_putnbr_hexa_fd(int s, unsigned int n, int fd);
void	ft_putnbr_pointer_fd(unsigned long long n, int fd);

#endif
