
NAME = megaphone

CC = c++

CPP_FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = megaphone.cpp

RM = rm -rf

all: $(NAME)

$(NAME):
	@$(CC) $(CPP_FLAGS) $(SRC) -o $(NAME)
	@echo "\033[1;32m[Make : 'megaphone' is done ​​✅​]\033[0m"

fclean:
	@$(RM) $(NAME)
	@echo "\033[1;32m[fclean : 'megaphone' is done ​​🗑️ ​🧹​]\033[0m"

re: fclean all

.PHONY: fclean, all, re