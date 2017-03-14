# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/25 18:53:08 by mmartins          #+#    #+#              #
#    Updated: 2017/03/14 18:35:04 by mmartins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		fdf
CC =		gcc
CFLAGS =	-Wall -Wextra -Werror -fsanitize=address -I.

SRCS =		main.c \
			get_next_line.c \
			display.c \
			draw.c \
			keyhook.c \
			new_points.c \
			color.c \
			error.c \

OBJS =		$(SRCS:.c=.o)

LIBFT_PATH =	./libft

all:	$(NAME)

$(NAME):	$(OBJS)
	make -C $(LIBFT_PATH)
	$(CC) $(CFLAG) $(SRCS) -I./mlx/mlx.h -framework OpenGL -framework Appkit -L./libft -lft -lmlx -o $(NAME) -g

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_PATH) clean

fclean:	clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

re:	fclean all

.PHONY: all clean fclean re
