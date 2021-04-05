/* *********************************** */
/*                                     */
/*      Morphosis project              */
/*                                     */
/*      Created by Artur Makhnach      */
/*      github.com/DippyArtu           */
/*      artum.me                       */
/*                                     */
/* *********************************** */

#include "morphosis.h"

t_gl						*init_gl_struct(void)
{
	t_gl					*gl;

	if (!(gl = (t_gl *)malloc(sizeof(t_gl))))
		error(MALLOC_FAIL_ERR, NULL);
	gl->window = NULL;
	gl->shaderProgram = 0;
	gl->vertexShader = 0;
	gl->fragmentShader = 0;
	gl->vbo = 0;
	gl->vao = 0;
	gl->points = NULL;
	gl->num_points = 0;
	return gl;
}

t_fract						*init_fract(void)
{
	t_fract 				*fract;

	if (!(fract = (t_fract *)malloc(sizeof(t_fract))))
		error(MALLOC_FAIL_ERR, NULL);

	fract->p0.x = -1.5f;
	fract->p0.y = -1.5f;
	fract->p0.z = -1.5f;

	fract->p1.x = 1.5f;
	fract->p1.y = 1.5f;
	fract->p1.z = 1.5f;

	fract->grid_length = 3.0f;
	fract->grid_size = 0.0f;

	fract->grid.x = NULL;
	fract->grid.y = NULL;
	fract->grid.z = NULL;
	fract->coord.dx = NULL;
	fract->coord.dy = NULL;
	fract->coord.dz = NULL;

	fract->step_size = 0.05f;

	fract->julia = init_julia();
	return fract;
}

t_julia 					*init_julia(void)
{
	t_julia 				*julia;

	if (!(julia = (t_julia *)malloc(sizeof(t_julia))))
		error(MALLOC_FAIL_ERR, NULL);

	julia->n_iter = 0;
	julia->max_iter = 6;
	julia->threshold = 2.0f;
	julia->w = 0.0f;

	julia->c.x = -0.2f;
	julia->c.y = 0.8f;
	julia->c.z = 0.0f;
	julia->c.w = 0.0f;

	return julia;
}

t_data						*init_data(void)
{
	t_data 					*data;

	if (!(data = (t_data *)malloc(sizeof(t_data))))
		error(MALLOC_FAIL_ERR, NULL);
	data->gl = init_gl_struct();
	data->fract = init_fract();
	return data;
}

void						init_grid(t_data *data)
{
	t_fract 				*f;

	f = data->fract;
	if (!(f->grid.x = (float *)malloc((size_t)f->grid_size * sizeof(float))))
		error(MALLOC_FAIL_ERR, data);
	if (!(f->grid.y = (float *)malloc((size_t)f->grid_size * sizeof(float))))
		error(MALLOC_FAIL_ERR, data);
	if (!(f->grid.z = (float *)malloc((size_t)f->grid_size * sizeof(float))))
		error(MALLOC_FAIL_ERR, data);
}
