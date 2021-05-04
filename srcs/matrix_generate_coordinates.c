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

//Brian Kernighan’s Algorithm
static int						count_set_bits(int byte)
{
	int 						c;

	c = 0;
	while (byte)
	{
		byte &= (byte - 1);
		c++;
	}
	return c;
}

/*
 * This function receives 8 bytes
 * 1st byte used to generate a sign
 * 2nd for the whole part (it can be either 0 or 1, because numbers have to be in -2 < x < 2 range)
 * remaining 6 for mantissa (decimal places) — can output numbers 0-8 to keep away from range limits
 */
static float 					generate_number(uint *bytes)
{
	float 						res;
	int 						negative;
	float 						mantissa;

	res = 0;
	negative = 0;
	mantissa = 0;
	if (count_set_bits(bytes[0]) >= 4)
		negative = 1;
	if (count_set_bits(bytes[1]) >= 4)
		res = 1;
	for (int i = 2; i < 8; i++)
	{
		mantissa += (float)count_set_bits(bytes[i]);
		mantissa *= 10;
	}
	mantissa /= 10000000;
	res += mantissa;

	return (negative ? res : res * -1);
}

//coord_bytes stores bytes used to generate x, y, z, w coordinates — 8 bytes per coordinate
void 					get_coords_from_hash(unsigned char *hash, t_mat_conv_data *data)
{
	uint 						coord_bytes[4][8];
	int							c;

	c = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 8; j++)
			coord_bytes[i][j] = (uint)hash[c++];
	}
	data->q.x = generate_number(coord_bytes[0]);
	data->q.y = generate_number(coord_bytes[1]);
	data->q.z = generate_number(coord_bytes[2]);
	data->q.w = generate_number(coord_bytes[3]);
}
