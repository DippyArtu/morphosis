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

//TODO comments

void 						run_graphics(t_gl *gl, float3 max, float3 min)
{
	gl_scale_points(gl, max, min);

	init_gl(gl);
	createVAO(gl);
	createVBO(gl, 3 * gl->num_points * sizeof(float), (GLfloat *)gl->points);
	makeShaderProgram(gl);
	gl_set_attrib_ptr(gl, "pos", 3,0, 0);

	gl_calc_transforms(gl);
	gl_render(gl);

	terminate_gl(gl);
}

void						gl_render(t_gl *gl)
{
	float 					time;
	float					delta;
	float 					old_time;

	old_time = 0;
	while (!glfwWindowShouldClose(gl->window))
	{
		processInput(gl->window);

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//Calculate transformation
		time = (float)glfwGetTime();
		delta = (time - old_time);
		glm_mat4_identity(gl->matrix->model_mat);
		glm_rotate(gl->matrix->model_mat, (0.25f * delta * glm_rad(180.0f)), gl->matrix->up);
		glUniformMatrix4fv(gl->matrix->model, 1, GL_FALSE, (float *)gl->matrix->model_mat);
		old_time = time;
		glm_rotate(gl->matrix->view_mat, (0.25f * delta * glm_rad(180.0f)), gl->matrix->up);
		glUniformMatrix4fv(gl->matrix->view, 1, GL_FALSE, (float *)gl->matrix->view_mat);

		//Render frames
		glDrawArrays(GL_LINES, 0, gl->num_points);

		glfwSwapBuffers(gl->window);
		glfwPollEvents();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
}
