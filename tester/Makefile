NAME       = ft_printf_tester

HDRS       = ft_printf.h
SRCS       = tester.c ../ft_printf.c ../ft_print_char.c ../ft_print_number.c ../ft_print_pointer.c ../ft_putnbr.c
OBJS       = $(SRCS:.c=.o)

BONUS_SRCS =
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

CC         = gcc
CFLAGS     = -Wall -Wextra -Werror

ifdef WITH_BONUS
    CFLAGS += -DBONUS
    OBJS   += $(BONUS_OBJS)
    HDRS   += ../ft_printf_bonus.h
endif

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

bonus:
	@$(MAKE) WITH_BONUS=1

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

test: $(NAME)
	@./$(NAME)
	@$(MAKE) fclean

.PHONY: all bonus clean fclean re test
