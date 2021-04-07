/* *********************************** */
/*                                     */
/*      Morphosis project              */
/*                                     */
/*      Created by Artur Makhnach      */
/*      github.com/DippyArtu           */
/*      artum.me                       */
/*                                     */
/* *********************************** */

#ifndef _MORPHOSIS_GL_INCLUDES_H
# define _MORPHOSIS_GL_INCLUDES_H

# define SHADER_SRC_SIZE 10000

# define VERTEX_SRC "./shaders/vertex.shader"
# define FRAGMENT_SRC "./shaders/fragment.shader"

# define GLEW_STATIC
# include <GL/glew.h>
# include <GLFW/glfw3.h>
# include "stb_image.h"
# include <cglm/cglm.h>

# include <structures.h>

//----------------------------------------------------------------------------------------------------------------------Window dimensions
# define SRC_WIDTH 800
# define SRC_HEIGHT 600


//---------------------------------------------------------------------------------------------------------------------- gl_init.c
void 						init_gl(t_gl *gl);
void						gl_init_points(t_data *data, uint size);

//---------------------------------------------------------------------------------------------------------------------- gl_draw.c
void 						run_graphics(t_gl *gl);
void						gl_render(t_gl *gl);

//---------------------------------------------------------------------------------------------------------------------- gl_utils.c
void 						framebuffer_size_callback(GLFWwindow *window, int width, int height);
void 						processInput(GLFWwindow *window);
void 						terminate_gl(t_gl *gl);

//---------------------------------------------------------------------------------------------------------------------- gl_buffers.c
void 						createVBO(t_gl *gl, GLsizeiptr size, GLfloat *points);
void						createVAO(t_gl *gl);

//---------------------------------------------------------------------------------------------------------------------- gl_build.c
void 						makeShaderProgram(t_gl *gl);
char						*readShaderSource(char *src_name);
GLuint 						createShader(GLenum type, char **src);

//---------------------------------------------------------------------------------------------------------------------- gl_build.c
void 						createProgram(t_gl *gl);

//---------------------------------------------------------------------------------------------------------------------- gl_points.c
void						gl_set_attrib_ptr(t_gl *gl, char *attrib_name, GLint num_vals, int stride, int offset);
void						gl_retrieve_points(t_data *data);

#endif
