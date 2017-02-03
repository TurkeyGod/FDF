# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrobinso <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/28 16:43:41 by mrobinso          #+#    #+#              #
#    Updated: 2016/11/28 16:43:43 by mrobinso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LDIR = ./libft
LIB = $(LDIR)/libft.a
IDIR = .

MLXDIR = ./minilibx_macos/ 
MLX = $(MLXDIR)/mlx.a

FINDLIB = -L$(LDIR) -lft -L$(MLXDIR) -lmlx -framework OpenGL -framework AppKit
INCLUDE = -I$(IDIR) -I$(LDIR) -I$(MLXDIR)

SRC = main.c window.c getshit.c drawline.c connect_thecrap.c moveyour_ass.c\
rotate_ho.c reset.c
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Werror -Wextra
 

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) $(FINDLIB) -o $(NAME) $(OBJ)

$(OBJ): $(SRC)
	gcc $(FLAGS) -c $(SRC) $(INCLUDE)

$(SRC): $(LIB) $(MLX)

$(LIB):
	make -C $(LDIR)
$(MLX):
	make -C $(MLXDIR)
clean:
	make clean -C $(LDIR)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LDIR)
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all

