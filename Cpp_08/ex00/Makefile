NAME := easyfind

CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++98

SRC := main.cpp

OBJ := $(SRC:.cpp=.o)

ifeq ($(NAME),)
	NAME := a.out
endif

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
