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
