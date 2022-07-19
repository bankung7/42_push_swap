NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

LIBFT = libft

SRCS_DIR = srcs/
SRCS = push_swap.c \
		exit.c merge_sort.c operation.c \
		operation2.c parsing.c small_sort.c \
		sort.c structure.c util.c \
		util2.c
SRCS_B = checker.c \
		exit.c merge_sort.c operation.c \
		operation2.c parsing.c small_sort.c \
		sort.c structure.c util.c \
		util2.c

OBJS_DIR = objs/
OBJS = $(addprefix $(OBJS_DIR),$(SRCS:.c=.o))
OBJS_B = $(addprefix $(OBJS_DIR),$(SRCS_B:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	cp libft/libftprintf.a $(LIBFT).a
	$(CC) $(CFLAGS) -g $(OBJS) $(LIBFT).a -o $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $^ -o $@

bonus: $(OBJS_B)
	make -C $(LIBFT)
	cp libft/libftprintf.a $(LIBFT).a
	$(CC) $(CFLAGS) -g $(OBJS_B) $(LIBFT).a -o checker

clean:
	make clean -C $(LIBFT)
	$(RM) $(OBJS_DIR) *.dSYM

fclean: clean
	make fclean -C $(LIBFT)
	$(RM) $(NAME) $(LIBFT).a checker

re: fclean all

norm:
	norminette $(wildcard *.c) $(wildcard *.h)

.PHONY: all clean fclean re
