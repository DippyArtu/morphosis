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

void 						run_graphics(t_gl *gl)
{
	init_gl(gl);
	createVAO(gl);
	createVBO(gl, gl->num_points * sizeof(float), (GLfloat *)gl->points);
	makeShaderProgram(gl);
	gl_set_attrib_ptr(gl, "pos", 2,0, 0);

	gl_render(gl);

	terminate_gl(gl);
}

void						gl_render(t_gl *gl)
{
	while (!glfwWindowShouldClose(gl->window))
	{
		processInput(gl->window);

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//Render frames
		glDrawArrays(GL_TRIANGLES, 0, gl->num_points);

		glfwSwapBuffers(gl->window);
		glfwPollEvents();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
}
