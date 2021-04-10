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
#include "look-up.h"

static uint 				get_cube_index(float *v_val)
{
	uint					cubeindex;

	cubeindex = 0;
	if (v_val[0])
		cubeindex |= 1;
	if (v_val[1])
		cubeindex |= 2;
	if (v_val[2])
		cubeindex |= 4;
	if (v_val[3])
		cubeindex |= 8;
	if (v_val[4])
		cubeindex |= 16;
	if (v_val[5])
		cubeindex |= 32;
	if (v_val[6])
		cubeindex |= 64;
	if (v_val[7])
		cubeindex |= 128;
	return cubeindex;
}

static float3				interpolate(float3 p0, float3 p1, float v0, float v1)
{
	float					mu;
	float3					p;

	if (v0 == 1)
		return p0;
	if (v1 == 1)
		return p1;
	if ((v1 - v0) == 0)
		return v0; //?
	mu = (1 - v0) / (v1 - v0);
	p = p0 + mu * (p1 - p0);
	return p;
}

//TODO create a way to address indexies of a cube in space (pos.y - pos.x) = 8 vert cube
//TODO (pos,y - 8)?
//TODO or mb cpy 8 consequtive verts and work with them (slower)

//TODO OH, JUST ADRESS IT BY (POS.X + i)
//TODO wtf are verts....
static float3				*get_vertices(uint cubeindex, float3 *v_pos, float *v_val, uint pos)
{
	float3					*vertlist;

	if (!(vertlist = (float3 *)malloc(12 * sizeof(float3))))
		return NULL;

	if (edgetable[cubeindex] & 1)
		vertlist[0] = interpolate(v_pos[pos + 0], v_pos[pos + 1], v_val[pos + 0], v_val[pos + 1]);
	if (edgetable[cubeindex] & 2)
		vertlist[1] = interpolate(v_pos[pos + 1], v_pos[pos + 2], v_val[pos + 1], v_val[pos + 2]);
	if (edgetable[cubeindex] & 4)
		vertlist[2] = interpolate(v_pos[pos + 2], v_pos[pos + 3], v_val[pos + 2], v_val[pos + 3]);
	if (edgetable[cubeindex] & 8)
		vertlist[3] = interpolate(v_pos[pos + 3], v_pos[pos + 0], v_val[pos + 3], v_val[pos + 0]);
	if (edgetable[cubeindex] & 16)
		vertlist[4] = interpolate(v_pos[pos + 4], v_pos[pos + 5], v_val[pos + 4], v_val[pos + 5]);
	if (edgetable[cubeindex] & 32)
		vertlist[5] = interpolate(v_pos[pos + 5], v_pos[pos + 6], v_val[pos + 5], v_val[pos + 6]);
	if (edgetable[cubeindex] & 64)
		vertlist[6] = interpolate(v_pos[pos + 6], v_pos[pos + 7], v_val[pos + 6], v_val[pos + 7]);
	if (edgetable[cubeindex] & 128)
		vertlist[7] = interpolate(v_pos[pos + 7], v_pos[pos + 4], v_val[pos + 7], v_val[pos + 4]);
	if (edgetable[cubeindex] & 256)
		vertlist[8] = interpolate(v_pos[pos + 0], v_pos[pos + 4], v_val[pos + 0], v_val[pos + 4]);
	if (edgetable[cubeindex] & 512)
		vertlist[9] = interpolate(v_pos[pos + 1], v_pos[pos + 5], v_val[pos + 1], v_val[pos + 5]);
	if (edgetable[cubeindex] & 1024)
		vertlist[10] = interpolate(v_pos[pos + 2], v_pos[pos + 6], v_val[pos + 2], v_val[pos + 6]);
	if (edgetable[cubeindex] & 2048)
		vertlist[11] = interpolate(v_pos[pos + 3], v_pos[pos + 7], v_val[pos + 3], v_val[pos + 7]);
	return vertlist;
}

/*
 * Process verticies from index pos.x to pos.y
 *
 * Returns NULL if no polygon is created (not an error!)
 */
float3 						**polygonise(float3 *v_pos, float *v_val, uint2 *pos, t_data *data)
{
	float3					**tris;
	float3 					**tris_tmp;
	float3					*vertlist;
	uint 					cubeindex;
	uint 					i;
	uint2 					len;

	tris = NULL;
	tris_tmp = NULL;
	vertlist = NULL;
	i = 0;
	cubeindex = get_cube_index(v_val);
	if (edgetable[cubeindex] == 0)
		return NULL;
	if (!(vertlist = get_vertices(cubeindex, v_pos, v_val, pos->x)))
		error(MALLOC_FAIL_ERR, data);

	len.x = 0;
	len.y = 1;
	while ((int)tritable[cubeindex][i] != -1)
	{

		i += 3;
	}

	free(vertlist);
	return tris;
}
