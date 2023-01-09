# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acastilh <acastilh@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/27 19:48:08 by acastilh          #+#    #+#              #
#    Updated: 2022/12/13 16:00:05 by acastilh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

LIBFT		= ./libft
LIBFT_LIB	= ./libft/libft.a

SRCS	=	 source/push_swap.c \
			 source/utils.c \
			 source/push_move.c \
			 source/swap_move.c \
			 source/rotate_move.c \
			 source/reverse_rotate_move.c \
			 source/algorithm.c \
			 source/sort.c \

OBJS	=  $(SRCS:.c=.o)

CFLAGS	= -g -Wall -Wextra -Werror

$(NAME):	$(OBJS)
			make -C ./libft
			cc $^ $(CFLAGS) $(LIBFT_LIB) -o $(NAME)

all:		$(NAME)

clean:
			rm -f $(OBJS)
			make clean -C ./libft

fclean:		clean
			rm -f $(NAME)
			rm -f libft.a
			make fclean -C ./libft

re:			fclean all

.PHONY:		all clean fclean re
