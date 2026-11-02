CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = gnl

SRC = main.c get_next_line.c

all: $(NAME)

$(NAME): $(SRC) get_next_line_utils.h
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
