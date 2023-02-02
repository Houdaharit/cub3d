NAME = cub3d

CC = cc

CFLAGS = -Wall -Wextra

SRC = main.c move.c init.c intersection.c raycasting.c render.c\
	  ver_intersection.c hor_intersection.c\
      parsing/parse_file.c parsing/get_next_line.c\
      parsing/get_next_line_utils.c parsing/split.c\
      parsing/more_parse.c parsing/parsing_utils.c close_win.c

#SRC = tst.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) -lm

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
