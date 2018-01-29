.PHONY: clean fclean re
.SUFFIXES:

CC =		gcc
EXEC =		ft_printf
LIB =		ft
SRCS_DIR =	./src/
OBJS_DIR =	./
LIB_DIR = 	./libft/
HEADER =	./include/
CFLAGS =	-Wall -Werror -Wextra -g
ARFLAGS =	-rcs
CFILES =	main ft_printf debug

SRCS =		$(CFILES:%=$(SRCS_DIR)%.c)
OBJS =		$(SRCS:%.c=$(OBJS_DIR)%.o)

all:
	make -C libft/
	$(CC) $(SRCS) -I$(HEADER) -Ilibft/ -L$(LIB_DIR) -l$(LIB) -o $(EXEC)

clean:
	rm -f $(OBJS)
	@make -C libft/ clean
	@echo clean $@ Done !

fclean:		clean
	rm -f $(EXEC)
	@make -C libft/ fclean
	@echo fclean $@ Done !

re:			fclean all

##-Lminilibx_macos
