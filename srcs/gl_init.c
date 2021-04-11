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

t_matrix 					*init_gl_matrices(void)
{
	t_matrix 				*matrix;

	if (!(matrix = (t_matrix *)malloc(sizeof(t_matrix))))
		error(MALLOC_FAIL_ERR, NULL);

	glm_mat4_identity(matrix->model_mat);
	glm_mat4_identity(matrix->projection_mat);
	glm_mat4_identity(matrix->view_mat);

	matrix->eye[0] = 1.5f;
	matrix->eye[1] = 1.5f;
	matrix->eye[2] = 0.0f;

	matrix->center[0] = 0.0f;
	matrix->center[1] = 0.0f;
	matrix->center[2] = 0.0f;

	matrix->up[0] = 0.8f;
	matrix->up[1] = 0.3f;
	matrix->up[2] = 0.7f;

	return matrix;
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
	gl->tris = NULL;
	gl->num_tris = 0;
	gl->num_points = 0;
	gl->matrix = init_gl_matrices();
	return gl;
}

