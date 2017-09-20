
#include "myselect.h"

/*pre: none
*post: clears the terminal
*/

void term_clear()
{
	tputs(gl_env.clear, 1, my_termprint);
}
