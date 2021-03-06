CC =			gcc
NAME =			libftprintf.a
EXEC =			ft_printf
SRC_DIR =		./src/
OBJ_DIR =		./obj/
HEADER_DIR =	./include/
LIBFT_DIR = 	./libft/
LIBFT =			$(LIBFT_DIR)libft.a
CFLAGS =		-Wall -Werror -Wextra
DEBUG_FLAGS =	-fsanitize=address -g
ARFLAGS =		-rcs
CFILES =		ft_printf parser apply modifier spec_conv spec_type spec_decimal spec_unicode
SRC =			$(CFILES:%=$(SRC_DIR)%.c)
OBJ =			$(CFILES:%=$(OBJ_DIR)%.o)

all: $(NAME) $(EXEC)
# all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(EXEC): $(NAME) $(SRC_DIR)main.c
	$(CC) $(SRC_DIR)main.c $(SRC) -I$(HEADER_DIR) -L./ -lftprintf -o $@ $(CFLAGS) #$(DEBUG_FLAGS)

$(NAME): $(LIBFT) $(OBJ)
	cp $(LIBFT) ./$(NAME)
	ar $(ARFLAGS) $@ $(OBJ)
	@echo $@ Done !

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) -I$(HEADER_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@echo clean $@ Done !

fclean:	clean
	rm -f $(NAME)
	rm -f $(EXEC)
	@make -C $(LIBFT_DIR) fclean
	@echo fclean $@ Done !

re:		fclean all

.PHONY: clean fclean re
.SUFFIXES:
