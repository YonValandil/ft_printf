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
CFILES =	main debug ft_printf parser apply spec_format spec_type spec_unicode

SRCS =		$(CFILES:%=$(SRCS_DIR)%.c)
OBJS =		$(SRCS:%.c=$(OBJS_DIR)%.o)

all:
	make -C libft/
	$(CC) $(SRCS) -I$(HEADER) -Ilibft/ -L$(LIB_DIR) -l$(LIB) -o $(EXEC) #-fsanitize=address -g

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
