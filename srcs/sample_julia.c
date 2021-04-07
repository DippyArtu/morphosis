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

/*
 * Iterates a given point through the Julia Fractal equation on quaternions
 *
 * 			Z = Z*Z + c
 *
 * Returns 0 if point didn't converge => not in the set
 * Returns 1 if point converged => in the set
 */
float 						sample_4D_Julia(t_julia *julia, float3 pos)
{
	cl_quat 				z;
	uint 					iter;

	iter = 0;
	z.x = pos.x;
	z.y = pos.y;
	z.z = pos.z;
	z.w = julia->w;

	while (iter < julia->max_iter)
	{
		z = cl_quat_mult(z, z);
		z = cl_quat_sum(z, julia->c);
		if (cl_quat_mod(z) > julia->threshold)
			return 0.0f;
		iter++;
	}
	return 1.0f;
}
