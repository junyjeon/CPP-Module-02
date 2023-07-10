NAME		=	Fixed

CC			=	clang++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98
CFLAGS		+=	-fsanitize=address

BUILD_DIR	=	bulid

SRC		=	main.cpp Fixed.cpp
OBJ		=	$(patsubst %.cpp, $(BUILD_DIR)/%.o, $(SRC))

all:	$(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $^
	@echo "$(GREEN)SUCCESS!$(END)"

$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

clean:
	@$(RM) -r $(BUILD_DIR)
	@echo "${YELLOW}> All objects files of the Fixed have been deleted.❌${END}"

fclean: clean
	@$(RM) -r $(NAME)
	@echo "${YELLOW}> Cleaning of the Fixed has been done.❌${END}"

re: fclean all

.PHONY: all clean fclean re