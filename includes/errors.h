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
# define NO_ARG_ERR 5

# define MALLOC_FAIL "\nERROR: Could not allocate memory\n"
# define OPEN_FILE "\nERROR: Could not open the file\n"
# define GRID "\nERROR: Invalid step size\n min: 0.00001 | max: 1\n"

# define ARGS "\nERROR: Invalid program arguments\n"
# define USAGE "\nUSAGE: ./morphosis *step_size* *q.x* *q.y* *q.z* *q.w*\nOR: ./morphosis def \nto use default values\n"
# define NO_ARG "\nThis program calculates, displays and saves a 4d Julia set as an OBJ file in the current directory\nWhen fractal is displayed, press ESC to exit or S to save and export the mesh\n"

#endif
