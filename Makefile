NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

LIBFT = libft

SRCS = src/push_swap.c $(wildcard src/files/*.c)

SRCS_BONUS = src/checker.c $(wildcard src/files/*.c)

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	cp libft/libftprintf.a $(LIBFT).a
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT).a -o $(NAME)

bonus: $(OBJS_BONUS)
	make -C $(LIBFT)
	cp libft/libftprintf.a $(LIBFT).a
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT).a -o checker

clean:
	make clean -C $(LIBFT)
	$(RM) $(OBJS) $(OBJS_BONUS) *.dSYM

fclean: clean
	make fclean -C $(LIBFT)
	$(RM) $(NAME) $(LIBFT).a checker

re: fclean all

norm:
	norminette $(wildcard *.c) $(wildcard *.h)

.PHONY: all $(NAME) clean fclean re
