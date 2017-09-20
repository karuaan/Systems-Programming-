
#include "myselect.h"

/*pre: none
*post: disables highlight
*/

void term_standend()
{
	tputs(gl_env.stand_end, 1, my_termprint);
}
