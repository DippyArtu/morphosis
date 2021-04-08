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

static float3 				*alloc_float_arr(uint size)
{
	float3 					*ret;

	if (!(ret = (float3 *)malloc(sizeof(float3) * size)))
		return NULL;
	return ret;
}

float3						*arr_float_cat(float3 *f_from, float3 *f_to, uint2 *len)
{
	float3 					*res;
	uint					from_c;
	uint 					to_c;
	uint 					res_c;

	res_c = 0;
	if (!(res = alloc_float_arr((uint)(len->x + len->y))))
		return NULL;
	from_c = 0;
	to_c = 0;
	while (to_c <= len->y)
		res[res_c++] = f_to[to_c++];
	while (from_c <= len->x)
		res[res_c++] = f_from[from_c++];
	len->x = res_c;
	len->y = 0;
	free(f_from);
	free(f_to);
	return res;
}
