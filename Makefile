# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hharit <hharit@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/12 20:17:40 by ahakam            #+#    #+#              #
#    Updated: 2023/02/17 20:55:32 by hharit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = main.c raycasting.c  init.c  hor_intersection.c intersection.c ver_intersection.c\
      hooks.c parsing/parse_file.c parsing/get_next_line.c render.c\
      parsing/get_next_line_utils.c parsing/split.c move.c parsing/trim.c\
      parsing/more_parse.c parsing/parsing_utils.c close_win.c\
      minimap.c init_tex.c floorAndCellings.c compare_ray_dis.c parsing/colors.c

#SRC = tst.c
 
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -lmlx -framework OpenGL -framework appKit -o $(NAME)

%.o:%.c
	$(CC) $(CLFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
