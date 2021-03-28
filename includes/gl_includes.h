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

# define VERTEX_SRC "./shaders/vertex.shader"
# define FRAGMENT_SRC "./shaders/fragment.shader"

# define GLEW_STATIC
# include <GL/glew.h>
# include <GLFW/glfw3.h>
# include "stb_image.h"
# include <cglm/cglm.h>

//----------------------------------------------------------------------------------------------------------------------Window dimensions
# define SRC_WIDTH 800
# define SRC_HEIGHT 600

#endif
