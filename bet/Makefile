NAME = cub3D

CC = cc

LIBFT = libft/libft.a

# CFLAGS =  -Wall -Wextra -Werror -g -fsanitize=address

INCLUDES = MLX/build/libmlx42.a  MLX/build/libglfw3.a -Iinclude -lm -framework Cocoa -framework OpenGL -framework IOKit

SRC = mandatory/main.c mandatory/parsing/parse.c mandatory/parsing/bad_alloc.c mandatory/parsing/fd_check.c \
		mandatory/parsing/free_maps.c mandatory/parsing/invalid_map.c mandatory/parsing/parse_line.c mandatory/parsing/parse_map.c \
		mandatory/parsing/parse_textures.c mandatory/parsing/linked_list.c mandatory/parsing/p_directions.c getnextline/get_next_line_utils.c \
		getnextline/get_next_line.c mandatory/parsing/free_split.c mandatory/parsing/ft_strcmp.c mandatory/parsing/prs_text_util.c\
		mandatory/parsing/cub_atoi.c\
 
OBJ = $(SRC:.c=.o)


# run:
# 	./run.sh

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJ) $(LIBFT)
 
%.o : %.c mandatory/cub3D.h  getnextline/get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all
