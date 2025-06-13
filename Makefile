NAME = ft_ls

### PATH ###
SRCS_PATH = srcs/
OBJ_DIR = obj
LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a
PRINTF_DIR = ft_printf/
PRINTF = $(PRINTF_DIR)ft_printf.a

### FILES ###
SRC = display.c ft_ls.c list_dir.c parse_args.c process.c sort.c utils.c
OBJ = $(SRC:.c=.o)

SRCS = $(addprefix $(SRCS_PATH), $(SRC))
OBJS = $(addprefix $(OBJ_DIR)/, $(OBJ))

### COMPILER FLAGS ###
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBFT) $(PRINTF)

$(OBJ_DIR)/%.o: $(SRCS_PATH)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)
	make clean -C $(PRINTF_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(PRINTF_DIR)

re: fclean all

