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
		utils.c \
		point_cloud.c \
		build_fractal.c \
		sample_julia.c \
		polygonisation.c \
		write_obj.c \
		\
		gl_draw.c \
        gl_utils.c \
        gl_buffers.c \
        gl_build.c \
        gl_points.c \
        gl_init.c \
        gl_calculations.c\
        \
        obj.c\
        \
        lib_complex.c

SRCS = $(addprefix $(SRC_DIR), $(SRC))
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))
OBJ_DIR = ./obj/
OBJ = $(SRC:.c=.o)

INCS = $(addprefix $(INC_DIR), $(INC))
INC_DIR = ./includes/
INC = 	morphosis.h \
		gl_includes.h \
		stb_image.h \
		errors.h \
		lib_complex.h \
		structures.h \
		look-up.h \
		obj.h

FLAGS = -I$(INC_DIR)
GL_LIBS = -framework OpenGL -I/usr/local/include -lGLEW -lglfw

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
		clang $(OBJS) -o $(NAME) $(GL_LIBS)

$(OBJ_DIR):
		mkdir -p $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCS)
		clang $(FLAGS) -o $@ -c $<

clean:
		@rm -f $(OBJS)
		@rm -rf $(OBJ_DIR)

fclean: clean
		@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re