CFILES = push_swap_input_check_1.c push_swap_input_check_2.c push_swap_input_creation.c push_swap_list_utils1.c push_swap_list_utils2.c \
		push_swap_utils.c push_swap.c rotate.c \
		swap.c reverse.c push.c limit_atoi.c Small_Sorts.c

OBJDIR = ./obj
OFILES = $(CFILES:%.c=$(OBJDIR)/%.o)
BONUS_OFILES = $(BONUS_FILES:%.c=%.o)
CFLAGS = -Wall -Werror -Wextra -g
CC = cc
LIBFT = libft.a
NAME = push_swap

all: $(NAME)

directory:
	@if ! [ -d $(OBJDIR) ]; then mkdir -p $(OBJDIR);\
	fi

clean:
	@rm -rf $(NAME)
	@rm -rf $(OFILES)
	@$(MAKE) clean -C libft/42-Libft
	@if [ -d $(OBJDIR) ]; then rmdir $(OBJDIR); \
	fi

fclean: clean
	@echo "Look at us go! Taking a sledgehammer to your very delicate work!"
	@rm -f $(NAME)
	@$(MAKE) fclean -C libft/42-Libft

re: fclean $(NAME)


$(NAME): directory $(OFILES)
	@$(MAKE) bonus -C libft/42-Libft
	@$(CC) $(CFLAGS) $(CFILES) -o $(NAME) $(LIBFT)
	@echo "Look at us go! Making your project with our silly little techno-gremlin hands!"

$(OBJDIR)/%.o : %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

.PHONY:  re fclean clean bonus all
