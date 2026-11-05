CC = cc
BUFFER_SIZE ?= 11
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=$(BUFFER_SIZE)
NAME = gnl

SRC = main.c get_next_line.c get_next_line_utils.c

all: $(NAME)

$(NAME): $(SRC) get_next_line.h
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
