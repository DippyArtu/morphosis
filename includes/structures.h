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

#endif
