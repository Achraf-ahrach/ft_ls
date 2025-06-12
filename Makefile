NAME = ft_ls
SRC = display.c ft_ls.c list_dir.c parse_args.c process.c sort.c utils.c
OBJ_DIR = obj
OBJ = $(SRC:.c=.o)
OBJF = $(addprefix $(OBJ_DIR)/, $(OBJ))

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJF)
	$(CC) $(CFLAGS) -o $@ $(OBJF)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

