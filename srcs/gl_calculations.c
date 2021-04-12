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

void 						gl_calc_transforms(t_gl *gl)
{
	t_matrix 				*matrix;
	GLuint		 			projection;

	matrix = gl->matrix;
	matrix->model = glGetUniformLocation(gl->shaderProgram, "model");
	glUniformMatrix4fv(matrix->model, 1, GL_FALSE, (float *)matrix->model_mat);

	glm_lookat(matrix->eye, matrix->center, matrix->up, matrix->view_mat);
	matrix->view = glGetUniformLocation(gl->shaderProgram, "view");
	glUniformMatrix4fv(matrix->view, 1, GL_FALSE, (float *)matrix->view_mat);

	glm_perspective(glm_rad(45.0f), (SRC_WIDTH / SRC_HEIGHT), 1.0f, 10.0f, matrix->projection_mat);
	projection = glGetUniformLocation(gl->shaderProgram, "proj");
	glUniformMatrix4fv(projection, 1, GL_FALSE, (float *)matrix->projection_mat);
}

/*
 * Scale function:
 *
 *        M - R_min
 * M =  --------------- * (T_max - T_min) + T_min
 *       R_max - R_min
 *
 * R_min — minimum of the range of input
 * R_max — maximum of the range of input
 * T_min — minimum of the target range
 * T_max — maximum of the target range
 * M — input value
 *
 * If coordinates are on a straight line, delta would equal to 0
 * to avoid the division by zero, in that case, delta is set to 1
 */
void						gl_scale_tris(t_gl *gl, float3 max, float3 min)
{
	uint 					i;
	float					delta_x;
	float					delta_y;
	float 					delta_z;

	i = 0;
	if (!(delta_x = (float)(max.x - min.x)))
		delta_x = 1.0f;
	if (!(delta_y = (float)(max.y - min.y)))
		delta_y = 1.0f;
	if (!(delta_z = (float)(max.z - min.z)))
		delta_z = 1.0f;
	while (i < gl->num_tris)
	{
		gl->tris[i] = ((gl->tris[i] - (float)min.x) / delta_x) * 1.5f - 0.75f;
		i++;
		gl->tris[i] = ((gl->tris[i] - (float)min.y) / delta_y) * 1.5f - 0.75f;
		i++;
		gl->tris[i] = ((gl->tris[i] - (float)min.z) / delta_z) * 1.5f - 0.75f;
		i++;
	}
}
