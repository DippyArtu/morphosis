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

//TODO y coordinate is off
void						build_fractal(t_data *data)
{
	t_fract 				*f;
	float3 					**new_tris;
	size_t 					i;																							//len.x = len original triangles list (data->triangles), len.y = len second
	uint2					pos;																						//pos in vertex array --- step_size = 8 veritces (a cube) | pos.x = POS_OLD | pos.y = POS_NEW (new end index)

	i = 0;
	f = data->fract;
	data->len.x = 0;
	data->len.y = 0;
	pos.x = 0;
	pos.y = 0;
	new_tris = NULL;
	for (size_t z = 0; z < f->grid_size; z++)
	{
		printf("%zu/%.0f\n", (z + 1), f->grid_size);
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
				pos.y += 8;
				new_tris = polygonise(data->vertexpos, data->vertexval, &pos, data);
				if (new_tris)
				{
					if (!(data->triangles = arr_float3_cat(new_tris, data->triangles, &data->len)))
						error(MALLOC_FAIL_ERR, data);
				}
				pos.x = pos.y;
			}
		}
	}
	printf("%.3f    %.3f   %.3f\n", data->triangles[0][0].x, data->triangles[0][0].y, data->triangles[0][0].z);
	printf("%.3f    %.3f   %.3f\n", data->triangles[0][1].x, data->triangles[0][1].y, data->triangles[0][1].z);
	printf("%.3f    %.3f   %.3f\n", data->triangles[0][2].x, data->triangles[0][2].y, data->triangles[0][2].z);
}
