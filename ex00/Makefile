RESET=\033[0m
BOLD=\033[1m
RED=\033[31m
GREEN=\033[32m
YELLOW=\033[33m
BLUE=\033[34m
MAGENTA=\033[35m
CYAN=\033[36m
WHITE=\033[37m
ORANGE=\033[38;5;208m

BG_RED=\033[41m
BG_GREEN=\033[42m
BG_YELLOW=\033[43m
BG_BLUE=\033[44m
BG_MAGENTA=\033[45m
BG_CYAN=\033[46m
BG_WHITE=\033[47m

CC = g++
CFLAGS = -Wall -Werror -Wextra 
RM = rm -rf

NAME =  megaphone
INCLUDES = 
SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ) $(INCLUDES)
	@echo "$(ORANGE)$(BOLD)building $@...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ) -o $@
	@echo "$(GREEN)$@ is ready to use$(RESET)"

%.o : %.cpp $(INCLUDES)
	@echo "$(YELLOW)$(BOLD)compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@$(RM) $(OBJ)

fclean : clean
	@$(RM) $(NAME)

re : fclean all

.PHONY : clean