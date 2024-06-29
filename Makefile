
# EXECUTABLE
NAME = so_long
BNAME = so_long_bonus

# DIRECTORIES

SRCS_DIR = srcs
BSRCS_DIR = srcs_bonus
LIBS_DIR = libs
INCS_DIR = includes
OBJS_DIR = objs
BOBJS_DIR = objs_bonus
LIBFT_DIR = $(LIBS_DIR)/libft
MLX_DIR = $(LIBS_DIR)/mlx

# FILES
LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx_Linux.a

# LIBRARIES FILES
define LIB := 
	$(LIBFT)
	$(MLX)
	-lX11
	-lXext
endef
LIB := $(strip $(LIB))

# INCLUDES FILES
define INCLUDES :=
	$(INCS_DIR)
	$(LIBFT_DIR)
	$(MLX_DIR)
endef
INCLUDES := $(strip $(INCLUDES))

# SRC FILES
define SRC :=
	collect_exit.c
	distance.c
	errors.c
	movement.c
	frees.c
	hooks.c
	inits.c
	map_check.c
	map_error.c
	map_floodfill.c
	map_init.c
	map_parse_utils.c
	map_parse.c
	utils.c
	render_map.c
	image.c
	zero.c
	img_array.c
	main.c
endef
SRC := $(strip $(SRC))

# Bonus SRC FILES
define BSRC :=
	collect_exit.c
	distance.c
	errors.c
	movement.c
	frees.c
	hooks.c
	inits.c
	map_check.c
	map_error.c
	map_floodfill.c
	map_init.c
	map_parse_utils.c
	map_parse.c
	utils.c
	render_map.c
	image.c
	zero.c
	img_array.c
	time.c
	shoot.c
	shoot_laser.c
	invaders.c
	invaders2.c
	invaders_movement.c
	invader_distance.c
	hp_moves.c
	image_bonus.c
	main.c
endef
BSRC := $(strip $(BSRC))

OBJ = $(addprefix $(OBJS_DIR)/,$(SRC:%.c=%.o))
BOBJ = $(addprefix $(BOBJS_DIR)/,$(BSRC:%.c=%.o))

CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD
RM = rm -rf
INCLUDES_FLAGS := $(addprefix -I , $(INCLUDES))

-include $(OBJ:.o=.d)
-include $(BOBJ:.o=.d)

# RULES
.PHONY: all
all: $(NAME)

.PHONY: ball
ball: $(NAME) $(BNAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES_FLAGS) -c $< -o $@

$(BNAME): $(LIBFT) $(MLX) $(BOBJ)
	$(CC) $(CFLAGS) $(BOBJ) $(LIB) -o $@

$(BOBJS_DIR)/%.o: $(BSRCS_DIR)/%.c
	mkdir -p $(BOBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES_FLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR)

.PHONY: clean
clean:
	$(RM) $(OBJS_DIR)
	$(RM) $(BOBJS_DIR)
	make clean -sC $(MLX_DIR)
	make clean -sC $(LIBFT_DIR)

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)
	$(RM) $(BNAME)
	make fclean -C $(LIBFT_DIR)

.PHONY: re
re: fclean all

.PHONY: bre
re: fclean ball

.PHONY: bonus
bonus: $(BNAME)


