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

	t_data 					*data;

	data = init_data();

	calculate_julia_cloud(data);
	exit(0);

	data->gl->points = (float *)malloc(sizeof(vertices));
	memcpy(data->gl->points, vertices, sizeof(vertices));
	data->gl->num_points = 3;

	run_graphics(data->gl);
	clean_up(data);
	return 0;
}
