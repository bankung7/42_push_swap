NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = $(wildcard src/*.c)

LIBFT = libft

RM = rm -rf

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	cp $(LIBFT)/libftprintf.a $(LIBFT).a
	$(CC) $(CFLAGS) -g $(OBJS) $(LIBFT).a -o $(NAME)

clean:
	make clean -C $(LIBFT)
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(LIBFT)
	$(RM) $(NAME) $(LIBFT).a

re: fclean all

.PHONY: all clean fclean re
