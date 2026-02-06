PUSHSWAP_NAME    := push_swap
CLT_NAME	:= client
LIBFT := libft.a

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g

PUSHSWAP_DIR := pushswap
PUSHSWAP_FILE = push_swap_input_check_1.c push_swap_input_check_2.c push_swap_input_creation.c push_swap_list_utils1.c push_swap_list_utils2.c \
		push_swap_utils.c push_swap.c rotate.c \
		swap.c reverse.c push.c limit_atoi.c Small_Sorts.c

OBJ_DIR := obj

PUSHSWAP_OBJ_DIR := $(OBJ_DIR)/$(PUSHSWAP_DIR)
PUSHSWAP_OBJ := $(PUSHSWAP_FILE:.c=.o)

PUSHSWAP_FILES := $(addprefix ./$(PUSHSWAP_DIR)/, $(PUSHSWAP_FILE))
PUSHSWAP_OBJS := $(addprefix ./$(PUSHSWAP_OBJ_DIR)/, $(PUSHSWAP_OBJ))


all: build_push_swap

build_push_swap: $(LIBFT) directory $(PUSHSWAP_NAME)

directory:
	mkdir -p ./$(PUSHSWAP_OBJ_DIR)

$(PUSHSWAP_NAME): $(PUSHSWAP_OBJS)
	$(CC) $(CFLAGS) $(PUSHSWAP_OBJS) -o $(PUSHSWAP_NAME) $(LIBFT)

./$(PUSHSWAP_OBJ_DIR)/%.o: $(PUSHSWAP_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) bonus -C libft/42-Libft

clean:
	$(MAKE) clean -C libft/42-Libft
	rm -rf ./$(OBJ_DIR)

fclean: clean
	rm -f $(PUSHSWAP_NAME) $(CLT_NAME)
	$(MAKE) fclean -C libft/42-Libft

re: fclean all

.PHONY: all clean fclean re libft.a directory
