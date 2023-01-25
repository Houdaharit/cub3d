NAME = cub3d

CC = cc

CFLAGS = -Wall -Wextra

SRC = main.c raycasting.c dda.c move.c minimap.c init.c init_dir.c\
	  init_tex.c textures_calcul.c\
      parsing/parse_file.c parsing/get_next_line.c\
      parsing/get_next_line_utils.c parsing/split.c\
      parsing/more_parse.c parsing/parsing_utils.c close_win.c

#SRC = tst.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -lmlx -framework OpenGL -framework appKit -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
