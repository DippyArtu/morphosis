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

//TODO grid and coord calculations —> get coordinates
//NOTE: loop to <= fract->grid_size when going through grid

void 						calculate_julia_cloud(t_data *data)
{
	t_fract 				*fract;

	fract = data->fract;
	fract->grid_size = fract->grid_length / fract->step_size;
	init_grid(data);
	process_grid(data);

//	int i;
//	printf("x: \n");
//	i = 0;
//	while (i <= (int)fract->grid_size)
//	{
//		printf("num: %.3f\n", fract->grid.x[i]);
//		i++;
//	}
//	printf("\ny: \n");
//	i = 0;
//	while (i <= (int)fract->grid_size)
//	{
//		printf("num: %.3f\n", fract->grid.y[i]);
//		i++;
//	}
//	printf("\nz: \n");
//	i = 0;
//	while (i <= (int)fract->grid_size)
//	{
//		printf("num: %.3f\n", fract->grid.z[i]);
//		i++;
//	}
}

void						process_grid(t_data *data)
{
	subdiv_grid(data->fract->p0.x, data->fract->p1.x, data->fract->step_size, data->fract->grid.x);
	subdiv_grid(data->fract->p0.y, data->fract->p1.y, data->fract->step_size, data->fract->grid.y);
	subdiv_grid(data->fract->p0.z, data->fract->p1.z, data->fract->step_size, data->fract->grid.z);
}

void 						subdiv_grid(float start, float stop, float step, float *axis)
{
	float 					val;
	int						i;

	val = start;
	i = 0;
	while (val <= stop)
	{
		axis[i++] = val;
		val += step;
	}
}
