NAME = libftprintf.a

SRCS = ft_printf.c \
	   ft_printf_utils.c \


CC = gcc

CFLAGS += -Wall -Wextra -Werror

OBJECTS = ft_printf.o \
		  ft_printf_utils.o

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rc libftprintf.a $(OBJECTS) ft_printf.h

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
