# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vnilprap <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/17 21:12:05 by vnilprap          #+#    #+#              #
#    Updated: 2022/05/17 21:17:23 by vnilprap         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

INC = inc/

LIBFT = libft
LIBFT_INC = $(LIBFT)/libft.h

SRCS_DIR = srcs/
SRCS = ft_check.c ft_convertcs.c ft_convertdi.c \
       ft_convertp.c ft_convertux.c ft_printf.c \
	   ft_util.c ft_util2.c

OBJS_DIR = objs/
OBJS = $(addprefix $(OBJS_DIR),$(SRCS:.c=.o))

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	cp $(LIBFT)/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJS)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(LIBFT_INC)
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -I/$(INC) -c $< -o $@

clean:
	make clean -C $(LIBFT)
	$(RM) $(OBJS_DIR)

fclean: clean
	make fclean -C $(LIBFT)
	$(RM) $(NAME)

re: fclean all

bonus: $(NAME)

.PHONY:	all clean fclean re