OBJ = src/cub.o src/intersection.o src/new.o src/move.o \
		src/ft_utilse.o src/get_info.o src/fall_img.o src/ft_split.o src/read_file.o\
		src/cub3d_utils.o src/cub3d_utils1.o src/cub3d.o src/ft_substr.o \
		src/ft_parcing.o src/ft_animate.o\
		src/ft_parcing2.o

OBJ_BONUS = bonus/src/cub.o intersection.o bonus/src/new.o move.o \
		bonus/src/ft_utilse.o get_info.o bonus/src/fall_img.o ft_split.o read_file.o\
		bonus/src/cub3d_utils.o bonus/src/cub3d_utils1.o cub3d.o ft_substr.o bonus/src/mini_map.o\
		bonus/src/mouse_rotate.o bonus/src/ft_animate.o bonus/src/collisions_bonus.o bonus/src/ft_parcing.o\
		bonus/src/ft_parcing2.o bonus/src/mini_map1.o

LAGS = -lmlx -framework OpenGL -framework AppKit
CFLAGS = -Wall -Wextra -Werror

NAME = cub3D
NAME_BONUS = cub3D_bonus

all: $(NAME) clean

$(NAME): $(OBJ)
	cc $(CFLAGS) $(LAGS) $(OBJ) -o $(NAME)

bonus: $(NAME_BONUS) clean

$(NAME_BONUS): $(OBJ_BONUS)
	cc $(CFLAGS) $(LAGS) $(OBJ_BONUS) -o $(NAME_BONUS)

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
		rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re