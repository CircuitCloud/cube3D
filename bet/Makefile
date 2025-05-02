NAME = cub3D

BONUS = cub3D_bonus

CC = cc

LIBFT = libft/libft.a

CFLAGS = -Wall -Wextra -Werror 
INCLUDES = MLX/build/libmlx42.a  MLX/build/libglfw3.a -Iinclude -lm -framework Cocoa -framework OpenGL -framework IOKit

SRC = mandatory/main.c mandatory/parsing/parse.c mandatory/parsing/bad_alloc.c mandatory/parsing/fd_check.c \
		mandatory/parsing/free_maps.c mandatory/parsing/invalid_map.c mandatory/parsing/parse_line.c mandatory/parsing/parse_map.c \
		mandatory/parsing/parse_textures.c mandatory/parsing/linked_list.c mandatory/parsing/p_directions.c getnextline/get_next_line_utils.c \
		getnextline/get_next_line.c mandatory/parsing/free_split.c mandatory/parsing/ft_strcmp.c mandatory/parsing/prs_text_util.c\
		mandatory/parsing/cub_atoi.c mandatory/parsing/convert_space.c mandatory/2D_map/player.c mandatory/2D_map/draw_utils.c mandatory/raycast/render_rays.c\
		mandatory/raycast/caster.c mandatory/raycast/horizotal.c mandatory/raycast/vertical.c mandatory/raycast/render_wall.c\
		mandatory/textures/load_textures.c mandatory/textures/positions.c mandatory/textures/player_tex.c mandatory/textures/pixels_tools.c \
		mandatory/textures/cleanup.c

BONUS_SRC = bonus/main_bonus.c bonus/parsing/parse_bonus.c bonus/parsing/bad_alloc_bonus.c bonus/parsing/fd_check_bonus.c \
		bonus/parsing/free_maps_bonus.c bonus/parsing/invalid_map_bonus.c bonus/parsing/parse_line_bonus.c bonus/parsing/parse_map_bonus.c \
		bonus/parsing/parse_textures_bonus.c bonus/parsing/linked_list_bonus.c bonus/parsing/p_directions_bonus.c getnextline/get_next_line_utils.c \
		getnextline/get_next_line.c bonus/parsing/free_split_bonus.c bonus/parsing/ft_strcmp_bonus.c bonus/parsing/prs_text_util_bonus.c\
		bonus/parsing/cub_atoi_bonus.c bonus/parsing/convert_space_bonus.c bonus/2D_map/player_bonus.c bonus/2D_map/draw_utils_bonus.c bonus/raycast/render_rays_bonus.c\
		bonus/raycast/caster_bonus.c bonus/raycast/horizotal_bonus.c bonus/raycast/vertical_bonus.c bonus/raycast/render_wall_bonus.c\
		bonus/textures/load_textures_bonus.c bonus/textures/positions_bonus.c bonus/textures/player_tex_bonus.c bonus/textures/pixels_tools_bonus.c \
		bonus/textures/cleanup_bonus.c bonus/bonus_fun/mini_map_bonus.c bonus/bonus_fun/animations_bonus.c bonus/bonus_fun/rotate_mouse_bonus.c bonus/raycast/steep_check_bonus.c bonus/2D_map/player_utils_bonus.c

OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS_SRC:.c=.o)

all : $(NAME)

bonus : $(BONUS)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJ) $(LIBFT)

$(BONUS) : $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(BONUS) $(BONUS_OBJ) $(LIBFT)

%.o : %.c mandatory/cub3D.h bonus/cub3D_bonus.h getnextline/get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -f $(OBJ)
	@rm -f $(BONUS_OBJ)

fclean : clean
	@rm -f $(NAME)
	@rm -f $(BONUS)

re : fclean all
