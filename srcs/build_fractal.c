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
//TODO triangles array cat algo done, now calculate triangles & store them
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
				/*
				 * polygonise here
				 *
				 * tris and function polygonise return are lists —> cat them
				 * have triangles_temp[], calculate to that & cat with triangles[]
				 * write tpm_tris = init_triangles() and cat with data-.triangles
				 * use arr_float3_cat (if returns NULL — error)
				 *
				 * use like so:
				 *
				 * new_tris = polygonise(vertpos, vertval);
				 * if (!(data->triangles = arr_float_cat(new_tris, data->triangles, &len)))
				 * 			error(MALLOC_FAIL_ERR, data);
				 *
				*/
				new_tris = polygonise(data->vertexpos, data->vertexval, &pos, data);
				if (new_tris)
				{
					if (!(data->triangles = arr_float3_cat(new_tris, data->triangles, &data->len)))
						error(MALLOC_FAIL_ERR, data);
				}
				pos.x = pos.y;
				exit(0);

//----------------------------------------------------------------------------------------------------------------------TRIS CAT TEST
//				new_tris = (float3 **)malloc(2 * sizeof(float3 *));
//				for (int ii = 0; ii < 2; ii++)
//					new_tris[ii] = (float3 *)malloc(3 * sizeof(float3));
//
//				new_tris[0][0].x = 1.1f;
//				new_tris[0][0].y = 1.1f;
//				new_tris[0][0].z = 1.1f;
//				new_tris[0][1].x = 1.2f;
//				new_tris[0][1].y = 1.2f;
//				new_tris[0][1].z = 1.2f;
//				new_tris[0][2].x = 1.3f;
//				new_tris[0][2].y = 1.3f;
//				new_tris[0][2].z = 1.3f;
//
//				new_tris[1][0].x = 2.1f;
//				new_tris[1][0].y = 2.1f;
//				new_tris[1][0].z = 2.1f;
//				new_tris[1][1].x = 2.2f;
//				new_tris[1][1].y = 2.2f;
//				new_tris[1][1].z = 2.2f;
//				new_tris[1][2].x = 2.3f;
//				new_tris[1][2].y = 2.3f;
//				new_tris[1][2].z = 2.3f;
//
//
//				data->len.y = 2;
//				data->triangles = arr_float3_cat(new_tris, data->triangles, &data->len);
//				for (uint c = 0; c < data->len.x; c++)
//				{
//					printf("TRIG %u: (%.1f,  %.1f,  %.1f)", c, data->triangles[c][0].x, data->triangles[c][0].y, data->triangles[c][0].z);
//					printf(", (%.1f,  %.1f,  %.1f)", data->triangles[c][1].x, data->triangles[c][1].y, data->triangles[c][1].z);
//					printf(", (%.1f,  %.1f,  %.1f)\n", data->triangles[c][2].x, data->triangles[c][2].y, data->triangles[c][2].z);
//				}
//				printf("len x: %i    ley y:  %i\n", data->len.x, data->len.y);
//				printf("\n");
//
//				new_tris = (float3 **)malloc(2 * sizeof(float3 *));
//				for (int ii = 0; ii < 2; ii++)
//					new_tris[ii] = (float3 *)malloc(3 * sizeof(float3));
//
//				new_tris[0][0].x = 3.1f;
//				new_tris[0][0].y = 3.1f;
//				new_tris[0][0].z = 3.1f;
//				new_tris[0][1].x = 3.2f;
//				new_tris[0][1].y = 3.2f;
//				new_tris[0][1].z = 3.2f;
//				new_tris[0][2].x = 3.3f;
//				new_tris[0][2].y = 3.3f;
//				new_tris[0][2].z = 3.3f;
//
//				new_tris[1][0].x = 4.1f;
//				new_tris[1][0].y = 4.1f;
//				new_tris[1][0].z = 4.1f;
//				new_tris[1][1].x = 4.2f;
//				new_tris[1][1].y = 4.2f;
//				new_tris[1][1].z = 4.2f;
//				new_tris[1][2].x = 4.3f;
//				new_tris[1][2].y = 4.3f;
//				new_tris[1][2].z = 4.3f;
//
//
//				data->len.y = 2;
//				data->triangles = arr_float3_cat(new_tris, data->triangles, &data->len);
//				for (uint c = 0; c < data->len.x; c++)
//				{
//					printf("TRIG %ui: (%.1f,  %.1f,  %.1f)", c, data->triangles[c][0].x, data->triangles[c][0].y, data->triangles[c][0].z);
//					printf(", (%.1f,  %.1f,  %.1f)", data->triangles[c][1].x, data->triangles[c][1].y, data->triangles[c][1].z);
//					printf(", (%.1f,  %.1f,  %.1f)\n", data->triangles[c][2].x, data->triangles[c][2].y, data->triangles[c][2].z);
//				}
//				printf("\nlen x: %i    ley y:  %i\n", data->len.x, data->len.y);
//				printf("\n");
//----------------------------------------------------------------------------------------------------------------------TRIS CAT TEST
			}
		}
	}
}
