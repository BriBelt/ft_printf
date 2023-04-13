NAME = libftprintf.a

SRCS = ft_printf.c \
	   ft_printf_utils.c \


CC = gcc

CFLAGS += -Wall -Wextra -Werror

OBJECTS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rc libftprintf.a $(OBJECTS) ft_printf.h

.o.c:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
