/* *********************************** */
/*                                     */
/*      Morphosis project              */
/*                                     */
/*      Created by Artur Makhnach      */
/*      github.com/DippyArtu           */
/*      artum.me                       */
/*                                     */
/* *********************************** */

#ifndef _MORPHOSIS_ERRORS_H
# define _MORPHOSIS_ERRORS_H

# define MALLOC_FAIL_ERR 1
# define OPEN_FILE_ERR 2
# define ARGS_ERR 3
# define GRID_ERR 4

# define MALLOC_FAIL "ERROR: Could not allocate memory\n"
# define OPEN_FILE "ERROR: Could not open the file\n"
# define GRID "ERROR: Invalid step size\n min: 0.00001 | max: 1\n"

# define ARGS "ERROR: Invalid program arguments\n"
# define USAGE "USAGE: ./morphosis *step_size* *q.x* *q.y* *q.z* *q.w*\n OR: ./morphosis def \nto use default values\n"

#endif
