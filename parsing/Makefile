NAME = cube_parse

CC= gcc

CFLAGS = #-fsanitize=address -g #-Wall -Werror -Wextra
	
SRC = parse_file.c  get_next_line.c get_next_line_utils.c split.c main.c more_parse.c parsing_utils.c

all : $(NAME)

$(NAME) : $(SRC)
	$(CC) $(CFLAGS) $(SRC) $(INCLUDES) -o $(NAME)

clean :
	rm -rf $(NAME)

fclean : clean

re : fclean all
