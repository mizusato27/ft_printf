# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mizusato <mizusato@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/07 15:16:46 by mizusato          #+#    #+#              #
#    Updated: 2024/10/24 18:17:01 by mizusato         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME       = libftprintf.a

CC         = cc
CFLAGS     = -Wall -Wextra -Werror

HDRS       = ft_printf.h
SRCS       = ft_print_char.c ft_print_number.c ft_print_pointer.c ft_printf.c ft_putnbr.c
OBJS       = $(SRCS:.c=.o)

BONUS_SRCS = ft_print_char_bonus.c ft_print_decimal_bonus.c ft_print_hexadecimal_bonus.c ft_print_pointer_bonus.c ft_printf_bonus.c ft_putnbr_bonus.c ft_store_func_bonus.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

ifdef WITH_BONUS
    CFLAGS += -DBONUS
    OBJS   += $(BONUS_OBJS)
    HDRS   += ft_printf_bonus.h
endif

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

# %.o: %.c
# 	$(CC) $(CFLAGS) -I$(HDRS) -c $< -o $@
%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) -I. -c $< -o $@

bonus:
	@$(MAKE) WITH_BONUS=1

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re