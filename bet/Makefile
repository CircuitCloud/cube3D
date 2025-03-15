NAME = cub3D

CC = cc

LIBFT = libft/libft.a

# CFLAGS =  -Wall -Wextra -Werror -g -fsanitize=address

INCLUDES = MLX/build/libmlx42.a  MLX/build/libglfw3.a -Iinclude -lm -framework Cocoa -framework OpenGL -framework IOKit

SRC = srcs/main.c srcs/parsing/parse.c srcs/parsing/bad_alloc.c srcs/parsing/fd_check.c \
		srcs/parsing/free_maps.c srcs/parsing/invalid_map.c srcs/parsing/parse_line.c srcs/parsing/parse_map.c \
		srcs/parsing/parse_textures.c srcs/parsing/linked_list.c srcs/parsing/p_directions.c getnextline/get_next_line_utils.c \
		getnextline/get_next_line.c srcs/parsing/free_split.c srcs/parsing/ft_strcmp.c srcs/parsing/prs_text_util.c\
		srcs/parsing/cub_atoi.c srcs/player.c srcs/draw_utils.c
 
OBJ = $(SRC:.c=.o)


# run:
# 	./run.sh

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJ) $(LIBFT)
 
%.o : %.c srcs/cub3D.h  getnextline/get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all
