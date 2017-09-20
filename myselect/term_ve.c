
#include "myselect.h"

/*pre: none
*post: enables cursor display
*/

void term_ve()
{
	tputs(gl_env.cursoron, 1, my_termprint);
}
