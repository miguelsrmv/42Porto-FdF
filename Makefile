# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-sa-- <mde-sa--@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/23 09:55:46 by mde-sa--          #+#    #+#              #
#    Updated: 2023/09/29 14:28:41 by mde-sa--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=   fdf

CC      = 	cc

CFLAGS   =  -Wall -Wextra -Werror -g

SRCDIR	=	src

INCDIR	=   includes

LIBFTDIR =  src/libft

MLXDIR  = 	minilibx-linux

SRC		=	main.c map_data.c pixel_data.c mlx_service.c hooks.c \
			calculations_rotation.c calculations_resize_center.c \
			bresenhaim.c draw.c data_clean.c

LIBS 	=   -L$(LIBFTDIR) -lft

MLXLIBS =   -L$(MLXDIR) -lmlx -lXext -lX11 -lm

OBJS	= 	$(addprefix $(SRCDIR)/, $(SRC:.c=.o))

RM      = 	rm -rf

INCFLAGS =  -I $(INCDIR) -I $(LIBFTDIR) -I $(MLXDIR)


all: libft minilibx $(NAME) 

$(NAME): $(OBJS) 
	@ $(CC) $(CFLAGS) $(OBJS) $(LIBS) $(MLXLIBS) -o $(NAME)

$(SRCDIR)/%.o: $(SRCDIR)/%.c $(INCDIR)/*.h $(MLXDIR)/*.h
	@ $(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@

libft:
	@ cd $(LIBFTDIR) && make -s && make -s clean

minilibx:
	@ cd minilibx-linux && make -s

clean:
	@ $(MAKE) -s -C $(LIBFTDIR) clean
	@ cd minilibx-linux && make clean
	@ $(RM) $(OBJS)

fclean: clean
	@ $(MAKE) -s -C $(LIBFTDIR) fclean
	@ cd minilibx-linux && make clean
	@ $(RM) $(NAME)

re: fclean all

download:
	@ wget https://cdn.intra.42.fr/document/document/20785/minilibx-linux.tgz
	@ tar -xzf minilibx-linux.tgz
	@ rm minilibx-linux.tgz

.PHONY: all clean fclean re libft minilibx download
