NAME = cub3d

CC = cc

CFLAGS = -Wall -Wextra

SRC = main.c raycasting.c\
      parsing/parse_file.c  parsing/get_next_line/get_next_line.c\
      parsing/get_next_line/get_next_line_utils.c parsing/split.c\
      parsing/more_parse.c parsing/parsing_utils.c parsing/ft_strnstr.c


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	#$(CC) $(CFLAGS) $(OBJ) -lmlx -framework OpenGL -framework appKit -o $(NAME)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
