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

//TODO Start with defining point sampled (position) and iterate it through Q Julia
//TODO wrong counts in loop
void						calculate_julia(t_data *data)
{
	t_fract 				*f;
	size_t 					i;

	i = 0;
	f = data->fract;
	for (size_t x = 0; x <= f->grid_size; x++)
	{
		for (size_t y = 0; y <= f->grid_size; y++)
		{
			for (size_t z = 0; z <= f->grid_size; z++)
			{
				for (int c = 0; c < 8; c++)
				{
					data->vertexpos[i].x = f->grid.x[x] + f->voxel[c].dx;
					data->vertexpos[i].y = f->grid.y[y] + f->voxel[c].dy;
					data->vertexpos[i].z = f->grid.z[z] + f->voxel[c].dz;
					printf("%zu:  %.3f  %.3f  %.3f\n", i, data->vertexpos[i].x, data->vertexpos[i].y, data->vertexpos[i].z);
					i++;
					if (i == 16)
						exit(0);
				}
			}
		}
	}
}
