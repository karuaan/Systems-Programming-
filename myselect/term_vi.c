
#include "myselect.h"

/*pre: none
*post: disables cursor display
*/

void term_vi()
{
	tputs(gl_env.cursoroff, 1, my_termprint);
}
