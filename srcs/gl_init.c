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

void						gl_init_points(t_data *data, uint size)
{
	if (!(data->gl->points = (float *)malloc(3 * size * sizeof(float))))
		error(MALLOC_FAIL_ERR, data);
}

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

