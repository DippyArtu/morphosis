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

void 						clean_fract(t_fract *fract)
{
	if (!fract)
		return;
	if (fract->julia)
		free(fract->julia);
	if (fract->grid.x)
		free(fract->grid.x);
	if (fract->grid.y)
		free(fract->grid.y);
	if (fract->grid.z)
		free(fract->grid.z);
	free(fract);
}

void 						clean_up(t_data *data)
{
	if (data)
	{
		if (data->gl)
		{
			if (data->gl->points)
				free(data->gl->points);
			free(data->gl);
		}
		if (data->fract)
			clean_fract(data->fract);
		if (data->vertexpos)
			free(data->vertexpos);
		if (data->vertexval)
			free(data->vertexval);
		free(data);
	}
}
