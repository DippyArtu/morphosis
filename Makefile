#########################################
##                                     ##
##      Morphosis project              ##
##                                     ##
##      Created by Artur Makhnach      ##
##      github.com/DippyArtu           ##
##      artum.me                       ##
##                                     ##
#########################################

NAME = morphosis

SRC_DIR = ./srcs/
SRC = 	main.c \
		cleanup.c \
		init.c \
		errors.c \
		gl_draw.c \
		gl_utils.c \
		gl_buffers.c \
		gl_build.c \
		gl_points.c

SRCS = $(addprefix $(SRC_DIR), $(SRC))

OBJS = $(addprefix $(OBJ_DIR), $(OBJ))
OBJ_DIR = ./obj/
OBJ = $(SRC:.c=.o)

INCS = $(addprefix $(INC_DIR), $(INC))
INC_DIR = ./includes/
INC = 	morphosis.h \
		gl_includes.h \
		stb_image.h \
		errors.h

LIB_OBJS = $(addprefix $(LIB_OBJ_DIR), $(LIB_OBJ))
LIB_OBJ = *.o
LIB_OBJ_DIR = ./libft/obj/
LIB_SRC_DIR = ./libft/srcs/
LIB_INCS = $(addprefix $(LIB_INC_DIR), $(LIB_INC))
LIB_INC = libft.h get_next_line.h
LIB_INC_DIR = ./libft/includes/

FLAGS = -Werror -Wextra -Wall -I$(INC_DIR) -I$(LIB_INC_DIR)
GL_LIBS = -framework OpenGL -I/usr/local/include -lGLEW -lglfw

all: $(NAME)

$(NAME): $(OBJ_DIR) $(LIB_OBJS) $(HASH_OBJS) $(OBJS)
		clang $(OBJS) ./libft/libft.a -o $(NAME) $(GL_LIBS)

$(OBJ_DIR):
		mkdir -p $@
		@mkdir -p $(LIB_OBJ_DIR)
		@mkdir -p $(HASH_OBJ_DIR)

$(LIB_OBJ_DIR)%.o: $(LIB_SRC_DIR)%.c $(LIB_INCS)
		@make -C libft

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCS)
		clang $(FLAGS) -o $@ -c $<

clean:
		@make clean -C libft
		@rm -f $(OBJS)
		@rm -rf $(OBJ_DIR)

fclean: clean
		@make fclean -C libft
		@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re