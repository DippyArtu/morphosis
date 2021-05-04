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
 * - OpenSSL
 */

/*
 * OBJ lib: https://github.com/rlk/obj
 */

//TODO OpenCL?
#include "morphosis.h"

static t_data 						*get_args(int argv, char **argc)
{
	t_data					*data;
	float 					s_size;
	float4 					q;
	t_mat_conv_data			mat;

	data = NULL;
	if (argv == 1)
		error(NO_ARG_ERR, NULL);
	if (argv != 6)
	{
		if (argv == 2 && !(strcmp(argc[1], "-d")))
		{
			data = init_data();
			return data;
		}
		else if (argv == 3 && !(strcmp(argc[1], "-m")))
		{
			process_matrix(argc[2], &mat);
			data = init_data();
			data->fract->step_size = mat.step_size;
			data->fract->julia->c = mat.q;

			printf("%f\n", data->fract->julia->c.x);
			printf("%f\n", data->fract->julia->c.y);
			printf("%f\n", data->fract->julia->c.z);
			printf("%f\n", data->fract->julia->c.w);
			exit(0);

			return data;
		}
		error(ARGS_ERR, NULL);
	}
	if ((s_size = (float)strtod(argc[1], NULL)) < 0.00001 || s_size > 1)
		error(GRID_ERR, NULL);
	q.x = (float)strtod(argc[2], NULL);
	q.y = (float)strtod(argc[3], NULL);
	q.z = (float)strtod(argc[4], NULL);
	q.w = (float)strtod(argc[5], NULL);
	data = init_data();

	data->fract->step_size = s_size;
	data->fract->julia->c = q;
	return data;
}

int 						main(int argv, char **argc)
{
	t_data 					*data;

	data = get_args(argv, argc);
	calculate_point_cloud(data);
	gl_retrieve_tris(data);
	clean_calcs(data);

	run_graphics(data->gl, data->fract->p1, data->fract->p0);
	if (data->gl->export)
	{
		printf("\nEXPORTING----\n");
		export_obj(data);
		printf("DONE\n");
	}

	clean_up(data);
	return 0;
}
