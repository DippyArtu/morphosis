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

//TODO check out the cloud on GL
int 						main(void)
{
	t_data 					*data;

	data = init_data();

	calculate_point_cloud(data);
	gl_retrieve_points(data);
	//exit(0);

	//run_graphics(data->gl);
	clean_up(data);
	return 0;
}
