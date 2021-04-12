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

void 						error(int errno, t_data *data)
{
	if (errno == MALLOC_FAIL_ERR)
		printf(MALLOC_FAIL);
	else if (errno == OPEN_FILE_ERR)
		printf(OPEN_FILE);
	else if (errno == ARGS_ERR)
		printf("%s%s", ARGS, USAGE);
	else if (errno == GRID_ERR)
		printf(GRID);
	clean_up(data);
	exit(1);
}
