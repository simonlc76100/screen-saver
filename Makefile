NAME = screensaver
PATH_SRC = ./src/
PATH_BIN = ./
PATH_OBJ = ./obj/
HEADER = ./includes/
FLAG = -Wall -Wextra -Werror
OPTION = -I $(HEADER)
SRC = $(PATH_SRC)main.c $(PATH_SRC)commandParser.c $(PATH_SRC)inputHandler.c $(PATH_SRC)screenSaver.c
OBJ = $(SRC:$(PATH_SRC)%.c=$(PATH_OBJ)%.o)

all: $(PATH_BIN)$(NAME)

$(PATH_BIN)$(NAME): $(OBJ)
	gcc $(FLAG) $(OBJ) -o $(PATH_BIN)$(NAME)

$(PATH_OBJ)%.o: $(PATH_SRC)%.c
	@mkdir -p $(PATH_OBJ)
	@mkdir -p $(PATH_BIN)
	gcc $(FLAG) $(OPTION) -c $< -o $@

clean:
	/bin/rm -f $(OBJ)
	/bin/rm -rf $(PATH_OBJ)

fclean: clean
	/bin/rm -f $(PATH_BIN)$(NAME)

re: fclean all

.PHONY: all clean fclean re