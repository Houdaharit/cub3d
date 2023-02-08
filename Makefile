NAME = cub3d

CC = cc

CFLAGS = -Wall -Wextra

SRC = main.c raycasting.c dda.c move.c minimap.c\
      parsing/parse_file.c parsing/get_next_line.c\
      parsing/get_next_line_utils.c parsing/split.c\
      parsing/more_parse.c parsing/parsing_utils.c close_win.c

#SRC = tst.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L /usr/X11/lib -lmlx -framework OpenGL -framework appKit -o $(NAME)
%.o:%.c
	$(CC) $(CFLAGS) -I /usr/X11/include -c $< -o $@
clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
