/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizusato <mizusato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:43:06 by mizusato          #+#    #+#             */
/*   Updated: 2024/08/20 21:01:40 by mizusato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

typedef struct s_flag
{
	int	flag;
	int	field;
	int	accuracy;
	int	specifier;
}				t_flag;

int		ft_print_char_bonus(t_flag *s, va_list *ap);
int		ft_print_string_bonus(t_flag *s, va_list *ap);

int		ft_print_decimal_bonus(t_flag *s, va_list *ap);

int		ft_print_hexadecimal_bonus(t_flag *s, va_list *ap);

int		ft_print_pointer_bonus(t_flag *s, va_list *ap);

int		ft_store_info(const char **fmt, va_list *ap);

int		ft_isdigit(int c);
void	ft_put_samechr_fd(char c, int n, int fd);
void	ft_putnbr_hexa_bonus_fd(t_flag *s, unsigned int n, int fd);

void	ft_store_flag(t_flag *s, const char **fmt);
void	ft_store_field_width(t_flag *s, const char **fmt, va_list *ap);
void	ft_store_accuracy(t_flag *s, const char **fmt, va_list *ap);

#endif