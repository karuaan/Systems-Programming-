
#include "myselect.h"

/*pre: none
*post: enables underline
*/

void term_underline()
{
	tputs(gl_env.underline, 1, my_termprint);
}
