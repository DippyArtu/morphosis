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

typedef struct 					s_mat_conv_data
{
	float4 						q;
	float 						step_size;
}								t_mat_conv_data;

//----------------------------------------------------------------------------------------------------------------------matrix_converter.c
void							process_matrix(char *file, t_mat_conv_data *data);

//----------------------------------------------------------------------------------------------------------------------matrix_utils.c


#endif
