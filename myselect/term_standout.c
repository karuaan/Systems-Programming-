
#include "myselect.h"

/*pre: none
*post: enables highlight
*/

void term_standout()
{
	tputs(gl_env.standout, 1, my_termprint);
}
