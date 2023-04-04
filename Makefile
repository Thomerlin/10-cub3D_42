# C Compiler
CC		:=	clang
# Compiler flags
CFLAGS	:=	-Wall -Wextra -Werror -g
# Removal tool
RM		:=	rm -rf
# Minilibx
MINILIBX := -lmlx -lXext -lX11


# PROGRAM
# Program name
NAME		:= cub3D

# Headers
HEADER_DIR	:=	inc
HEADER		:=	cub3D.h
H_INCLUDE	:=	$(addprefix -I, $(HEADER_DIR))

# Source
SRC_DIR		:=	./src ./src/render ./src/color
SRC			:=	main.c exit.c load_game.c validate.c load_map.c
SRC			+=	conversion_color.c
SRC			+=	render.c

# Object
OBJ_DIR		:=	obj
OBJ			:=	$(SRC:%.c=$(OBJ_DIR)/%.o)

# LIBFT
LIBFT_DIR	:=	./libft
LIBFT_H_INC	:=	-I$(LIBFT_DIR)
LIBFT		:=	$(LIBFT_DIR)/libft.a

# Inclusions:
INCLUDE		:=	$(C_INCLUDE) $(H_INCLUDE) $(LIBFT_H_INC)

# vpath
vpath	%.h		$(HEADER_DIR)
vpath	%.c		$(SRC_DIR)

# -----------------------RULES------------------------------------------------ #
.PHONY: all vg norm clean fclean re

# Creates NAME
all: $(NAME)

# Compiles OBJ and LIBFT into the program NAME
$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBFT) $(INCLUDE) $(MINILIBX)

# Compiles SRC into OBJ
$(OBJ): $(OBJ_DIR)/%.o: %.c $(HEADER) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE)

# Directory making
$(OBJ_DIR):
	@mkdir -p $@

# Libft compiling
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Run program using valgrind
vg:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=log_vg ./$(NAME) assets/maps/test.cub

# Norm: checks code for norm errors
norm:
	@norminette | grep "Error" | cat

# Clean: removes objects' directory
clean:
	@$(RM) $(OBJ_DIR) $(C_HEADER_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

# Full clean: removes objects' directory and generated libs/programs
fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

# Remake: full cleans and runs 'all' rule
re: fclean all