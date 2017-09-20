
#include "myselect.h"

/*pre: none
*post: disables underline
*/

void term_underend()
{
	tputs(gl_env.under_end, 1, my_termprint);
}
