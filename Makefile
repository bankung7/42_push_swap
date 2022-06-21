NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

LIBFT = libft

SRCS = $(wildcard src/*.c)

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	cp libft/libftprintf.a $(LIBFT).a
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT).a -o $(NAME)

clean:
	make clean -C $(LIBFT)
	$(RM) $(OBJS) *.dSYM

fclean: clean
	make fclean -C $(LIBFT)
	$(RM) $(NAME) $(LIBFT).a

re: fclean all

norm:
	norminette $(wildcard *.c) $(wildcard *.h)

.PHONY: all $(NAME) clean fclean re
