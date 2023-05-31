# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: martiper <martiper@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/21 14:31:56 by martiper          #+#    #+#              #
#    Updated: 2023/05/31 12:36:46 by martiper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECT_NAME = So Long

### CONFIG ###
### (requires full rebuild to take effect) ###

# Caps the rendering framerate to this value (doesnt stop the loop thread from running though)
# -1 to disable the cap
# 	Since the game is cpu rendered, it still takes a lot to render (40/50ms) a frame
# when a context asks for a render batch.
FPS_CAP = 1024

# 'Camera FOV' is the amount of tiles that will be rendered in the camera's view
# Usage: <width>x<height>
CAMERA_FOV = \"8x6\"

# General scale for the game
# Will be multiplied with SPRITE_SIZE and given to WINDOW_UI_SCALE
GAME_SCALE = 1.0

# How many pixels should a sprite have.
# If the given sprite asset doesn't have the same size, it will be scaled to fit (with nearest neighbor)
# Camera FOV multiplied by this value should be equal to the window size
SPRITE_SIZE = 64

# How fast does the player move (default is SPRITE_SIZE)
# Multiples of 2 are recommended due to bounding box collision detection
PLAYER_SPEED_MULTIPLIER = 0.0625

## Vignette
# Vignette is a shader that darkens the edges of the screen
# It is disabled by default since the cpu dies while rendering it
# as it has to blend with already rendered pixels..
GFX_VIGNETTE_ENABLED = 1

# Vignette radius (float)
GFX_VIGNETTE_RADIUS = 0.75

# Vignette intensity (float)
GFX_VIGNETTE_INTENSITY = 100.0

### END OF CONFIG ###

SRC_PATH = src/
INCLUDES_PATH = includes/

# CUSTOM WRAPPERS
CTX_SRC_FILES	 	= 	context/context.c
MATH_SRC_FILES	 	=	math/vectors/vec2.c math/vectors/vec2_1.c \
						math/vectors/vec2_2.c math/helpers.c
EVENT_SRC_FILES	 	= 	events/events.c
KEYS_SRC_FILES	 	= 	keys/keys.c keys/handlers.c
MAP_SRC_FILES	 	= 	map/utils.c map/tile.c map/checks.c \
						map/renderer.c map/interact.c map/map.c \
						map/map_2.c map/parser.c map/parser_2.c \
						map/parser_utils.c
ENTITY_SRC_FILES 	=	entities/entity.c entities/registry.c \
						entities/spawn.c entities/spawners.c \
						entities/renderer.c entities/getters.c \
						entities/spawn_2.c entities/registry_ctx.c
GFX_SRC_FILES	 	=	gfx/color.c gfx/image.c gfx/image_2.c \
						gfx/sprites/sprite.c gfx/sprites/store.c \
						gfx/window.c gfx/window_2.c \
						gfx/textures/animator.c gfx/textures/texture.c \
						gfx/textures/manager.c gfx/textures/manager_2.c \
						gfx/textures/cleanup.c gfx/textures/utils.c \
						gfx/textures/parser.c gfx/textures/renderer.c \
						gfx/vignette.c gfx/ui/text.c gfx/ui/fps.c \
						gfx/ui/cache.c gfx/renderer.c gfx/renderer_ctx.c
TIME_SRC_FILES	 	=	time/time_2.c time/time.c
CAMERA_SRC_FILES 	=	camera/camera.c
UTILS_SRC_FILES	 	=	utils/error.c utils/io.c utils/rand.c utils/gnl.c
SCRIPTING_SRC_FILES =	scripting/scripting.c scripting/player/player.c \
						scripting/player/utils.c scripting/player/keys.c \
						scripting/player/movement.c scripting/player/interact.c \
						scripting/player/patrol_collision.c \
						scripting/game/time.c scripting/chests.c \
						scripting/patrols/gameplay.c scripting/patrols/patrols.c
GAME_SRC_FILES		=	game/ui.c game/game.c

SRC_FILES = $(UTILS_SRC_FILES) $(CTX_SRC_FILES) $(MATH_SRC_FILES) \
			$(EVENT_SRC_FILES) $(GFX_SRC_FILES) $(MAP_SRC_FILES) \
			$(ENTITY_SRC_FILES) $(CAMERA_SRC_FILES) $(GAME_SRC_FILES) \
			$(TIME_SRC_FILES) $(KEYS_SRC_FILES) $(SCRIPTING_SRC_FILES) \
			so_long.c

SRCS = $(addprefix $(SRC_PATH),$(SRC_FILES))

OBJ_DIR = objs
OBJS = $(addprefix $(OBJ_DIR)/,$(SRCS:%.c=%.o))

NAME = so_long

CC = cc
NORM = norminette
NORM_FLAGS = -R CheckForbiddenSourceHeader -R CheckDefine

MLX_PATH = libs/mlx_linux
LIBFT_PATH = libs/libft

LIB_ARCHS = $(MLX_PATH)/libmlx_Linux.a $(LIBFT_PATH)/libft.a

__SPRITE_SIZE=$(shell (echo "$(SPRITE_SIZE) * $(GAME_SCALE) / 1" | bc ) )
INCLUDES =	-O3 -I$(INCLUDES_PATH) -I$(MLX_PATH) -I$(LIBFT_PATH) \
			-D FPS_CAP=$(FPS_CAP) \
			-D CAMERA_FOV=$(CAMERA_FOV) \
			-D SPRITE_SIZE=$(__SPRITE_SIZE) \
			-D WINDOW_UI_SCALE=$(GAME_SCALE) \
			-D PLAYER_SPEED_MULTIPLIER=$(PLAYER_SPEED_MULTIPLIER) \
			-D GFX_VIGNETTE_ENABLED=$(GFX_VIGNETTE_ENABLED) \
			-D GFX_VIGNETTE_RADIUS=$(GFX_VIGNETTE_RADIUS) \
			-D GFX_VIGNETTE_INTENSITY=$(GFX_VIGNETTE_INTENSITY)

OBJ_INCLUDES = $(INCLUDES) -I/usr/include
PROGRAM_INCLUDES = $(INCLUDES) -L$(MLX_PATH) -L$(LIBFT_PATH) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -lft

CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

### COLORS ###

RED = \033[0;31m
GREEN = \033[0;92m
YELLOW = \033[93m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[96m
RESET = \033[0m

TAG = [$(CYAN)$(PROJECT_NAME)$(RESET)]

### END OF COLORS ###

all: $(NAME)

$(MLX_PATH)/libmlx_Linux.a:
	@printf "$(TAG) compiling $(YELLOW)MiniLibX$(RESET)..\n"
	@make -C $(MLX_PATH) --no-print-directory --no-print

$(LIBFT_PATH)/libft.a:
	@make -C $(LIBFT_PATH)

$(NAME): $(LIB_ARCHS) $(OBJS)
	@printf "$(TAG) compiling $(YELLOW)$(NAME)$(RESET)..\n"
	@$(CC) $(OBJS) $(CFLAGS) $(PROGRAM_INCLUDES) -o $(NAME)
	@printf "\nCompiled with this config:\n"
	@printf "FPS Cap$(RESET): $(YELLOW)$(FPS_CAP)$(RESET);\n"
	@printf "Camera FOV$(RESET): $(YELLOW)$(CAMERA_FOV)$(RESET);\n"
	@printf "Sprite Size$(RESET): $(YELLOW)$(SPRITE_SIZE)$(RESET);\n"
	@printf "Game Scale$(RESET): $(YELLOW)$(GAME_SCALE)$(RESET);\n"
	@printf "Player Speed Multiplier$(RESET): $(YELLOW)$(PLAYER_SPEED_MULTIPLIER)$(RESET);\n"
	@printf "Vignette Enabled$(RESET): $(YELLOW)$(GFX_VIGNETTE_ENABLED)$(RESET);\n"
	@printf "Vignette Radius$(RESET): $(YELLOW)$(GFX_VIGNETTE_RADIUS)$(RESET);\n"
	@printf "Vignette Intensity$(RESET): $(YELLOW)$(GFX_VIGNETTE_INTENSITY)$(RESET);\n"
	@printf "\n$(CYAN)Done!$(RESET)\n\n"

$(OBJ_DIR)/%.o: %.c
	@printf "$(TAG) compiling $(YELLOW)$<$(RESET)..\n"
	@mkdir -p $(OBJ_DIR)/$(dir $<)
	@$(CC) $(CFLAGS) $(OBJ_INCLUDES) -c $< -o $@

clean:
	@rm -rf $(OBJS)
	@make -C $(MLX_PATH) clean --no-print-directory --no-print
	@make -C $(LIBFT_PATH) clean --no-print-directory --no-print

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT_PATH) fclean --no-print-directory --no-print

norm:
	@$(NORM) $(NORM_FLAGS) $(SRC_PATH) $(INCLUDES_PATH) $(LIBFT_PATH)

watch:
	@printf "Watching files..\n"
	@while true; do clear && ($(MAKE) -q --no-print-directory || $(MAKE) --no-print-directory); sleep 1; done;

re: fclean all

.PHONY: all clean fclean re watch
