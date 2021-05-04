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

typedef struct 					s_mat_conv_data
{
	float4 						q;
	float 						step_size;
}								t_mat_conv_data;

//----------------------------------------------------------------------------------------------------------------------matrix_converter.c
void							process_matrix(char *file, t_mat_conv_data *data);

//----------------------------------------------------------------------------------------------------------------------matrix_hash.c
void 							matrix_hash(int **matrix, t_mat_conv_data *data);

//----------------------------------------------------------------------------------------------------------------------matrix_generate_coordinates.c
void 							get_coords_from_hash(unsigned char *hash, t_mat_conv_data *data);

#endif
