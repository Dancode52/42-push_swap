CFILES = push_swap_input_check.c push_swap_input_creation.c push_swap_min_max_check.c push_swap_utils.c push_swap.c push_swap_list_utils1.c push_swap.c push_swap_list_utils2.c

OBJDIR = ./obj
OFILES = $(CFILES:%.c=$(OBJDIR)/%.o)
BONUS_OFILES = $(BONUS_FILES:%.c=%.o)
CFLAGS = -Wall -Werror -Wextra
CC = cc
LIBFT = libft.a
NAME = push_swap

all: $(NAME)

directory:
	if ! [ -d $(OBJDIR) ]; then mkdir -p $(OBJDIR);\
	fi

bonus:	$(OFILES) $(BONUS_OFILES)
	ar rcs $(NAME) $(OFILES) $(BONUS_OFILES)

clean:
	rm -rf $(NAME)
	rm -rf $(OFILES)
	$(MAKE) clean -C libft/42-Libft
	if [ -d $(OBJDIR) ]; then rmdir $(OBJDIR); \
	fi

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C libft/42-Libft

re: fclean $(NAME)


$(NAME): directory $(OFILES)
	$(MAKE) bonus -C libft/42-Libft
	$(CC) $(CFLAGS) $(CFILES) -o $(NAME) $(LIBFT)

$(OBJDIR)/%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY:  re fclean clean bonus all
