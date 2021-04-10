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

static float3 				**alloc_float3_arr(float3 **mem, uint size)
{
	if (!size)
		return NULL;
	if (!mem)
	{
		if (!(mem = (float3 **)malloc(sizeof(float3 *) * size)))
			return NULL;
		for (int i = 0; i < 3; i++)
		{
			if (!(mem[i] = (float3 *)malloc(sizeof(float3))))
				return NULL;
		}
	}
	else
	{
		if (!(mem = (float3 **)realloc(mem, sizeof(float3 **) * size)))
			return NULL;
		for (int i = 0; i < 3; i++)
		{
			if (!(mem[i] = (float3 *)malloc(sizeof(float3))))
				return NULL;
		}
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

//TODO rewrite so its float3 ** ([][12])

//TODO check how it frees stuff
float3						**arr_float3_cat(float3 **f_from, float3 **f_to, uint2 *len)
{
	uint					from_c;
	uint 					to_c;
	uint 					res_c;

	res_c = len->x + len->y;
	from_c = 0;
	to_c = len->x;
	if (!(f_to = alloc_float3_arr(f_to, (uint)(len->x + len->y))))
		return NULL;

	while (to_c < res_c)
	{
		f_to[to_c][0] = f_from[from_c][0];
		f_to[to_c][1] = f_from[from_c][1];
		f_to[to_c][2] = f_from[from_c][2];
		to_c++;
		from_c++;
	}

	len->x = res_c;

	for (uint i = 0; i < len->y; i++)
		free(f_from[i]);
	free(f_from);

	len->y = 0;
	f_from = NULL;
	return f_to;
}
