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
 * Prereqs (homebrew):
 * - OpenGL 3.2+
 * - GLFW
 * - GLEW
 * - CGLM | docs: https://cglm.readthedocs.io/en/latest/
 */

/*
 * OBJ lib: https://github.com/rlk/obj
 *
 */

#include "morphosis.h"

int 						main(void)
{
	t_data 					*data;

	data = init_data();

	calculate_point_cloud(data);
	gl_retrieve_tris(data);

	clean_calcs(data);
	printf("\nEXPORTING----\n");
	export_obj(data);
	printf("DONE\n");
	run_graphics(data->gl, data->fract->p1, data->fract->p0);

	clean_up(data);
	return 0;
}
