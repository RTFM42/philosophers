# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/22 16:27:12 by yushsato          #+#    #+#              #
#    Updated: 2024/09/22 16:27:13 by yushsato         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
SRCS	= forks.c \
		  main.c \
		  actions.c \
		  philos.c \
		  start.c \
		  util/getms.c \
		  util/usage.c \
		  util/config.c \
		  lib/ft_putstr_fd.c \
		  lib/ft_strlen.c \
		  lib/ft_atoi.c \
		  lib/channel/safe.c \
		  lib/channel/channel.c
OBJS	= $(SRCS:.c=.o)
INCLUDE	= -I./include \
		  -I./lib/include \
		  -I./lib/channel/include

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
