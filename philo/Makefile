# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yussato <yussato@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/30 23:19:07 by yushsato          #+#    #+#              #
#    Updated: 2024/09/11 18:58:19 by yussato          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
SRCS	= ./lib/channel/channel.c \
		  ./lib/ft_atoi.c \
		  ./lib/ft_getms.c \
		  ./lib/ft_putstr_fd.c \
		  ./lib/ft_strlen.c \
		  ./main.c \
		  ./util/config.c \
		  ./util/usage.c
OBJS	= $(SRCS:.c=.o)
INCLUDE	= -I./include -I./lib/channel/include

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(INCLUDE)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

__debug_configure__:
	$(eval CC := gcc)
	$(eval CFLAGS := -g -fsanitize=address -Wall -Wextra -Werror)

debug: fclean __debug_configure__ all

norminette: $(SRCS)
	norminette $^

norm: norminette

.PHONY: all clean fclean re debug norminette norm
