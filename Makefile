SRC = 	main.c\
		lm_parse_file.c\
		lm_check_room.c\
		lm_check_link.c\
		lm_resolve.c\
		lm_path.c\
		lm_trace_path.c\
		lm_print.c\
		lm_util.c

OBJ = $(SRC:c=o)

NAME = lem-in

all: $(NAME)

$(NAME):
	make -C libft/
	cc -c $(SRC) -I./libft -Wall -Werror -Wextra
	cc -o $(NAME) $(OBJ) -L./libft -lft

clean:
	make -C libft/ clean 
	rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean 
	rm -f $(NAME)

re: fclean all

me: all clean