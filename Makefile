# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/23 09:55:46 by mde-sa--          #+#    #+#              #
#    Updated: 2023/09/08 17:24:34 by mde-sa--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=   fdf

CC      = 	cc

CLAGS   =   -g

SFLAGS  =   -g -Wall -Wextra -Werror 

SRCDIR	=	src

INCDIR	=   includes

LIBFTDIR =  src/libft

MLXDIR  = 	mlx_linux

SRC		=	main.c

LIBS 	=   -L$(LIBFTDIR) -lft

MLXLIBS =   -L$(MLXDIR) -lmlx -lXext -lX11 -lm -lz -lft 

OBJS	= 	$(addprefix $(SRCDIR)/, $(SRC:.c=.o))

RM      = 	rm -rf


all: libft $(NAME) 

$(NAME): $(OBJS)
	@ $(CC) $(CFLAGS) $(OBJS) $(LIBS) $(MLXLIBS) -o $(NAME) 

$(SRCDIR)/%.o: $(SRCDIR)/%.c $(INCDIR)/*.h $(MLXDIR)/*.h
	@ $(CC) $(CFLAGS) -I $(INCDIR) -I $(LIBFTDIR) -I $(MLXDIR) -c $< -o $@

libft:
	@ cd $(LIBFTDIR) && make -s && make -s clean

clean:
	@ $(MAKE) -s -C $(LIBFTDIR) clean
	@ $(RM) $(OBJS) $(OBJSBON)

fclean: clean
	@ $(MAKE) -s -C $(LIBFTDIR) fclean
	@ $(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re libft