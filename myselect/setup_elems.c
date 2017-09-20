
#include "myselect.h"

/*pre: takes in an int argc and a char **argv, argc is > 0
*post: sets up the elements in the global struct from the command-line arguments
*/

void setup_elems(int argc, char **argv)
{
	int i;

	gl_env.elements = (t_elem*)malloc(argc*sizeof(t_elem));
	gl_env.nbelems = argc;
	for(i = 0; i < argc; i++)
	{
		gl_env.elements[i].elem = argv[i];
		gl_env.elements[i].size = my_strlen(argv[i]);
		gl_env.elements[i].x = 0;
		gl_env.elements[i].y = 0;
		gl_env.elements[i].mode = 0;
	}
}
