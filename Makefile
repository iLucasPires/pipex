NAME =		pipex
HEADER =	./includes
SRC_DIR =	./sources
OBJ_DIR =	./objects
BONUS_DIR =	./bonus
LIBFT_DIR =	./libft
LIBFT =		$(addprefix $(LIBFT_DIR)/, libftprintf.a)

SRC_FILES =	pipex.c manager_process.c handle_arguments.c

BONUS_FILES = pipex_bonus.c manager_process_bonus.c handle_arguments_bonus.c

SRC =		$(addprefix $(SRC_DIR)/, $(SRC_FILES))

BONUS =		$(addprefix $(OBJ_DIR)/, $(BONUS_FILES:.c=.o))
OBJ =		$(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
CFLAGS =	-g3 -O3 -Wall -Wextra -Werror

all: $(NAME)

bonus:
	@make OBJ="$(BONUS)" all --no-print-directory

$(NAME): $(OBJ) $(LIBFT)
	cc $(OBJ) $(LIBFT) $(CFLAGS) -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	@mkdir -p $(OBJ_DIR)
	cc $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(BONUS_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re bonus