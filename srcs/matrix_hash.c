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

static void					read_matrix(int **matrix)
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			printf("%i ", matrix[i][j]);
		}
		printf("\n");
	}
}

const uint32_t  MOD_ADLER = 65521;

uint32_t 						adler32(unsigned char *data, size_t len)
{
	uint32_t 					a;
	uint32_t 					b;
	size_t 						index;

	a = 1;
	b = 0;
	for (index = 0; index < len; ++index)
	{
		a = (a + data[index]) % MOD_ADLER;
		b = (b + a) % MOD_ADLER;
	}
	return (b << 16) | a;
}

//6*6 matrix
void 							matrix_hash(int **matrix, t_mat_conv_data *data)
{
	//read_matrix(matrix);
	uint32_t 					checksum;

	size_t 						size = 6;
//	int 						mat[] =
//		{
//		34, 41, 40, 36, 48, 41,
//		16, 31, 45, 51, 47, 33,
//		15, 39, 28, 35, 45, 48,
//		36, 32, 57, 46, 42, 47,
//		60, 46, 62, 59, 51, 26,
//		55, 57, 45, 49, 25, 21
//		};

	//1835014
	int 						mat[] =
		{
		3, 3, 1,
		3, 3, 8
		};

//	for (size_t i = 0; i < size; i++)
//		printf("%i ", mat[i]);
//	printf("\n");
	checksum = 0;
	checksum = adler32((unsigned char *)mat, size);
	printf("%u\n", checksum);
}
