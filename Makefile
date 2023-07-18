OBJ = cub.o read_file.o ft_split.o intersection.o

LAGS = -lmlx -framework OpenGL -framework AppKit
#CFLAGS = -fsanitize=address -g3
NAME = cub3D

all: $(NAME)

$(NAME): $(OBJ)
	cc $(CFLAGS) $(LAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re