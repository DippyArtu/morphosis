/* *********************************** */
/*                                     */
/*      Morphosis project              */
/*                                     */
/*      Created by Artur Makhnach      */
/*      github.com/DippyArtu           */
/*      artum.me                       */
/*                                     */
/* *********************************** */

/*
 * Prereqs:
 * - OpenGL 3.2+
 * - GLFW
 * - GLEW
 * - CGLM | docs: https://cglm.readthedocs.io/en/latest/
 */

#include "morphosis.h"

int 						main(void)
{
	float vertices[] = {
		0.0f,  0.5f, // Vertex 1 (X, Y)
		0.5f, -0.5f, // Vertex 2 (X, Y)
		-0.5f, -0.5f  // Vertex 3 (X, Y)
	};

	t_gl 					*gl;

	gl = init_gl_struct();

	gl->points = (float *)malloc(sizeof(vertices));
	memcpy(gl->points, vertices, sizeof(vertices));
	gl->num_points = 3;

	run_graphics(gl);
	clean_up(gl);
	return 0;
}
