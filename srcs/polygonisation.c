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

static float				interpolate(float p0, float p1, float v0, float v1)
{
	float					mu;
	float					p;

	if (v0 == 1)
		return p0;
	if (v1 == 1)
		return p1;
	if ((v1 - v0) == 0)
		return v0;
	mu = (1 - v0) / (v1 - v0);
	p = p0 + mu * (p1 - p0);
	return p;
}

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

//TODO create a way to address indexies of a cube in space (pos.y - pos.x) = 8 vert cube
//TODO (pos,y - 8)?
//TODO or mb cpy 8 consequtive verts and work with them (slower)

//TODO OH, JUST ADRESS IT BY (POS.X + i)
static float 				*get_vertices(uint cubeindex, float3 *v_pos, float *v_val, uint pos)
{
	float					*vertlist;

	if (!(vertlist = (float *)malloc(12 * sizeof(float))))
		return NULL;
}

/*
 * Process verticies from index pos.x to pos.y
 *
 * Returns NULL if no polygon is created (not an error!)
 */
float3 						*polygonise(float3 *v_pos, float *v_val, uint2 *pos, t_data *data)
{
	float3					*tris;
	float3 					*tris_tmp;
	float					*vertlist;
	uint 					cubeindex;

	tris = NULL;
	tris_tmp = NULL;
	vertlist = NULL;
	cubeindex = get_cube_index(v_val);
	if (edgetable[cubeindex] == 0)
		return NULL;
	if (!(vertlist = get_vertices(cubeindex, v_pos, v_val, pos->x)))
		error(MALLOC_FAIL_ERR, data);



	free(vertlist);
	return tris;
}
