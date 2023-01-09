# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acastilh <acastilh@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/24 15:44:11 by acastilh          #+#    #+#              #
#    Updated: 2022/11/26 23:26:07 by acastilh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

INCS	= include/
SRC_DIR = source/
OBJ_DIR = obj/

#Sources

LIBFT_DIR	= lib/
LIBFT		= ft_atoi ft_bzero ft_calloc ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint ft_itoa ft_memchr ft_memcmp ft_memcpy ft_memmove ft_memset ft_putchar_fd ft_putendl_fd ft_putnbr_fd ft_putstr_fd ft_split ft_strchr ft_strdup ft_striteri ft_strjoin ft_strlcat ft_strlcpy ft_strlen ft_strmapi ft_strncmp ft_strnstr ft_strrchr ft_strtrim ft_substr ft_tolower ft_toupper

GNL_DIR 	= get_next_line/
GNL 		= get_next_line get_next_line_utils

FTPRINTF_DIR 	= ft_printf/
FTPRINTF		= arg_format ft_utoa pf_ft_itoa put_hexadecimal put_string ft_printf put_char put_pointer

CC		= cc
RM		= rm -f
AR		= ar rcs

CFLAGS	= -Wall -Wextra -Werror -I

SRC_FILES+=$(addprefix $(LIBFT_DIR),$(LIBFT))
SRC_FILES+=$(addprefix $(GNL_DIR),$(GNL))
SRC_FILES+=$(addprefix $(FTPRINTF_DIR),$(FTPRINTF))

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJF		= .cache_exists

$(NAME):	$(OBJ)
			$(AR) $(NAME) $(OBJ)

all:	$(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | ${OBJF}
			@$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)
			@mkdir -p $(OBJ_DIR)$(LIBFT_DIR)
			@mkdir -p $(OBJ_DIR)$(GNL_DIR)
			@mkdir -p $(OBJ_DIR)$(FTPRINTF_DIR)
			@touch $(OBJF)

clean:
		@$(RM) -r $(OBJ_DIR)
		@$(RM) $(OBJF)

fclean:	clean
		$(RM) $(NAME)

re:	fclean all

.PHONY:	all  clean fclean re
