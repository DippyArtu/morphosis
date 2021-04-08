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

//TODO poligonise Julia with Marching Cubes
void						build_fractal(t_data *data)
{
	t_fract 				*f;
	float 					*new_tris;
	size_t 					i;
	uint2					len; //len.x = len first list, len.y = len second

	i = 0;
	f = data->fract;
	len.x = 0;
	len.y = 0;
	new_tris = NULL;
	for (size_t z = 0; z < f->grid_size; z++)
	{
		for (size_t y = 0; y < f->grid_size; y++)
		{
			for (size_t x = 0; x < f->grid_size; x++)
			{
				for (int c = 0; c < 8; c++)
				{
					data->vertexpos[i].x = f->grid.x[x] + f->voxel[c].dx;
					data->vertexpos[i].y = f->grid.y[y] + f->voxel[c].dy;
					data->vertexpos[i].z = f->grid.z[z] + f->voxel[c].dz;
					data->vertexval[i] = sample_4D_Julia(f->julia, data->vertexpos[i]);
					if (data->vertexval[i] == 1)
						data->gl->num_points++;
					i++;
				}
				/*
				 * polygonise here
				 *
				 * tris and function polygonise return are lists —> cat them
				 * have triangles_temp[], calculate to that & cat with triangles[]
				 * num triangles == pow(grid_size, 3);
				 * write tpm_tris = init_triangles() and cat with data.triangles
				 * use arr_float_cat (if returns NULL — error)
				 *
				 * use like so:
				 *
				 * new_tris = polygonise(vertpos, vertval);
				 * if (!(data->triangles = arr_float_cat(new_tris, data->triangles, &len)))
				 * 			error(MALLOC_FAIL_ERR, data);
				 *
				*/
			}
		}
	}
}
