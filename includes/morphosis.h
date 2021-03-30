/* *********************************** */
/*                                     */
/*      Morphosis project              */
/*                                     */
/*      Created by Artur Makhnach      */
/*      github.com/DippyArtu           */
/*      artum.me                       */
/*                                     */
/* *********************************** */

#ifndef _MORPHOSIS_H
# define _MORPHOSIS_H

# include "stdio.h"
# include "stdlib.h"
# include "ctype.h"

# include <libft.h>
# include <gl_includes.h>
# include <errors.h>

//---------------------------------------------------------------------------------------------------------------------- init.c
t_gl						*init_gl_struct(void);

//---------------------------------------------------------------------------------------------------------------------- errors.c
void 						error(int errno, t_gl *gl);

//---------------------------------------------------------------------------------------------------------------------- cleanup.c
void 						clean_up(t_gl *gl);

#endif
