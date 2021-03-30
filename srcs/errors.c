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

void 						error(int errno, t_gl *gl)
{
	if (errno == MALLOC_FAIL_ERR)
		printf(MALLOC_FAIL);
	else if (errno == OPEN_FILE_ERR)
		printf(OPEN_FILE);
	clean_up(gl);
	exit(1);
}
