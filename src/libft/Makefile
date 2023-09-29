# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-sa-- <mde-sa--@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/15 19:59:42 by mde-sa--          #+#    #+#              #
#    Updated: 2023/09/29 12:14:55 by mde-sa--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

SRC		=	ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c \
			ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c \
			ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isspace.c \
			ft_isquote.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c \
			ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
			ft_strtrim.c ft_split.c ft_itoa.c ft_striteri.c ft_strmapi.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			ft_lstmap.c ft_printf.c ft_printf_string.c ft_printf_base.c \
			ft_printf_char.c ft_printf_int.c ft_printf_ptr.c ft_printf_uns.c \
			ft_fprintf.c get_next_line.c get_next_line_utils.c ft_strcmp.c \
			ft_strcmp_input.c ft_free_tabs.c ft_atoi_base.c ft_swap.c \
			ft_abs.c ft_str_tolower.c ft_str_toupper.c ft_checkextension.c

OBJ		=	$(SRC:.c=.o)

RM		=	rm -f

all: $(NAME)

$(NAME): $(OBJ)
	@ ar -rcs $(NAME) $(OBJ)

.c.o:
	@ $(CC) $(CFLAGS) -c $< -I . -o $@

clean:
	@ rm -rf $(OBJ)

fclean: clean
	@ rm -rf $(NAME)

re: fclean all
