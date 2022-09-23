NAME =		pipex
HEADER =	./includes
SRC_DIR =	./sources
OBJ_DIR =	./objects
LIBFT_DIR =	./ft_printf
LIBFT =		$(addprefix $(LIBFT_DIR)/, libftprintf.a)
SRC_FILES =	*.c
SRC =		$(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ =		$(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

CFLAGS =	-g3 -O3 -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	cc $(OBJ) $(LIBFT) $(CFLAGS) -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	@mkdir -p $(OBJ_DIR)
	cc -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)
	make fclean -C $(LIBFT_DIR)

re: fclean all
