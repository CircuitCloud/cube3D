NAME = cub3D

BONUS = cub3D_bonus

CC = cc

LIBFT = libft/libft.a

CFLAGS =  -g #-fsanitize=address -Wall -Wextra -Werror 
INCLUDES = MLX/build/libmlx42.a  MLX/build/libglfw3.a -Iinclude -lm -framework Cocoa -framework OpenGL -framework IOKit

SRC = mandatory/main.c mandatory/parsing/parse.c mandatory/parsing/bad_alloc.c mandatory/parsing/fd_check.c \
		mandatory/parsing/free_maps.c mandatory/parsing/invalid_map.c mandatory/parsing/parse_line.c mandatory/parsing/parse_map.c \
		mandatory/parsing/parse_textures.c mandatory/parsing/linked_list.c mandatory/parsing/p_directions.c getnextline/get_next_line_utils.c \
		getnextline/get_next_line.c mandatory/parsing/free_split.c mandatory/parsing/ft_strcmp.c mandatory/parsing/prs_text_util.c\
		mandatory/parsing/cub_atoi.c mandatory/parsing/convert_space.c mandatory/2D_map/player.c mandatory/2D_map/draw_utils.c mandatory/raycast/render_rays.c\
		mandatory/raycast/caster.c mandatory/raycast/horizotal.c mandatory/raycast/vertical.c mandatory/raycast/render_wall.c\
		mandatory/textures/load_textures.c mandatory/textures/positions.c mandatory/textures/player_tex.c mandatory/textures/pixels_tools.c \
		mandatory/textures/cleanup.c

BONUS_SRC = bonus/main.c bonus/parsing/parse.c bonus/parsing/bad_alloc.c bonus/parsing/fd_check.c \
		bonus/parsing/free_maps.c bonus/parsing/invalid_map.c bonus/parsing/parse_line.c bonus/parsing/parse_map.c \
		bonus/parsing/parse_textures.c bonus/parsing/linked_list.c bonus/parsing/p_directions.c getnextline/get_next_line_utils.c \
		getnextline/get_next_line.c bonus/parsing/free_split.c bonus/parsing/ft_strcmp.c bonus/parsing/prs_text_util.c\
		bonus/parsing/cub_atoi.c bonus/parsing/convert_space.c bonus/2D_map/player.c bonus/2D_map/draw_utils.c bonus/raycast/render_rays.c\
		bonus/raycast/caster.c bonus/raycast/horizotal.c bonus/raycast/vertical.c bonus/raycast/render_wall.c\
		bonus/textures/load_textures.c bonus/textures/positions.c bonus/textures/player_tex.c bonus/textures/pixels_tools.c \
		bonus/textures/cleanup.c bonus/bonus_fun/mini_map.c bonus/bonus_fun/animations.c bonus/bonus_fun/rotate_mouse.c bonus/raycast/steep_check.c bonus/2D_map/player_utils.c

OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS_SRC:.c=.o)


# run:
# 	./run.sh

all : $(NAME)

bonus : $(BONUS)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJ) $(LIBFT)

$(BONUS) : $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(BONUS) $(BONUS_OBJ) $(LIBFT)

%.o : %.c mandatory/cub3D.h  getnextline/get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -f $(OBJ)
	@rm -f $(BONUS_OBJ)

fclean : clean
	@rm -f $(NAME)
	@rm -f $(BONUS)

re : fclean all
