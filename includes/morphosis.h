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


//---------------------------------------------------------------------------------------------------------------------- init.c
t_data						*init_data(void);
t_gl						*init_gl_struct(void);
t_julia 					*init_julia(void);
t_fract						*init_fract(void);
void						init_grid(t_data *data);
void						init_vertex(t_data *data);

//---------------------------------------------------------------------------------------------------------------------- errors.c
void 						error(int errno, t_data *data);

//---------------------------------------------------------------------------------------------------------------------- utils.c
float3						*arr_float_cat(float3 *f_from, float3 *f_to, uint2 *len);

//---------------------------------------------------------------------------------------------------------------------- cleanup.c
void 						clean_up(t_data *data);
void						clean_gl(t_gl *gl);
void 						clean_fract(t_fract *fract);

//---------------------------------------------------------------------------------------------------------------------- point_cloud.c
void 						calculate_point_cloud(t_data *data);
void						create_grid(t_data *data);
void 						subdiv_grid(float start, float stop, float step, float *axis);
void						define_voxel(t_fract *fract, float s);

//---------------------------------------------------------------------------------------------------------------------- build_fractal.c
void						build_fractal(t_data *data);

//---------------------------------------------------------------------------------------------------------------------- sample_julia.c
float 						sample_4D_Julia(t_julia *julia, float3 pos);

#endif
