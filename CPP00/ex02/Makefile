NAME = Account

CC = c++

CPP_FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Account.cpp \
	tests.cpp \

OBJS = $(SRCS:.cpp=.o)

RM = rm -rf

RED=\033[1;31m
GREEN=\033[1;32m
YELLOW=\033[1;33m
BLUE=\033[1;34m
MAGENTA=\033[1;35m
CYAN=\033[1;36m
RESET=\033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CPP_FLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)[Make : 'Account' is done ✓]$(RESET)"

%.o: %.cpp
	@$(CC) $(CPP_FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean:
	@$(RM) $(OBJS)
	@$(RM) $(NAME)
	@echo "$(BLUE)[fclean : 'Account' is done 🗑️ ​🧹​]$(RESET)"

re: fclean all

.PHONY: fclean all re
