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

static float3 				*alloc_float_arr(float3 *mem, uint size)
{
	if (!size)
		return NULL;
	if (!mem)
	{
		if (!(mem = (float3 *)malloc(sizeof(float3) * size)))
			return NULL;
	}
	else
	{
		if (!(mem = realloc(mem, sizeof(float3) * size)))
			return NULL;
	}
	return mem;
}

/*
 * Appends array FROM to the end of array TO
 * Frees FROM & TO, returns new array
 *
 * len.y = FROM counter
 * len.x = TO counter
 */
float3						*arr_float_cat(float3 *f_from, float3 *f_to, uint2 *len)
{
	uint					from_c;
	uint 					to_c;
	uint 					res_c;

	res_c = len->x + len->y;
	from_c = 0;
	to_c = len->x;
	if (!(f_to = alloc_float_arr(f_to, (uint)(len->x + len->y))))
		return NULL;
	while (to_c < res_c)
		f_to[to_c++] = f_from[from_c++];
	len->x = res_c;
	len->y = 0;
	free(f_from);
	f_from = NULL;
	return f_to;
}
