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

void						gl_retrieve_tris(t_data *data)
{
	uint					i;
	uint 					j;
	uint					size;

	i = 0;
	j = 0;
	size = data->gl->num_tris * 3 * 3;             																		//each cell has 3 coordinates with 3 values each
	if (!(data->gl->tris = (float *)malloc(size * sizeof(float))))
		error(MALLOC_FAIL_ERR, data);

	while (j < size)
	{
		for (int c = 0; c < 3; c++)
		{
			data->gl->tris[j++] = data->triangles[i][c].x;
			data->gl->tris[j++] = data->triangles[i][c].y;
			data->gl->tris[j++] = data->triangles[i][c].z;
		}
		i++;
	}
}

void						gl_retrieve_points(t_data *data)
{
	uint					i;
	uint 					j;
	uint 					c;
	uint					size;
	float 					*pts;

	i = 0;
	j = 0;
	c = 0;
	gl_init_points(data, data->gl->num_points);
	pts = data->gl->points;
	size = pow(data->fract->grid_size, 3) * 8;
	while (i <= size)
	{
		if (data->vertexval[i] == 1.0f)
		{
			pts[j++] = data->vertexpos[i].x;
			pts[j++] = data->vertexpos[i].y;
			pts[j++] = data->vertexpos[i].z;
			c++;
		}
		if (c == data->gl->num_points)
			break;
		i++;
	}
}

void						gl_set_attrib_ptr(t_gl *gl, char *attrib_name, GLint num_vals, int stride, int offset)
{
	GLuint 					attrib;

	attrib = glGetAttribLocation(gl->shaderProgram, attrib_name);
	glVertexAttribPointer(attrib, num_vals, GL_FLOAT, GL_FALSE, stride * sizeof(float), (void *)(offset * sizeof(float)));
	glEnableVertexAttribArray(attrib);
}
