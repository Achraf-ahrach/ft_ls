NAME = ft_ls

### PATH ###
SRCS_PATH = srcs/
OBJ_DIR = obj
LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

### FILES ###
SRC = display.c ft_ls.c list_dir.c parse_args.c process.c sort.c utils.c
OBJ = $(SRC:.c=.o)

SRCS = $(addprefix $(SRCS_PATH), $(SRC))
OBJS = $(addprefix $(OBJ_DIR)/, $(OBJ))

### COMPILER FLAGS ###
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBFT)

$(OBJ_DIR)/%.o: $(SRCS_PATH)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

