CC =			gcc
NAME =			libft_printf.a
EXEC =			ft_printf
SRC_DIR =		./src/
OBJ_DIR =		./obj/
HEADER_DIR =	./include/
LIBFT_DIR = 	./libft/
LIBFT =			$(LIBFT_DIR)libft.a
CFLAGS =		-Wall -Werror -Wextra
DEBUG_FLAGS =	-fsanitize=address -g
ARFLAGS =		-rcs
CFILES =		debug ft_printf parser apply attribut spec_format spec_type spec_unicode
SRC =			$(CFILES:%=$(SRC_DIR)%.c)
OBJ =			$(CFILES:%=$(OBJ_DIR)%.o)

all: $(LIBFT) $(EXEC) #replace exec by NAME

$(LIBFT):
	make -C $(LIBFT_DIR)

$(EXEC): $(NAME) $(SRC_DIR)main.c
	$(CC) $(SRC_DIR)main.c $(SRC) -I$(HEADER_DIR) -L$(LIBFT_DIR) -L./ -lft -lft_printf -o $@ $(DEBUG_FLAGS) #$(CFLAGS)

$(NAME): $(OBJ)
	ar $(ARFLAGS) $@ $(OBJ)
	@echo $@ Done !

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) -I$(HEADER_DIR) -c $< -o $@ #$(DEBUG_FLAGS) #$(CFLAGS) 

clean:
	rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@echo clean $@ Done !

fclean:	clean
	rm -f $(NAME)
	rm -f $(EXEC) #a enlever
	@make -C $(LIBFT_DIR) fclean
	@echo fclean $@ Done !

re:		fclean all

.PHONY: clean fclean re
.SUFFIXES:
