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

static void 					ft_itoa(int num, char *str)
{
	if (!str)
		return;
	sprintf(str, "%d", num);
}

static char						*matrix_to_string(int **matrix)
{
	char 						*res;
	char						tmp[4];

	if (!(res = (char *)malloc(STR_BUFFER * sizeof(char))))
		error(MALLOC_FAIL_ERR, NULL);
	bzero(res, STR_BUFFER);
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			bzero(tmp, 4);
			ft_itoa(matrix[i][j], tmp);
			res = strcat(res, tmp);
		}
	}
	return res;
}

// convert matrix to string
// get SHA-256 hash
// divide hash bytes into 4 groups of 8 bytes — each group per coordinate
void 							matrix_hash(int **matrix, t_mat_conv_data *data)
{
	char 						*mat_string;
	unsigned char 				*hash;

	mat_string = matrix_to_string(matrix);
	hash = SHA256((const unsigned char *)mat_string, strlen(mat_string), 0);
	free(mat_string);
	get_coords_from_hash(hash, data);
}
