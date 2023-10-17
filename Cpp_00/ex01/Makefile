NAME := phonebook

CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++98 -fsanitize=address

SRC := PhoneBook.cpp\
	Contact.cpp\
	main.cpp

OBJ := $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
