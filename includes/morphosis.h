/* *********************************** */
/*                                     */
/*      Morphosis project              */
/*                                     */
/*      Created by Artur Makhnach      */
/*      github.com/DippyArtu           */
/*      artum.me                       */
/*                                     */
/* *********************************** */

#ifndef _MORPHOSIS_H
# define _MORPHOSIS_H

# include "stdio.h"
# include "stdlib.h"
# include "ctype.h"

# include <libft.h>
# include <gl_includes.h>
# include <errors.h>
# include <structures.h>

typedef struct 				s_data
{
	t_gl					*gl;
	t_fract 				*fract;
	float3 					*vertexpos;
	float					*vertexval;
}							t_data;


//---------------------------------------------------------------------------------------------------------------------- init.c
t_data						*init_data(void);
t_gl						*init_gl_struct(void);
t_julia 					*init_julia(void);
t_fract						*init_fract(void);
void						init_grid(t_data *data);
void						init_vertex(t_data *data);

//---------------------------------------------------------------------------------------------------------------------- errors.c
void 						error(int errno, t_data *data);

//---------------------------------------------------------------------------------------------------------------------- cleanup.c
void 						clean_up(t_data *data);

//---------------------------------------------------------------------------------------------------------------------- point_cloud.c
void 						calculate_point_cloud(t_data *data);
void						create_grid(t_data *data);
void 						subdiv_grid(float start, float stop, float step, float *axis);
void						define_voxel(t_fract *fract, float s);

//---------------------------------------------------------------------------------------------------------------------- calculate_julia.c
void						calculate_julia(t_data *data);

#endif
