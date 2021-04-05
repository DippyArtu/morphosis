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

//TODO grid and coord calculations —> get bounding cube

void 						calculate_julia_cloud(t_data *data)
{
	t_fract 				*fract;

	fract = data->fract;
	fract->grid_size = fract->grid_length / fract->step_size;
	init_grid(data);
}

