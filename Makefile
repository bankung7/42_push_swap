PS_NAME = push_swap
CHK_NAME = checker

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NPD_FLAG = --no-print-directory

RM = rm -rf

LIBFT_DIR = libft
LIBFT = libft/libftprintf.a

SRCS_DIR = srcs/
SRCS = exit.c merge_sort.c operation.c \
	operation2.c parsing.c small_sort.c \
	sort.c structure.c util.c \
	util2.c
PS = push_swap.c
CHK = checker.c

OBJS_DIR = objs/
OBJS = $(addprefix $(OBJS_DIR),$(SRCS:.c=.o))
OBJS_PS = $(addprefix $(OBJS_DIR),$(PS:.c=.o))
OBJS_CHK = $(addprefix $(OBJS_DIR),$(CHK:.c=.o))

all: $(PS_NAME)

bonus: $(CHK_NAME)

$(PS_NAME): $(OBJS) $(OBJS_PS) $(LIBFT)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "Push swap is ready"

$(CHK_NAME): $(OBJS) $(OBJS_CHK) $(LIBFT)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "Checker is ready"

$(LIBFT):
	@make -C $(LIBFT_DIR) $(NPD_FLAG)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $^ -o $@

clean:
	@make clean -C $(LIBFT_DIR) $(NPD_FLAG)
	@$(RM) $(OBJS_DIR) *.dSYM
	@echo "Push swap or/and Checker objects were cleaned"

fclean: clean
	@make fclean -C $(LIBFT_DIR) $(NPD_FLAG)
	@$(RM) $(PS_NAME) $(CHK_NAME)
	@echo "Push swap or/and Checker was forcely cleaned"

re: fclean all

.PHONY: all clean fclean re
