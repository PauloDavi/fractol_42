vpath %.c src
vpath %.c src/fractal_sets

NAME := fractol
CFLAGS := -Wextra -Wall -Werror
CFLAGS += -O3 -g3

LIBTF_DIR := ./lib/libft
LIBS := -L$(LIBTF_DIR) -lft -lmlx -lm -lX11 -lXext

OBJ_DIR := build
INCLUDE_DIR := include
INCLUDES := -I$(INCLUDE_DIR) -I$(LIBTF_DIR)

SRCS := handles.c render.c main.c mlx_utils.c colors.c operations.c
SRCS += parse_args.c math_functions.c help_message.c utils.c mandelbox.c
SRCS += tricorn.c julia.c burning_ship.c mandelbrot.c
OBJS := $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all: libft $(NAME)

bonus: all

libft: update_modules
	@$(MAKE) -C $(LIBTF_DIR)

init_modules: $(LIBTF_DIR)
	git submodule update --init

update_modules: init_modules
	git submodule foreach git pull origin master --rebase

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBTF_DIR):
	mkdir -p $(LIBTF_DIR)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(INCLUDES) $(CFLAGS) -o $(NAME)

clean: 
	@$(MAKE) -C $(LIBTF_DIR) clean
	@rm -rf $(OBJS) $(OBJS_BONUS)

fclean: clean
	@$(MAKE) -C $(LIBTF_DIR) fclean
	@rm -rf $(NAME)

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re bonus rebonus libft init_modules update_modules
