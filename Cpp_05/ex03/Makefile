NAME := intern

CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++98

SRC := main.cpp\
	AForm.cpp\
	Bureaucrat.cpp\
	ShrubberyCreationForm.cpp\
	RobotomyRequestForm.cpp\
	Intern.cpp\
	PresidentialPardonForm.cpp

OBJ := $(SRC:.cpp=.o)

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
