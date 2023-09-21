# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/23 09:55:46 by mde-sa--          #+#    #+#              #
#    Updated: 2023/09/21 21:58:28 by mde-sa--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=   fdf

CC      = 	cc

CFLAGS   =  -Wall -Wextra -Werror -g

SRCDIR	=	src

INCDIR	=   includes

LIBFTDIR =  src/libft

MLXDIR  = 	mlx_linux

SRC		=	main.c draw.c map_data.c pixel_data.c exit_error.c helper.c \
			window.c calculations_rotation.c calculations_resize_center.c \
			bresenhaim.c

LIBS 	=   -L$(LIBFTDIR) -lft

MLXLIBS =   -L$(MLXDIR) -lmlx -lXext -lX11 -lm -lz -lft

OBJS	= 	$(addprefix $(SRCDIR)/, $(SRC:.c=.o))

RM      = 	rm -rf

INCFLAGS =  -I $(INCDIR) -I $(LIBFTDIR) -I $(MLXDIR)


all: libft $(NAME)

$(NAME): $(OBJS)
	@ $(CC) $(CFLAGS) $(OBJS) $(LIBS) $(MLXLIBS) -o $(NAME)

$(SRCDIR)/%.o: $(SRCDIR)/%.c $(INCDIR)/*.h $(MLXDIR)/*.h
	@ $(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@

libft:
	@ cd $(LIBFTDIR) && make -s && make -s clean

clean:
	@ $(MAKE) -s -C $(LIBFTDIR) clean
	@ $(RM) $(OBJS)

fclean: clean
	@ $(MAKE) -s -C $(LIBFTDIR) fclean
	@ $(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re libft