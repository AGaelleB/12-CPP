NAME = PhoneBook

CC = c++

CPP_FLAGS = -Wall -Wextra -Werror -std=c++98

OBJ_DIR = objs
OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.cpp=.o)))

SRC = srcs/main.cpp \
	srcs/PhoneBook.cpp \
	srcs/Contact.cpp \

RM = rm -rf

RED=\033[1;31m
GREEN=\033[1;32m
YELLOW=\033[1;33m
BLUE=\033[1;34m
MAGENTA=\033[1;35m
CYAN=\033[1;36m
RESET=\033[0m

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: srcs/%.cpp
	@$(CC) $(CPP_FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(CPP_FLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)[Make : 'PhoneBook' is done ​​✅​]$(RESET)"

clean:
	@$(RM) $(OBJ_DIR)

fclean:
	@$(RM) $(OBJ_DIR)
	@$(RM) $(NAME)
	@echo "$(BLUE)[fclean : 'PhoneBook' is done ​​🗑️ ​🧹​]$(RESET)"

re: fclean all

.PHONY: fclean all re
