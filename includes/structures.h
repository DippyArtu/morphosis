/* *********************************** */
/*                                     */
/*      Morphosis project              */
/*                                     */
/*      Created by Artur Makhnach      */
/*      github.com/DippyArtu           */
/*      artum.me                       */
/*                                     */
/* *********************************** */

#ifndef _MORPHOSIS_STRUCTURES_H
# define _MORPHOSIS_STRUCTURES_H

# include <lib_complex.h>

//---------------------------------------------------------------------------------------------------------------------- OPENGL STRUCTS
typedef struct 				s_matrix
{
	mat4 					model_mat;
	mat4 					projection_mat;
	mat4 					view_mat;

	vec3 					eye;
	vec3 					center;
	vec3 					up;

	GLuint 					model;
	GLuint 					view;
}							t_matrix;

typedef struct 				s_gl
{
	GLFWwindow 				*window;

	int						export;

	GLuint 					vertexShader;
	GLuint 					fragmentShader;
	GLuint					shaderProgram;

	GLuint 					vbo;
	GLuint 					vao;

	float					*tris;
	uint 					num_pts;
	uint					num_tris;
	t_matrix 				*matrix;
}							t_gl;


//---------------------------------------------------------------------------------------------------------------------- MORPHOSIS STRUCTS
typedef struct 				s_julia
{
	uint					max_iter;
	float 					threshold;
	float 					w;
	cl_quat 				c;
}							t_julia;

typedef struct 				s_grid
{
	float 					*x;
	float 					*y;
	float 					*z;
}							t_grid;

typedef struct 				s_voxel
{
	float 					dx;
	float 					dy;
	float 					dz;
}							t_voxel;

typedef struct				s_fract
{
	float3 					p0;
	float3 					p1;
	float 					step_size;
	float 					grid_length;
	float 					grid_size;

	t_julia 				*julia;
	t_grid 					grid;
	t_voxel 				voxel[8];
}							t_fract;

typedef struct 				s_data
{
	t_gl					*gl;
	t_fract 				*fract;
	float3 					*vertexpos;
	float					*vertexval;
	float3					**triangles;

	/*
	 * len.x = totall length of triangles list
	 * len.y = length of list to be appended
	 */
	uint2 					len;
}							t_data;

#endif
