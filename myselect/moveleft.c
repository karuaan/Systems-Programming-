
#include "myselect.h"

/*pre: none
*post: moves the cursor one column to the left
*	moves the cursor to the first element if there is no column to the left
*/

void moveleft()
{
	refreshout(gl_env.pos);
	if((gl_env.pos -= gl_env.win.ws_row) < 0)
		gl_env.pos = 0;
	refreshin();
}
