CFLAGS = -Wall -Werror -Wextra
CC = cc
NAME = my_libft.a
LIB1 = 42-ft_printf/libftprintf.a
LIB2 = 42-Libft/libft.a

all: $(NAME)

$(NAME):
	if ! [ -d temporary ]; then mkdir temporary;\
	fi
	if ! [ -d $(LIB1) ]; then $(MAKE) -C 42-ft_printf;\
	fi
	cp $(LIB1) temporary
	if ! [ -d $(LIB2) ]; then $(MAKE) -C 42-Libft;\
	fi
	cp $(LIB2) temporary

.PHONY:  re fclean clean bonus all


