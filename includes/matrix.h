/* *********************************** */
/*                                     */
/*      Morphosis project              */
/*                                     */
/*      Created by Artur Makhnach      */
/*      github.com/DippyArtu           */
/*      artum.me                       */
/*                                     */
/* *********************************** */

#ifndef _MORPHOSIS_MATRIX_H
# define _MORPHOSIS_MATRIX_H

# include <openssl/sha.h>

# define STR_BUFFER 150

// 1 (find mean matrix) or 2 (work with raw matrix)
# define MODE 1
// 1 (whole part always 0) or 2 (whole part can be 1)
# define WHOLE 1
// 1 (z & w coordinates calculated) or 2 (z & w coordinates set to 0)
# define ZW 1

typedef struct 					s_mat_conv_data
{
	float4 						q;
	float 						step_size;
	int							iter;
}								t_mat_conv_data;

//----------------------------------------------------------------------------------------------------------------------matrix_read.c
char							*read_matrix(FILE *stream);

//----------------------------------------------------------------------------------------------------------------------matrix_converter.c
void							process_matrix(char *file, t_mat_conv_data *data);

//----------------------------------------------------------------------------------------------------------------------matrix_hash.c
void 							matrix_hash(int **matrix, t_mat_conv_data *data);
void 							matrix_hash2(char *matrix, t_mat_conv_data *data);

//----------------------------------------------------------------------------------------------------------------------matrix_generate_coordinates.c
void 							get_coords_from_hash(unsigned char *hash, t_mat_conv_data *data);

#endif
